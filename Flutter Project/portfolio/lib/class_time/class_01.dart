import 'package:flutter/cupertino.dart';
import 'package:flutter/material.dart';

class NewPage extends StatefulWidget {
  @override
  State<NewPage> createState() => _NewPageState();
}

class _NewPageState extends State<NewPage> {
  @override
  Widget build(BuildContext context) {
    return SafeArea(
      child: Container(
        color: Colors.green,
        // ignore: prefer_const_constructors
        child: Image(
          image: NetworkImage(
              'https://images.pexels.com/photos/213780/pexels-photo-213780.jpeg?auto=compress&cs=tinysrgb&dpr=1&w=500'),
          fit: BoxFit.contain,
        ),
        // child: Text(
        //   'Sami',
        //   style: TextStyle(color: Colors.black, fontSize: 89.50),
        // ),
        //   child: Image(
        //     /// fit: ,
        //     //   image: NetworkImage(
        //     //       'https://www.pinterest.com/pin/neymar-jr-wallpaper-em-2022--890235051313997441/'),
        //     // ),
        //   //   image: NetworkImage(
        //   //       'https://docs.flutter.dev/assets/images/dash/dash-fainting.gif'),
        //   // ),

        // )

        // child: Image.network(
        //   "https://images.pexels.com/photos/213780/pexels-photo-213780.jpeg?auto=compress&cs=tinysrgb&dpr=1&w=500",
        //   fit: BoxFit.fill,
        // ),
      ),
    );
  }
}
