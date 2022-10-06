import 'dart:async';

import 'package:flutter/material.dart';
import 'package:geolocator/geolocator.dart';
import 'package:get/get.dart';
import 'package:epic_weather/app/settings/settings.dart';
import 'package:epic_weather/app/utils/connectivity.dart';
import 'package:epic_weather/app/utils/geolocator.dart';
import 'package:epic_weather/app/data/Api/weather_api.dart';
import 'package:epic_weather/app/data/database/database.dart';
import 'package:epic_weather/app/data/models/location_model.dart';
import 'package:epic_weather/app/routes/app_pages.dart';
import 'package:epic_weather/app/theme/app_theme.dart';
import 'package:epic_weather/app/widgets/common_components.dart';
import 'package:epic_weather/app/widgets/locationview_components.dart';

class LocationSelectController extends GetxController {
  //statc variables
  final WeatherApi api = WeatherApi();
  ScrollController scrollController =
      ScrollController(initialScrollOffset: 0.0, keepScrollOffset: true);
  TextEditingController searchTextConroller = TextEditingController();
  FocusNode focusNode = FocusNode();

  //global variables
  late LocationViewComponents components;
  late AppTheme theme;
  late Size size;
  late AppDatabase database;
  late ConnectionStatusSingleton connectionStatus;
  late Settings appSettings;

  //State Variables
  double scrollOffset = 0.0;
  bool typingState = false;
  bool loadingState = false;
  bool locationsAvailable = false;
  bool isSnackbarOn = false;

  //Data variables
  var locations;
  var locationList;
  var currentLocation = -1;

  @override
  void onInit() async {
    database = AppDatabase.instance;
    appSettings = Settings.instance;
    appSettings.loadData();

    connectionStatus = ConnectionStatusSingleton.getInstance();
    connectionStatus.initialize();

    setTheme();

    size = Get.size;
    components = LocationViewComponents(size: size, theme: theme);
    scrollController.addListener(() {
      if (scrollController.offset >= 0)
        scrollOffset =
            scrollController.offset < 100 ? scrollController.offset : 100.0;
      update();
    });

    locations = (await database.getAllLocations());
    if (locations.length > 0) {
      locationsAvailable = true;
      currentLocation = appSettings.currentLocation;
      update();
    }
    super.onInit();
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
  }

  Future<bool> isOnline() async {
    return (await connectionStatus.checkConnection());
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
    isSnackbarOn = true;
  }

  void onSearchBarTextChanged(String value) async {
    if (await connectionStatus.checkConnection()) {
      isSnackbarOn = false;
      if (value == '') {
        typingState = false;
        loadingState = false;
      } else {
        loadingState = true;
        typingState = true;
        update();
        locationList = ((await api.getCities(value))
            .toList()
            .map((city) => Location.fromAPI(city))).toList();
        loadingState = false;
      }
      update();
    } else {
      searchTextConroller.clear();
      if (!isSnackbarOn) {
        showSnackBar(
            title: "Connection", description: "No Internet Connection");
      }
    }
  }

  void getLocationFromGps() async {
    if (await connectionStatus.checkConnection()) {
      loadingState = true;
      update();
      await determinePosition()
          .then(
              (value) => getLocationFromCoord(value.latitude, value.longitude))
          .onError((error, stackTrace) => locatorError(error));
    } else {
      showSnackBar(title: "Connection", description: "No Internet Connection");
    }
  }

  Future<void> onRefresh() async {
    loadingState = true;
    update();
    database = AppDatabase.instance;
    locations = (await database.getAllLocations());
    if (locations.length > 0) {
      locationsAvailable = true;
    }
    await Future.delayed(Duration(seconds: 1));
    loadingState = false;
    update();
  }

