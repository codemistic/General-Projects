import 'package:flutter/cupertino.dart';
import 'package:flutter/material.dart';

class RowCol_1 extends StatelessWidget {
  const RowCol_1({super.key});

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
          child: Column(
            mainAxisAlignment: MainAxisAlignment.spaceAround,
            children: [
              Container(
                margin: EdgeInsets.all(1),
                child: Image.asset(
                  'images/pic2.jpeg',
                  fit: BoxFit.contain,
                  height: 170,
                  width: 220,
                ),
              ),
              Container(
                //margin: EdgeInsets.all(10),
                child: Column(
                  mainAxisAlignment: MainAxisAlignment.spaceBetween,
                  children: [
                    Column(
                      //mainAxisAlignment: MainAxisAlignment.spaceEvenly,
                      children: [
                        Row(
                          mainAxisAlignment: MainAxisAlignment.spaceEvenly,
                          //crossAxisAlignment: CrossAxisAlignment.start,

                          /// ignore: prefer_const_literals_to_create_immutables
                          children: [
                            const Padding(padding: EdgeInsets.only(left: 20)),
                            const Text("Name"),
                            const Padding(padding: EdgeInsets.only(left: 80)),
                            const Text("Sajjad Rahman"),
                          ],
                        ),
                        const Padding(padding: EdgeInsets.only(top: 12)),
                        Row(
                          //mainAxisAlignment: MainAxisAlignment.spaceEvenly,
                          // ignore: prefer_const_literals_to_create_immutables
                          children: [
                            const Padding(padding: EdgeInsets.only(left: 20)),
                            const Text("Name"),
                            const Padding(padding: EdgeInsets.only(left: 100)),
                            const Text("Sajjad Rahman"),
                          ],
                        ),
                        Row(
                          //mainAxisAlignment: MainAxisAlignment.spaceEvenly,
                          // ignore: prefer_const_literals_to_create_immutables
                          children: [
                            const Padding(padding: EdgeInsets.only(left: 20)),
                            const Text("Name"),
                            const Padding(padding: EdgeInsets.only(left: 100)),
                            const Text("Sajjad Rahman"),
                          ],
                        ),
                        Row(
                          //mainAxisAlignment: MainAxisAlignment.spaceEvenly,
                          // ignore: prefer_const_literals_to_create_immutables
                          children: [
                            const Padding(padding: EdgeInsets.only(left: 20)),
                            const Text("Name"),
                            const Padding(padding: EdgeInsets.only(left: 100)),
                            const Text("Sajjad Rahman"),
                          ],
                        ),
                        Row(
                          //mainAxisAlignment: MainAxisAlignment.spaceEvenly,
                          // ignore: prefer_const_literals_to_create_immutables
                          children: [
                            const Padding(padding: EdgeInsets.only(left: 20)),
                            const Text("Name"),
                            const Padding(padding: EdgeInsets.only(left: 100)),
                            const Text("Sajjad Rahman"),
                          ],
                        ),
                      ],
                    )
                  ],
                ),
              )
            ],
          ),
        ),
      ),
    );
  }
}
