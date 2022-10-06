import 'package:epic_weather/app/data/models/temperature_model.dart';
import 'package:epic_weather/app/data/models/tommorrow_model.dart';

class Location {
  late String locId;
  late String cityName;
  late String countryName;
  late double longitude;
  late double latitude;

  DateTime date = DateTime.now();
  double currentTemperature = 0.0;
  String currentWeather = "";
  String weatherIcon = "";
  double uvi = 0.0;
  double currentWind = 0.0;
  double currentHumidity = 0.0;
  var dayChartData = [];
  var weekChartData = [];
  TommorrowData tommorrowData = TommorrowData();

  bool isDataAvailable = false;

  Location.fromAPI(Map<String, dynamic> data) {
    this.locId = data["locId"].toString();
    this.cityName = data["cityName"];
    this.countryName = data["countryName"];
    this.longitude = data["lon"].toDouble();
    this.latitude = data["lat"].toDouble();
  }

  Map<String, dynamic> toDatabase() {
    return {
      'date': date.toString(),
      'locId': locId,
      'cityName': cityName,
      'countryName': countryName,
      'currentTemperature': currentTemperature,
      'currentWeather': currentWeather,
      'weatherIcon': weatherIcon,
      'uvi': uvi,
      'currentWind': currentWind,
      'currentHumidity': currentHumidity,
      'dayChartData': dayChartData.map((e) => e.toJSON()).toList(),
      'weekChartData': weekChartData.map((e) => e.toJSON()).toList(),
      'lon': longitude,
      'lat': latitude,
      'isDataAvailable': isDataAvailable,
      'tommorrowData': tommorrowData.toJSON()
    };
  }

  Location.fromDatabase(Map<String, dynamic> data) {
    this.isDataAvailable = data["isDataAvailable"];
    this.latitude = data["lat"];
    this.longitude = data["lon"];
    this.date = DateTime.parse(data["date"]);
    this.locId = data["locId"].toString();
    this.cityName = data["cityName"];
    this.countryName = data["countryName"];
    this.currentWeather = data["currentWeather"];
    this.weatherIcon = data["weatherIcon"];
    this.currentTemperature = data["currentTemperature"];
    this.uvi = data["uvi"];
    this.currentHumidity = data["currentHumidity"];
    this.currentWind = data["currentWind"];
    this.dayChartData = data["dayChartData"] != null
        ? data["dayChartData"].map((hours) {
            return TemperatureData(
                time: DateTime.parse(hours["time"]),
                temperature: hours["temperature"],
                weather: hours["weather"],
                weatherIcon: hours["weatherIcon"]);
          }).toList()
        : [];
    this.weekChartData = data["weekChartData"] != null
        ? data["weekChartData"].map((day) {
            return TemperatureData(
                time: DateTime.parse(day["time"]),
                temperature: day["temperature"],
                weather: day["weather"],
                weatherIcon: day["weatherIcon"]);
          }).toList()
        : [];
    this.tommorrowData = TommorrowData.fromJSON(data["tommorrowData"]);
  }

  void setWeather(Map<String, dynamic> data) {
    date = DateTime.fromMillisecondsSinceEpoch(data["date"] * 1000);
    locId = data["locId"].toString();
    cityName = data["cityName"];
    countryName = data["countryName"];
    currentWeather = data["currentWeather"];
    weatherIcon = data["weatherIcon"];
    currentTemperature = data["currentTemperature"].toDouble();
  }

  void setFullWeather(Map<String, dynamic> data) {
    date = DateTime.fromMillisecondsSinceEpoch(data["date"] * 1000);
    currentWeather = data["currentWeather"];
    weatherIcon = data["weatherIcon"];
    currentTemperature = data["currentTemperature"].toDouble();
    uvi = data["uvi"].toDouble();
    currentHumidity = data["currentHumidity"].toDouble();
    currentWind = (data["currentWind"].toDouble() * 3.6).ceilToDouble();
    dayChartData = data["hourlyData"] != null
        ? data["hourlyData"].map((hours) {
            return TemperatureData(
                time: DateTime.fromMillisecondsSinceEpoch(hours["time"] * 1000),
                temperature: hours["temperature"].toDouble(),
                weather: hours["weather"],
                weatherIcon: hours["weatherIcon"]);
          }).toList()
        : [];
    weekChartData = data["dailyData"] != null
        ? data["dailyData"].map((day) {
            return TemperatureData(
                time: DateTime.fromMillisecondsSinceEpoch(day["time"] * 1000),
                temperature: day["temperature"].toDouble(),
                weather: day["weather"],
                weatherIcon: day["weatherIcon"]);
          }).toList()
        : [];
    tommorrowData = TommorrowData.fromJSON(data["tommorrowData"]);
  }
}
