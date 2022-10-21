import 'package:flutter/material.dart';

class FirstScreen extends StatefulWidget {
  const FirstScreen({super.key});

  @override
  State<FirstScreen> createState() => _FirstScreenState();
}

class _FirstScreenState extends State<FirstScreen> {
  @override
  Widget build(BuildContext context) {
    return SafeArea(
        child: Scaffold(
      appBar: AppBar(
        leading: Icon(Icons.one_k),
        title: Text('First Screen'),
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
              height: 200,
            ),
            Container(
              padding: const EdgeInsets.only(top: 20, left: 120),
              // color: Colors.green,
              child: Row(children: const [
                Text(
                  'Md ',
                  style: TextStyle(
                    fontSize: 24,
                    color: Color.fromARGB(255, 15, 16, 15),
                    fontWeight: FontWeight.bold,
                  ),
                ),
                SizedBox(
                  width: 20,
                ),
                Text(
                  'Sajjad',
                  style: TextStyle(
                    fontSize: 24,
                    color: Color.fromARGB(255, 15, 16, 15),
                    fontWeight: FontWeight.bold,
                  ),
                )
              ]),
            ),
            SizedBox(
              height: 30,
            ),
            ElevatedButton(
                onPressed: () {
                  Navigator.pushNamed(context, "/second");
                },
                child: Text('Next Page '))
          ],
        ),
      ),
    ));
  }
}
