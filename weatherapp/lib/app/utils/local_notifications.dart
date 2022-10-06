import 'package:flutter_local_notifications/flutter_local_notifications.dart';
import 'package:epic_weather/app/data/Api/weather_api.dart';
import 'package:epic_weather/app/data/database/database.dart';
import 'package:epic_weather/app/data/models/location_model.dart';
import 'package:workmanager/workmanager.dart';

class LocalNotifications {
  late FlutterLocalNotificationsPlugin notificationsPlugin;

  Future intialize() async {
    var initSetAndroid =
        new AndroidInitializationSettings('@mipmap/ic_launcher');
    var initSet = new InitializationSettings(android: initSetAndroid);
    notificationsPlugin = new FlutterLocalNotificationsPlugin();
    await notificationsPlugin.initialize(initSet);
  }

  Future showNotificationWithDefaultSound(
      {required Location location, required bool isCelcius}) async {
    var androidPlatformChannelSpecifics = new AndroidNotificationDetails(
        '3612', 'We Now', 'We Now Weather Updates',
        importance: Importance.max, priority: Priority.max);
    var platformChannelSpecifics =
        new NotificationDetails(android: androidPlatformChannelSpecifics);
    await notificationsPlugin.show(
      0,
      location.currentWeather + " in " + location.cityName,
      (isCelcius
              ? (location.currentTemperature - 273).ceil().toString() + "°c"
              : ((location.currentTemperature - 273) * (9 / 5) + 32)
                      .ceil()
                      .toString() +
                  "°F") +
          " with wind " +
          (location.currentWind).toString() +
          " km/h",
      platformChannelSpecifics,
      payload: 'Default_Sound',
    );
  }

  Future dummyNotification() async {
    var androidPlatformChannelSpecifics = new AndroidNotificationDetails(
        '1', 'We Now', 'We Now Weather Updates',
        importance: Importance.max, priority: Priority.max);
    var platformChannelSpecifics =
        new NotificationDetails(android: androidPlatformChannelSpecifics);
    await notificationsPlugin.show(
      100,
      "Hi",
      "hello",
      platformChannelSpecifics,
      payload: 'Default_Sound',
    );
  }
}

void callbackDispatcher() {
  Workmanager().executeTask((task, inputData) async {
    var database = AppDatabase.instance;
    Location data = (await database.getLocation(inputData!['locId']));
    LocalNotifications notifications = LocalNotifications();
    await notifications.intialize();

    DateTime currTime = DateTime.now();

    if (!((data.date.day == currTime.day) &&
        (data.date.month == currTime.month) &&
        (data.date.year == currTime.year))) {
      data.setFullWeather(
          await WeatherApi().getFullWeather(data.longitude, data.latitude));
    }
    notifications.showNotificationWithDefaultSound(
        location: data, isCelcius: inputData['isCel']);
    return Future.value(true);
  });
}