  void locatorError(error) {
    loadingState = false;
    Get.dialog(
        Material(
          color: Colors.grey.withOpacity(0.4),
          child: dialogBox(
              controller: this,
              title: "Location",
              description: Text(
                error == LocatorStatus.LOCATION_OFF
                    ? "Please Turn On Your Location"
                    : error == LocatorStatus.PERMISSIONS_DISABLED
                        ? "Location Access Denied"
                        : error == LocatorStatus.PERMISSIONS_DISABLED_FOREVER
                            ? "App Location Permissions Disabled"
                            : "Can't Fetch Location",
                style: theme.appTextTheme.txt18grey,
              ),
              negetive: "Cancel",
              positive: error == LocatorStatus.LOCATION_OFF
                  ? "Turn On"
                  : error == LocatorStatus.PERMISSIONS_DISABLED
                      ? "Request"
                      : error == LocatorStatus.PERMISSIONS_DISABLED_FOREVER
                          ? "Ok"
                          : "Try Again",
              onNegetive: () => Get.back(),
              onPositive: error == LocatorStatus.LOCATION_OFF
                  ? () {
                      Geolocator.openLocationSettings();
                      Get.back();
                    }
                  : error == LocatorStatus.PERMISSIONS_DISABLED
                      ? () {
                          Geolocator.requestPermission();
                          Get.back();
                        }
                      : error == LocatorStatus.PERMISSIONS_DISABLED_FOREVER
                          ? () => Get.back()
                          : () {
                              Get.back();
                              getLocationFromGps();
                            }),
        ),
        barrierColor: Colors.transparent,
        transitionDuration: Duration(milliseconds: 200));
    focusNode.unfocus();
    loadingState = false;
    typingState = false;
    update();
  }

  void getLocationFromCoord(double lat, double lon) async {
    if (await connectionStatus.checkConnection()) {
      locationList = ((await api.getCitiesByLocation(lon, lat))
          .toList()
          .map((city) => Location.fromAPI(city))).toList();
      loadingState = false;
      typingState = true;
      update();
    }
  }

  void backClicked() async {
    if (typingState) {
      searchTextConroller.text = '';
      typingState = false;
      loadingState = false;
      update();
    } else {
      if (currentLocation >= 0) Get.offAndToNamed(AppPages.INITIAL);
    }
  }

  void addLocation(int index) async {
    if (await connectionStatus.checkConnection()) {
      typingState = false;
      loadingState = true;
      update();
      database = AppDatabase.instance;
      Location loc = locationList[index];
      loc.setWeather(await api.getWeather(locationList[index].locId));
      await database.addLocation(loc);
      locations = (await database.getAllLocations());
      searchTextConroller.text = '';
      loadingState = false;
      locationsAvailable = true;
      update();
    } else {
      showSnackBar(title: "Connection", description: "No Internet Connection");
    }
  }

  void deleteLocation(int index) {
    database = AppDatabase.instance;
    Location loc = locations[index];
    Get.dialog(
        Material(
          color: Colors.grey.withOpacity(0.4),
          child: dialogBox(
              controller: this,
              title: "Delete Location",
              description: Text(
                "Do you want to delete this location?",
                style: theme.appTextTheme.txt18grey,
              ),
              onNegetive: () => Get.back(),
              onPositive: () async {
                loadingState = true;
                update();
                await database.deleteLocation(loc);
                locations = (await database.getAllLocations());
                if (locations.length > 0) {
                  locationsAvailable = true;
                } else {
                  locationsAvailable = false;
                }
                if (index == currentLocation)
                  currentLocation = -1;
                else
                  currentLocation--;
                appSettings.currentLocation = currentLocation;
                appSettings.saveData();
                loadingState = false;
                Get.back();
                update();
              },
              positive: "Delete",
              negetive: "Cancel"),
        ),
        barrierColor: Colors.transparent,
        transitionDuration: Duration(milliseconds: 200));
    focusNode.unfocus();
  }

  void onLocationClicked(int index) async {
    if (await connectionStatus.checkConnection() ||
        locations[index].isDataAvailable) {
      currentLocation = index;
      appSettings.currentLocation = index;
      appSettings.currentLocationId = locations[index].locId;
      await appSettings.saveData();
      update();
      Get.offAndToNamed(AppPages.INITIAL);
    } else {
      showSnackBar(title: "Connection", description: "No Internet Connection");
    }
  }
}
