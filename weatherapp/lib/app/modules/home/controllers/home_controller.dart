import 'dart:async';
import 'package:flutter/cupertino.dart';
import 'package:flutter/material.dart';
import 'package:flutter/services.dart';
import 'package:flutter_svg/flutter_svg.dart';
import 'package:get/get.dart';
import 'package:syncfusion_flutter_charts/charts.dart';
import 'package:epic_weather/app/settings/settings.dart';
import 'package:epic_weather/app/utils/connectivity.dart';
import 'package:epic_weather/app/utils/day_converter.dart';
import 'package:epic_weather/app/data/Api/weather_api.dart';
import 'package:epic_weather/app/data/database/database.dart';
import 'package:epic_weather/app/data/models/location_model.dart';
import 'package:epic_weather/app/data/models/temperature_model.dart';
import 'package:epic_weather/app/routes/app_pages.dart';
import 'package:epic_weather/app/theme/app_theme.dart';
import 'package:epic_weather/app/utils/local_notifications.dart';
import 'package:epic_weather/app/widgets/common_components.dart';
import 'package:epic_weather/app/widgets/homeview_components.dart';
import 'package:epic_weather/app/widgets/temperature_chart.dart';
import 'package:url_launcher/url_launcher.dart';
import 'package:workmanager/workmanager.dart';

class HomeController extends GetxController {
  //Static Variables
  final WeatherApi api = WeatherApi();

  //Global Variables
  late AppDatabase database;
  late HomeViewComponents components;
  late AppTheme theme;
  late ConnectionStatusSingleton connectionStatus;
  late StreamSubscription connectionChangeStream;
  late Settings appSettings;

  //State Variables
  late bool isDrawerOpen;
  late Size size;
  bool loadingState = false;
  ChartSeriesController? chartController;
  bool isSettingsOpen = false;

  //Data variables
  late Location data;
  String currentLocation = "";
  var locations;
  late List<TemperatureChartData> chartData = [];
  double highestTemperature = -273.0;
  double lowestTemperature = 1000.0;

  //ForegroundDown View
  late TemperatureChart chart;

  //PeriodChooser View
  late List<bool> periodChooserState;

  //Switcher View
  late bool switcherState;

  @override
  void onInit() async {
    database = AppDatabase.instance;
    appSettings = Settings.instance;

    connectionStatus = ConnectionStatusSingleton.getInstance();
    connectionStatus.initialize();

    isDrawerOpen = false;

    size = Get.size;
    setTheme();
    components = HomeViewComponents();
    loadingState = true;
    update();
    await appSettings.loadData();
    currentLocation = appSettings.currentLocationId;

    data = (await database.getLocation(currentLocation));
    if (!data.isDataAvailable || checkTime()) {
      if (await connectionStatus.checkConnection()) {
        (await api
            .getFullWeather(data.longitude, data.latitude)
            .then((value) async {
          data.isDataAvailable = true;
          data.setFullWeather(value);
          await database.updateLocation(data);
        }).onError((error, stackTrace) {
          data.isDataAvailable = false;
        }));
      } else {
        showSnackBar(
            title: "Connection", description: "No Internet Connection");

        Get.offAndToNamed(AppPages.LOCATION);
        onClose();
      }
    }
    locations = (await database.getAllLocations());
    periodChooserState = [true, false, false];
    switcherState = true;
    setData(data);
    setNotification();
    super.onInit();
  }

  bool checkTime() {
    DateTime currTime = DateTime.now();
    if (!((data.date.day == currTime.day) &&
        (data.date.month == currTime.month) &&
        (data.date.year == currTime.year))) {
      return true;
    } else {
      return false;
    }
  }

  void onRefresh() {
    onInit();
  }

  Future<bool> isOnline() async {
    return (await connectionStatus.checkConnection());
  }

  @override
  void onClose() {
    super.onClose();
  }

  void setTheme() {
    if (appSettings.isdefaultTheme) {
      theme = Get.mediaQuery.platformBrightness == Brightness.dark
          ? AppTheme.darkTheme()
          : AppTheme.lightTheme();
    } else {
      theme =
          appSettings.isDarkMode ? AppTheme.darkTheme() : AppTheme.lightTheme();
    }
    update();
  }

  void showSnackBar({required String title, required String description}) {
    Get.snackbar(title, description,
        snackPosition: SnackPosition.BOTTOM,
        colorText: theme.appColorTheme.greyButtonInsideColor,
        isDismissible: true,
        dismissDirection: SnackDismissDirection.HORIZONTAL,
        backgroundColor: theme.appColorTheme.colorBackground,
        borderRadius: 10,
        boxShadows: [theme.appColorTheme.shadowMedium],
        animationDuration: Duration(milliseconds: 200));
  }

  void setData(Location data) {
    chartData.clear();
    highestTemperature = -273.0;
    lowestTemperature = 1000.0;
    if (periodChooserState[0]) {
      data.dayChartData.forEach((hour) {
        if (DateTime.now().day == hour.time.day) {
          if (hour.temperature < lowestTemperature)
            lowestTemperature = hour.temperature;
          if (hour.temperature > highestTemperature)
            highestTemperature = hour.temperature;

          chartData.add(TemperatureChartData(
              time:
                  hour.time.hour.toString() + ":" + hour.time.minute.toString(),
              temperature: hour.temperature,
              weather: hour.weather,
              weatherIcon: hour.weatherIcon));
        }
      });
    } else if (periodChooserState[1]) {
      data.dayChartData.forEach((hour) {
        if (DateTime.now().day + 1 == hour.time.day) {
          if (hour.temperature < lowestTemperature)
            lowestTemperature = hour.temperature;
          if (hour.temperature > highestTemperature)
            highestTemperature = hour.temperature;

          chartData.add(TemperatureChartData(
              time:
                  hour.time.hour.toString() + ":" + hour.time.minute.toString(),
              temperature: hour.temperature,
              weather: hour.weather,
              weatherIcon: hour.weatherIcon));
        }
      });
    } else if (periodChooserState[2]) {
      data.weekChartData.forEach((day) {
        if (day.temperature < lowestTemperature)
          lowestTemperature = day.temperature;
        if (day.temperature > highestTemperature)
          highestTemperature = day.temperature;
        chartData.add(TemperatureChartData(
            time: convertToDay(day.time.weekday) +
                "\n (" +
                day.time.day.toString() +
                ")",
            temperature: day.temperature,
            weather: day.weather,
            weatherIcon: day.weatherIcon));
      });
    }
    chart = TemperatureChart();
    loadingState = false;
    update();
  }

