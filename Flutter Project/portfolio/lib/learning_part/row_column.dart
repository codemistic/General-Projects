import 'dart:io';

import 'package:flutter/material.dart';

class BasicLayoutTry extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return SafeArea(
        child: Scaffold(
      appBar: AppBar(
        //  leading: Icons.handshake,
        title: const Text(
          'Sajjad',
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
      body: Container(
        color: Colors.amber,
        child: Column(
          children: [
            Row(
              // ignore: prefer_const_literals_to_create_immutables
              children: [
                const Text(("Bale")),
                const Text(("Bal1")),
              ],
            ),
            Expanded(
              child: new Padding(
                padding: const EdgeInsets.all(20.0),
                //child: countryCodePicker,
              ),
            ),
            Expanded(
              child: new Padding(
                padding: const EdgeInsets.all(20.0),
                // child: mobileNumber,
              ),
            ),
          ],
        ),
      ),
    ));
  }
}
