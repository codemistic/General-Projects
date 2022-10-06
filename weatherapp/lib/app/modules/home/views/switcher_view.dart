import 'package:flutter/material.dart';

import 'package:get/get.dart';
import 'package:epic_weather/app/modules/home/controllers/home_controller.dart';

class SwitcherView extends GetView<HomeController> {
  @override
  Widget build(BuildContext context) {
    return GetBuilder<HomeController>(
        init: controller,
        builder: (controller) {
          return Container(
              child: Column(
            children: [
              Row(
                children: [
                  Spacer(),
                  Container(
                    alignment: Alignment.center,
                    child: Material(
                      color: Colors.transparent,
                      child: InkWell(
                        onTap: () {
                          controller.changeSwitcherState(true);
                        },
                        child: Column(
                          children: [
                            Container(
                              height: 20,
                              padding: EdgeInsets.only(top: 10),
                              child: Text(
                                "Today",
                                textAlign: TextAlign.center,
                                style: controller.theme.appTextTheme.txt12white
                                    .copyWith(
                                        color: controller.theme.appColorTheme
                                            .greyButtonInsideColor),
                              ),
                            ),
                            SizedBox(
                              height: 5,
                            ),
                            Container(
                              width: controller.size.width / 3.5,
                              height: 5,
                              color: controller.switcherState
                                  ? controller.theme.appColorTheme.primaryColor
                                  : controller.theme.appColorTheme.graphColor,
                            ),
                          ],
                        ),
                      ),
                    ),
                  ),
                  Container(
                    alignment: Alignment.center,
                    child: Material(
                      color: Colors.transparent,
                      child: InkWell(
                        onTap: () {
                          controller.changeSwitcherState(false);
                        },
                        child: Column(
                          children: [
                            Container(
                              height: 20,
                              padding: EdgeInsets.only(top: 10),
                              child: Text(
                                "Tommorrow",
                                textAlign: TextAlign.center,
                                style: controller.theme.appTextTheme.txt12white
                                    .copyWith(
                                        color: controller.theme.appColorTheme
                                            .greyButtonInsideColor),
                              ),
                            ),
                            SizedBox(
                              height: 5,
                            ),
                            Container(
                              width: controller.size.width / 3.5,
                              height: 5,
                              color: !controller.switcherState
                                  ? controller.theme.appColorTheme.primaryColor
                                  : controller.theme.appColorTheme.graphColor,
                            ),
                          ],
                        ),
                      ),
                    ),
                  ),
                  Spacer()
                ],
              ),
            ],
          ));
        });
  }
}
