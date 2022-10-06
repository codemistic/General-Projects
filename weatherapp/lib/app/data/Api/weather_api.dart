import 'dart:convert';
import 'package:http/http.dart' as http;

class WeatherApi {
  static const String _src = "https://we-now.herokuapp.com";

  Future getCities(String locationString) async {
    final String url = _src + "/city/query";

    Map<String, dynamic> data = {"city": locationString};

    var resp = await http.post(Uri.parse(url),
        headers: {"Content-Type": "application/json"},
        body: jsonEncode(data).toString());
    return jsonDecode(resp.body);
  }

  Future getCitiesByLocation(double lon, double lat) async {
    final String url = _src + "/city/coord";

    Map<String, dynamic> data = {"lon": lon, "lat": lat};

    var resp = await http.post(Uri.parse(url),
        headers: {"Content-Type": "application/json"},
        body: jsonEncode(data).toString());
    return jsonDecode(resp.body);
  }

  Future getWeather(String locId) async {
    final String url = _src + "/weather/id";

    Map<String, dynamic> data = {"id": locId};

    var resp = await http.post(Uri.parse(url),
        headers: {"Content-Type": "application/json"},
        body: jsonEncode(data).toString());
    return jsonDecode(resp.body);
  }

  Future getFullWeather(double lon, double lat) async {
    final String url = _src + "/weather/coord/full";

    Map<String, dynamic> data = {"lon": lon, "lat": lat};

    var resp;

    await http
        .post(Uri.parse(url),
            headers: {"Content-Type": "application/json"},
            body: jsonEncode(data).toString())
        .then((value) {
      resp = jsonDecode(value.body);
    }).onError((error, stackTrace) {
      resp = null;
    });

    if (resp == null) {
      return Future.error(0);
    } else {
      return resp;
    }
  }
}
