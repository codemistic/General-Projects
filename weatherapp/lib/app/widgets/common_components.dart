import 'package:flutter/material.dart';

Widget dialogBox(
    {required controller,
    required String title,
    required Widget description,
    required String negetive,
    required String positive,
    required Function onNegetive,
    required Function onPositive}) {
  return Container(
    alignment: Alignment.center,
    child: Container(
      padding: EdgeInsets.symmetric(horizontal: 30, vertical: 20),
      width: controller.size.width * 0.8,
      height: controller.size.height * 0.3,
      decoration: BoxDecoration(
          color: controller.theme.appColorTheme.colorBackground,
          borderRadius: BorderRadius.circular(15),
          boxShadow: [controller.theme.appColorTheme.shadowMedium]),
      child: Column(
        mainAxisAlignment: MainAxisAlignment.spaceAround,
        children: [
          FittedBox(
            child: Text(
              title,
              style: controller.theme.appTextTheme.txt32grey,
            ),
          ),
          description,
          Row(
            mainAxisAlignment: MainAxisAlignment.spaceAround,
            children: [
              Container(
                width: controller.size.width * 0.3,
                height: controller.size.height * 0.04,
                decoration: BoxDecoration(
                    color: controller.theme.appColorTheme.greyButtonInsideColor
                        .withOpacity(0.4),
                    borderRadius: BorderRadius.circular(15),
                    boxShadow: [controller.theme.appColorTheme.shadowMild]),
                child: Material(
                  color: Colors.transparent,
                  child: InkWell(
                    borderRadius: BorderRadius.circular(15),
                    onTap: () {
                      onNegetive();
                    },
                    child: Container(
                      alignment: Alignment.center,
                      width: double.infinity,
                      height: double.infinity,
                      child: Text(
                        negetive,
                        style: controller.theme.appTextTheme.txt12white,
                      ),
                    ),
                  ),
                ),
              ),
              Container(
                width: controller.size.width * 0.3,
                height: controller.size.height * 0.04,
                decoration: BoxDecoration(
                    color: controller.theme.appColorTheme.color3,
                    borderRadius: BorderRadius.circular(15),
                    boxShadow: [controller.theme.appColorTheme.shadowMild]),
                child: Material(
                  color: Colors.transparent,
                  child: InkWell(
                    borderRadius: BorderRadius.circular(15),
                    onTap: () {
                      onPositive();
                    },
                    child: Container(
                      alignment: Alignment.center,
                      width: double.infinity,
                      height: double.infinity,
                      child: Text(
                        positive,
                        style: controller.theme.appTextTheme.txt12white,
                      ),
                    ),
                  ),
                ),
              ),
            ],
          )
        ],
      ),
    ),
  );
}
