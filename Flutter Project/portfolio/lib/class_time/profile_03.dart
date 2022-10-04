import 'package:flutter/material.dart';

// ignore: camel_case_types
class RowCol_11 extends StatelessWidget {
  const RowCol_11({super.key});

  @override
  Widget build(BuildContext context) {
    return SafeArea(
      child: Scaffold(
        appBar: AppBar(
          leading: const Icon(Icons.people),
          title: const Text(
            'Sajjad\'s Portfolio',
            textAlign: TextAlign.center,
            style: TextStyle(
              fontSize: 22,
              height: 2,
              letterSpacing: 5, //letter spacing
              decorationStyle: TextDecorationStyle.double,
              decorationThickness: 1.5,
              fontStyle: FontStyle.italic,
            ),
          ),
        ),
        body: Row(
          mainAxisAlignment: MainAxisAlignment.center,
          children: [
            Column(
              children: [
                const Padding(padding: EdgeInsets.only(top: 60)),
                Image.asset(
                  'images/pic2.jpeg',
                  fit: BoxFit.fitWidth,
                  height: 220,
                  width: 220,
                ),
                Container(
                  height: 50,
                ),
                Row(
                  /// ignore: prefer_const_literals_to_create_immutables
                  children: [
                    const Padding(padding: EdgeInsets.only(top: 50)),
                    const Padding(padding: EdgeInsets.only(left: 20)),
                    const Text(
                      "Bootcamp id",
                      style:
                          TextStyle(fontSize: 16, fontWeight: FontWeight.bold),
                    ),
                    const Padding(padding: EdgeInsets.only(right: 120)),
                    const Text(
                      "2222",
                      style:
                          TextStyle(fontSize: 16, fontWeight: FontWeight.bold),
                    ),
                  ],
                ),
                Row(
                  // ignore: prefer_const_literals_to_create_immutables
                  children: [
                    const Padding(padding: EdgeInsets.only(top: 50)),
                    const Padding(padding: EdgeInsets.only(left: 20)),
                    const Text(
                      "Name",
                      style:
                          TextStyle(fontSize: 16, fontWeight: FontWeight.bold),
                    ),
                    const Padding(padding: EdgeInsets.only(right: 110)),
                    const Text(
                      "Sajjad Rahman",
                      style:
                          TextStyle(fontSize: 16, fontWeight: FontWeight.bold),
                    ),
                  ],
                ),
                Row(
                  // ignore: prefer_const_literals_to_create_immutables
                  children: [
                    const Padding(padding: EdgeInsets.only(top: 50)),
                    const Padding(padding: EdgeInsets.only(left: 20)),
                    const Text(
                      "Designation",
                      style:
                          TextStyle(fontSize: 16, fontWeight: FontWeight.bold),
                    ),
                    const Padding(padding: EdgeInsets.only(left: 110)),
                    const Text(
                      "Student",
                      style:
                          TextStyle(fontSize: 16, fontWeight: FontWeight.bold),
                    ),
                  ],
                ),
                Row(
                  // ignore: prefer_const_literals_to_create_immutables
                  children: [
                    const Padding(padding: EdgeInsets.only(top: 50)),
                    const Padding(padding: EdgeInsets.only(left: 20)),
                    const Text(
                      "Career Objective",
                      style:
                          TextStyle(fontSize: 16, fontWeight: FontWeight.bold),
                    ),
                    const Padding(padding: EdgeInsets.only(left: 40)),
                    const Text(
                      "Self motivated\nteam member\nseeking work\na lead\nandroid dev  ",
                      style:
                          TextStyle(fontSize: 15, fontWeight: FontWeight.bold),
                    ),
                  ],
                ),
                Row(
                  // ignore: prefer_const_literals_to_create_immutables
                  children: [
                    const Padding(padding: EdgeInsets.only(top: 50)),
                    const Padding(padding: EdgeInsets.only(left: 20)),
                    const Text(
                      "Skill",
                      style:
                          TextStyle(fontSize: 16, fontWeight: FontWeight.bold),
                    ),
                    const Padding(padding: EdgeInsets.only(left: 80)),
                    const Text(
                      "C++, Java , MySQL",
                      style:
                          TextStyle(fontSize: 16, fontWeight: FontWeight.bold),
                    ),
                  ],
                ),
              ],
            )
          ],
        ),
      ),
    );
  }
}
