import 'package:flutter/material.dart';
import 'package:portfolio/pogram_file.dart';
import 'class_time/cla_02.dart';
import 'class_time/class_01.dart';
import 'class_time/profile_03.dart';
import 'learning_part/row_column.dart';

void main() {
  runApp(const MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({super.key});

  // This widget is the root of your application.
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'Flutter Demo',
      debugShowCheckedModeBanner: false,
      theme: ThemeData(primarySwatch: Colors.purple),
      home: RowCol_11(),
    );
  }
}
