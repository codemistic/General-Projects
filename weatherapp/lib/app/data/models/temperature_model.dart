class TemperatureData {
  late DateTime time;
  late double temperature;
  late String weather;
  late String weatherIcon;

  TemperatureData(
      {required this.time,
      required this.temperature,
      required this.weather,
      required this.weatherIcon});
  Map<String, dynamic> toJSON() {
    return {
      'time': time.toString(),
      'temperature': temperature,
      'weather': weather,
      'weatherIcon': weatherIcon
    };
  }
}

class TemperatureChartData {
  late String time;
  late double temperature;
  late String weather;
  late String weatherIcon;

  TemperatureChartData(
      {required this.time,
      required this.temperature,
      required this.weather,
      required this.weatherIcon});
  Map<String, dynamic> toJSON() {
    return {
      'time': time,
      'temperature': temperature,
      'weather': weather,
      'weatherIcon': weatherIcon
    };
  }
}
