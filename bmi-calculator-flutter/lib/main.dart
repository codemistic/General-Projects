import 'package:flutter/material.dart';
import 'screens/input_page.dart';
import 'package:bmi_calculator/screens/input_page.dart';

void main() {
  runApp(BMICalculator());
}

class BMICalculator extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      theme: ThemeData.dark().copyWith(
        appBarTheme: AppBarTheme(
          color: Color(0xff090c20),
        ),
        scaffoldBackgroundColor: Color(0xff090c20),
      ),
      home: InputPage(),
      // initialRoute: '/',
      // routes: {
      //   '/' : (context)=> InputPage(),
      //   '/second' : (context)=> ResultPage(
      //     calculateBMI: calc.calculateBMI(),
      //   ),
      // },
    );
  }
}