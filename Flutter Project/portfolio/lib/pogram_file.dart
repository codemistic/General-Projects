import 'package:flutter/material.dart';

class MainLayout extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return SafeArea(
      child: Scaffold(
        appBar: AppBar(
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
            //crossAxisAlignment: CrossAxisAlignment.center,
            mainAxisAlignment: MainAxisAlignment.center,
            crossAxisAlignment: CrossAxisAlignment.center,

            children: [
              /// that use for gap create from the top of the app bar
              Padding(
                padding: EdgeInsets.fromLTRB(20, 0, 20, 0),
                child: Container(
                  padding: const EdgeInsets.all(0.0),
                  width: 20.0,
                  height: 20.0,
                ), //Container
              ),
              Expanded(
                child: Image.asset(
                  'images/pic2.jpeg',
                  fit: BoxFit.cover,
                ),
              ),
              Padding(
                padding: EdgeInsets.fromLTRB(20, 0, 20, 0),
                child: Container(
                  padding: const EdgeInsets.all(0.0),
                  width: 20.0,
                  height: 20.0,
                ), //Container
              ),
              Expanded(
                child: Container(
                  margin: new EdgeInsets.all(2.0),
                  child: Column(children: [
                    Row(
                      mainAxisAlignment: MainAxisAlignment.spaceAround,
                      // ignore: prefer_const_literals_to_create_immutables
                      children: [
                        //Padding(padding: padding),
                        const Text(
                          'Bootcamp Id  ',
                          textAlign: TextAlign.center,
                          style: TextStyle(
                            fontSize: 20,
                            height: 2,
                            //letterSpacing: 5, //letter spacing
                            // decorationStyle: TextDecorationStyle.double,
                            decorationThickness: 1.5,
                            fontStyle: FontStyle.italic,
                          ),
                        ),
                        const Text(
                          'LUCSFB22',
                          textAlign: TextAlign.center,
                          style: TextStyle(
                            fontSize: 20,
                            height: 2,
                            //letterSpacing: 5, //letter spacing
                            // decorationStyle: TextDecorationStyle.double,
                            decorationThickness: 1.5,
                            fontStyle: FontStyle.italic,
                          ),
                        ),
                      ],
                    ),
                    Row(
                      mainAxisAlignment: MainAxisAlignment.spaceAround,
                      // ignore: prefer_const_literals_to_create_immutables
                      children: [
                        //Padding(padding: padding),
                        const Text(
                          'Name : ',
                          textAlign: TextAlign.center,
                          style: TextStyle(
                            fontSize: 20,
                            height: 2,
                            //letterSpacing: 5, //letter spacing
                            // decorationStyle: TextDecorationStyle.double,
                            decorationThickness: 1.5,
                            fontStyle: FontStyle.italic,
                          ),
                        ),
                        const Text(
                          'Sajjad Rahman',
                          textAlign: TextAlign.center,
                          style: TextStyle(
                            fontSize: 20,
                            height: 2,
                            //letterSpacing: 5, //letter spacing
                            // decorationStyle: TextDecorationStyle.double,
                            decorationThickness: 1.5,
                            fontStyle: FontStyle.italic,
                          ),
                        ),
                      ],
                    ),
                    Row(
                      mainAxisAlignment: MainAxisAlignment.spaceAround,
                      // ignore: prefer_const_literals_to_create_immutables
                      children: [
                        //Padding(padding: padding),
                        const Text(
                          'Designation ',
                          textAlign: TextAlign.center,
                          style: TextStyle(
                            fontSize: 20,
                            height: 2,
                            //letterSpacing: 5, //letter spacing
                            // decorationStyle: TextDecorationStyle.double,
                            decorationThickness: 1.5,
                            fontStyle: FontStyle.italic,
                          ),
                        ),
                        const Text(
                          'Student',
                          textAlign: TextAlign.center,
                          style: TextStyle(
                            fontSize: 20,
                            height: 2,
                            //letterSpacing: 5, //letter spacing
                            // decorationStyle: TextDecorationStyle.double,
                            decorationThickness: 1.5,
                            fontStyle: FontStyle.italic,
                          ),
                        ),
                      ],
                    ),
                  ]),
                ),
              )
            ],
          ),
        ),
      ),
    );
  }
}
