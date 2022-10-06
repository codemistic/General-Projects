// This is a basic Flutter widget test.
//
// To perform an interaction with a widget in your test, use the WidgetTester
// utility that Flutter provides. For example, you can send tap and scroll
// gestures. You can also use WidgetTester to find child widgets in the widget
// tree, read text, and verify that the values of widget properties are correct.

import 'package:flutter/material.dart';
import 'package:flutter_test/flutter_test.dart';
import 'package:epic_weather/app/data/Api/weather_api.dart';

import 'package:epic_weather/main.dart';

void main() {
  test("check", () async {
    print(await WeatherApi().getFullWeather(46.0, 42.0));
  });
}
