import 'package:flutter/material.dart';
import 'constants.dart';

class ShowingIcon extends StatelessWidget {
  ShowingIcon({this.setIcon, @required this.setText});

  final IconData setIcon;
  final String setText;

  @override
  Widget build(BuildContext context) {
    return Column(
      mainAxisAlignment: MainAxisAlignment.center,
      children: [
        Icon(
          setIcon,
          color: Color(0xffffffff),
          size: 80,
        ),
        SizedBox(
          height: 20,
        ),
        Text(
          setText,
          style: kLabelTextStyle,
        ),
      ],
    );
  }
}