  void changePeriodChooserState(List<bool> state) {
    periodChooserState = state;
    setData(data);
    update();
  }

  void changeSwitcherState(bool state) {
    switcherState = state;
    setData(data);
    update();
  }

  void openDrawer() async {
    database = AppDatabase.instance;

    isDrawerOpen = true;
    update();
  }

  void closeDrawer() async {
    isDrawerOpen = false;
    update();
  }

  void onLocationClicked(int index) async {
    if (locations[index].isDataAvailable ||
        (await connectionStatus.checkConnection())) {
      appSettings.currentLocation = index;
      appSettings.currentLocationId = locations[index].locId;
      await appSettings.saveData();
      onInit();
    } else {
      showSnackBar(title: "Connection", description: "No Internet Connection");
    }
  }

  void onLocationPageClicked() async {
    await appSettings.saveData();
    closeDrawer();
    update();
    onClose();
    Get.offAndToNamed(AppPages.LOCATION);
  }

  void setNotification() async {
    if (appSettings.weatherUpdate) {
      Workmanager wrk = Workmanager();
      await wrk.initialize(callbackDispatcher);
      await wrk.registerPeriodicTask("epicweather_background", "epicweather_weather_update",
          existingWorkPolicy: ExistingWorkPolicy.replace,
          constraints: Constraints(
            networkType: NetworkType.connected,
          ),
          inputData: {
            'locId': appSettings.currentLocationId,
            'isCel': appSettings.isCelciuis
          },
          frequency: Duration(hours: appSettings.updateTime),
          initialDelay: Duration(seconds: 5));
    } else {
      Workmanager wrk = Workmanager();
      await wrk.cancelAll();
    }
  }

  void onSettingsSaveClicked() async {
    setNotification();
    await appSettings.saveData();
    await appSettings.loadData();
    isSettingsOpen = false;
    update();
  }

  void settingsOptionClicked() {
    isSettingsOpen = true;
    isDrawerOpen = false;
    update();
  }

  void settingsBackClicked() {
    isSettingsOpen = false;
    update();
  }

  void onAppInfoClicked() {
    Get.dialog(
        Material(
          color: Colors.grey.withOpacity(0.4),
          child: dialogBox(
              controller: this,
              title: " ",
              description: Container(
                child: Column(
                  mainAxisAlignment: MainAxisAlignment.spaceBetween,
                  children: [
                    SvgPicture.asset(
                      theme.appSvgImages.logo,
                      width: 50,
                    ),
                    Text(
                      "Epic Weather",
                      style: theme.appTextTheme.txt18grey,
                    ),
                    Text(
                      "v1.0.0",
                      style:
                          theme.appTextTheme.txt18grey.copyWith(fontSize: 10),
                    ),
                    SizedBox(
                      height: 10,
                    ),
                    Text(
                      "by Epic Programmer",
                      style: theme.appTextTheme.txt12white,
                    ),
                    SizedBox(
                      height: 20,
                    ),
                  ],
                ),
              ),
              negetive: "API Doc",
              positive: "Ok",
              onNegetive: () async {
                if ((await connectionStatus.checkConnection())) {
                  const url = "https://youtube.com/epicprogrammer";
                  if (await canLaunch(url)) await launch(url);
                }
                Get.back();
              },
              onPositive: () {
                Get.back();
              }),
        ),
        barrierDismissible: true,
        barrierColor: Colors.transparent,
        transitionDuration: Duration(milliseconds: 200));
  }

  void onWeatherAlertClicked(bool isWeatherUpdateTrue) async {
    if (!isWeatherUpdateTrue) {
      appSettings.weatherUpdate = isWeatherUpdateTrue;
      update();
    }
    if (isWeatherUpdateTrue) {
      Get.dialog(
          Material(
            color: Colors.grey.withOpacity(0.4),
            child: dialogBox(
                controller: this,
                title: "AutoStart Permission Required",
                description: Container(
                  child: Column(
                    mainAxisAlignment: MainAxisAlignment.spaceBetween,
                    children: [
                      Text(
                        "app requires special auto start permission to show background notifications in some smartphones.",
                        style: theme.appTextTheme.txt18grey,
                        textAlign: TextAlign.center,
                      ),
                    ],
                  ),
                ),
                negetive: "Cancel",
                positive: "Go to Settings",
                onNegetive: () {
                  Get.back();
                },
                onPositive: () async {
                  const platform =
                      const MethodChannel('com.epicprogrammer.epic_weather/autostart');
                  await platform.invokeMethod('autostart');
                  Get.back();
                  appSettings.weatherUpdate = isWeatherUpdateTrue;
                  update();
                }),
          ),
          barrierDismissible: true,
          barrierColor: Colors.transparent,
          transitionDuration: Duration(milliseconds: 200));
    }
  }
}
