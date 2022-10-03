import 'package:flutter/material.dart';
import 'constants.dart';

class BottomButton extends StatelessWidget {

  Function onTap;
  String text;
  BottomButton({@required this.onTap,@required this.text});

  @override
  Widget build(BuildContext context) {
    return GestureDetector(
      onTap: onTap,
      child: Container(
        child: Center(
          child: Text(
            text,
            style: TextStyle(
              fontSize: 30.0, fontWeight: FontWeight.w900,
            ),
          ),
        ),
        color: kActiveBottomContainerColour,
        height: 80.0,
        width: double.infinity,
      ),
    );
  }
}
