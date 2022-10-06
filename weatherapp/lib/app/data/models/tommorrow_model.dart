class TommorrowData {
  double temperature = 0.0;
  double uvi = 0.0;
  double wind = 0.0;
  double humidity = 0.0;
  String weather = "";
  String weatherIcon = "";

  TommorrowData() {}

  TommorrowData.fromJSON(Map<String, dynamic> data) {
    this.temperature = data["temperature"].toDouble();
    this.uvi = data["uvi"].toDouble();
    this.wind = (data["wind"].toDouble() * 3.6).ceilToDouble();
    this.humidity = data["humidity"].toDouble();
    this.weather = data["weather"].toString();
    this.weatherIcon = data["weatherIcon"].toString();
  }

  Map<String, dynamic> toJSON() {
    return {
      "temperature": temperature,
      "uvi": uvi,
      "wind": wind,
      "humidity": humidity,
      "weather": weather,
      "weatherIcon": weatherIcon,
    };
  }
}
