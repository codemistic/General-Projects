import 'package:epic_weather/app/data/database/database.dart';

class Settings {
  bool isDarkMode = false;
  bool isCelciuis = true;
  bool isdefaultTheme = true;
  bool weatherUpdate = false;
  int updateTime = 2;

  int currentLocation = -1;
  String currentLocationId = "0";

  static final _singleton = Settings._();
  static Settings get instance => _singleton;
  late AppDatabase db;

  Settings._();

  Future saveData() async {
    db = AppDatabase.instance;
    await db.setSettings({
      'id': '1',
      'isDarkMode': isDarkMode,
      'isCelciuis': isCelciuis,
      'isdefaultTheme': isdefaultTheme,
      'currentLocation': currentLocation,
      'currentLocationId': currentLocationId,
      'weatherUpdate': weatherUpdate,
      'updateTime': updateTime
    });
  }

  Future loadData() async {
    db = AppDatabase.instance;
    var data = (await db.getSettings());
    if (data != null) {
      isDarkMode = data.value['isDarkMode'];
      isCelciuis = data.value['isCelciuis'];
      isdefaultTheme = data.value['isdefaultTheme'];
      currentLocation = data.value['currentLocation'];
      currentLocationId = data.value['currentLocationId'];
      weatherUpdate = data.value['weatherUpdate'];
      updateTime = data.value['updateTime'];
    }
  }
}
