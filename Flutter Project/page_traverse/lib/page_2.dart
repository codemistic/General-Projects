import 'package:flutter/material.dart';
import 'package:flutter/src/widgets/container.dart';
import 'package:flutter/src/widgets/framework.dart';

class SecondScreen extends StatefulWidget {
  const SecondScreen({super.key});

  @override
  State<SecondScreen> createState() => _SecondScreenState();
}

class _SecondScreenState extends State<SecondScreen> {
  @override
  Widget build(BuildContext context) {
    return SafeArea(
        child: Scaffold(
      appBar: AppBar(
        leading: Icon(Icons.one_k),
        title: Text(
          'Second Screen',
          style: TextStyle(color: Colors.pink),
        ),
        actions: const [
          Icon(Icons.search),
          SizedBox(
            width: 10,
          ),
          Icon(Icons.people),
          SizedBox(
            width: 10,
          ),
        ],
      ),
      body: Center(
        child: Column(
          children: [
            const SizedBox(
              height: 120,
            ),
            Container(
              //padding: const EdgeInsets.only(top: 20, left: 120),
              width: 250,
              height: 250,
              child: Image.asset(
                'images/sajjad.jpg',
                fit: BoxFit.fill,
              ),
              color: Colors.amberAccent,
            ),
            const SizedBox(
              height: 20,
            ),

            const SizedBox(
              height: 50,
            ),
            // ElevatedButton(
            //   onPressed: () {},
            //   child: const Text(
            //     'Next Page ',
            //     style: TextStyle(
            //       fontSize: 20,
            //       fontWeight: FontWeight.bold,
            //     ),
            //   ),
            // ),
          ],
        ),
      ),
    ));
  }
}
