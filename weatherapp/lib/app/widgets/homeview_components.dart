import 'package:flutter/material.dart';
import 'package:flutter_svg/svg.dart';
import 'package:epic_weather/app/modules/home/controllers/home_controller.dart';
import 'package:epic_weather/app/theme/app_theme.dart';

class HomeViewComponents {
  Widget menuButton(
      {required Function onClick, required icon, required color, shadow}) {
    return Container(
      margin: EdgeInsets.all(10),
      decoration: BoxDecoration(
          borderRadius: BorderRadius.circular(10),
          color: color,
          boxShadow: [shadow ?? BoxShadow(color: Colors.transparent)]),
      child: Material(
        color: Colors.transparent,
        borderRadius: BorderRadius.circular(10),
        child: InkWell(
          borderRadius: BorderRadius.circular(10),
          onTap: () {
            onClick();
          },
          child: Container(
            width: 50,
            height: 50,
            child: icon,
          ),
        ),
      ),
    );
  }

  Widget squareButton(
      {required Color color,
      required HomeController controller,
      required String title,
      required icon,
      required String value,
      required String unit}) {
    return FittedBox(
      child: Container(
        margin: EdgeInsets.all(5),
        decoration: BoxDecoration(
            color: color,
            borderRadius: BorderRadius.circular(14),
            boxShadow: [controller.theme.appColorTheme.shadowMedium]),
        child: Material(
          color: Colors.transparent,
          child: InkWell(
            borderRadius: BorderRadius.circular(14),
            onTap: () {},
            child: Container(
              padding: EdgeInsets.symmetric(vertical: 17, horizontal: 8),
              child: Column(
                mainAxisAlignment: MainAxisAlignment.center,
                crossAxisAlignment: CrossAxisAlignment.center,
                children: [
                  Text(
                    title,
                    style: controller.theme.appTextTheme.txt12white,
                  ),
                  SizedBox(
                    height: 6,
                  ),
                  Row(
                    children: [
                      SvgPicture.asset(icon),
                      SizedBox(
                        width: 5,
                      ),
                      Text(
                        value,
                        style: controller.theme.appTextTheme.txt18white,
                      ),
                      Text(
                        unit,
                        style: controller.theme.appTextTheme.txt12white
                            .copyWith(fontSize: 8),
                        textAlign: TextAlign.center,
                      ),
                    ],
                  )
                ],
              ),
            ),
          ),
        ),
      ),
    );
  }

  Widget locationBuilder({
    required int index,
    required data,
    required Function onClick,
    required HomeController controller,
  }) {
    return Column(children: [
      FittedBox(
        child: Container(
            margin: EdgeInsets.all(5),
            width: controller.size.width / 3.5,
            height: controller.size.height / 15,
            decoration: BoxDecoration(
                color: controller.theme.appColorTheme.color1,
                borderRadius: BorderRadius.circular(12),
                boxShadow: [controller.theme.appColorTheme.shadowMedium]),
            child: Stack(
              children: [
                Container(
                  child: ClipRRect(
                    borderRadius: BorderRadius.circular(12),
                    child: SvgPicture.asset(
                      controller.theme.appSvgImages.getAnImage(index),
                      fit: BoxFit.cover,
                    ),
                  ),
                ),
                Container(
                  decoration: BoxDecoration(
                      borderRadius: BorderRadius.circular(14),
                      color: controller
                                  .theme.appColorTheme.colorBackground.value ==
                              0xFF212121
                          ? controller.theme.appColorTheme.colorBackground
                              .withOpacity(0.3)
                          : Colors.black.withOpacity(0.06)),
                ),
                Material(
                  color: Colors.transparent,
                  child: InkWell(
                    borderRadius: BorderRadius.circular(12),
                    onTap: () => onClick(),
                    child: Container(
                      width: double.infinity,
                      height: double.infinity,
                      child: Container(
                        padding: EdgeInsets.only(left: 10, top: 20),
                        child: Column(
                          crossAxisAlignment: CrossAxisAlignment.start,
                          mainAxisAlignment: MainAxisAlignment.start,
                          children: [
                            Text(
                              data[index].cityName,
                              style: controller.theme.appTextTheme.txt12white,
                            ),
                            SizedBox(
                              height: 8,
                            ),
                            Text(
                              data[index].countryName,
                              style: controller.theme.appTextTheme.txt12white
                                  .copyWith(color: Colors.white30, fontSize: 8),
                            ),
                          ],
                        ),
                      ),
                    ),
                  ),
                )
              ],
            )),
      ),
    ]);
  }

  Widget menuItem(
      {required String title,
      required Function onClick,
      required icon,
      required HomeController controller}) {
    return Container(
      margin: EdgeInsets.only(left: controller.size.width * 0.03),
      decoration: BoxDecoration(
          borderRadius: BorderRadius.circular(10),
          boxShadow: [controller.theme.appColorTheme.shadowMedium],
          color: controller.theme.appColorTheme.colorWhite),
      child: Material(
        color: Colors.transparent,
        child: InkWell(
          borderRadius: BorderRadius.circular(10),
          onTap: () => onClick(),
          child: Padding(
              padding: EdgeInsets.only(top: 10, bottom: 9, left: 20, right: 20),
              child: Row(
                children: [
                  Container(
                    padding: EdgeInsets.only(right: 10, bottom: 0),
                    child: Icon(
                      icon,
                      color: controller
                          .theme.appColorTheme.greyButtonInsideColor
                          .withOpacity(0.5),
                      size: 20,
                    ),
                  ),
                  Text(
                    title,
                    style: controller.theme.appTextTheme.txt18grey,
                  ),
                ],
              )),
        ),
      ),
    );
  }

  Widget settingsMenu({
    required HomeController controller,
  }) {
    return Container(
      alignment: Alignment.center,
      color: Colors.black12,
      child: Container(
        padding: EdgeInsets.symmetric(horizontal: 30, vertical: 20),
        width: controller.size.width * 0.8,
        height: controller.size.height * 0.4,
        decoration: BoxDecoration(
            color: controller.theme.appColorTheme.colorBackground,
            borderRadius: BorderRadius.circular(15),
            boxShadow: [controller.theme.appColorTheme.shadowMild]),
        child: Column(
          mainAxisAlignment: MainAxisAlignment.spaceAround,
          children: [
            FittedBox(
              child: Text(
                "Settings",
                style: controller.theme.appTextTheme.txt32grey,
              ),
            ),
            FittedBox(
              child: Column(
                children: [
                  Row(
                    mainAxisAlignment: MainAxisAlignment.spaceAround,
                    children: [
                      Text(
                        "Temperature Unit",
                        style: controller.theme.appTextTheme.txt18grey,
                      ),
                      Row(
                        children: [
                          Radio(
                              activeColor: controller
                                  .theme.appColorTheme.graphBorderColor,
                              value: "degree",
                              groupValue: controller.appSettings.isCelciuis
                                  ? "degree"
                                  : "farenheit",
                              onChanged: (value) {
                                controller.appSettings.isCelciuis = true;
                                controller.update();
                              }),
                          Text(
                            "°C",
                            style: controller.theme.appTextTheme.txt18grey
                                .copyWith(fontSize: 14),
                          ),
                        ],
                      ),
                      Row(
                        children: [
                          Radio(
                              activeColor: controller
                                  .theme.appColorTheme.graphBorderColor,
                              value: "farenheit",
                              groupValue: controller.appSettings.isCelciuis
                                  ? "degree"
                                  : "farenheit",
                              onChanged: (value) {
                                controller.appSettings.isCelciuis = false;
                                controller.update();
                              }),
                          Text(
                            "°F",
                            style: controller.theme.appTextTheme.txt18grey
                                .copyWith(fontSize: 14),
                          ),
                        ],
                      )
                    ],
                  ),
                  Row(
                    mainAxisAlignment: MainAxisAlignment.spaceAround,
                    children: [
                      Text(
                        "Theme",
                        style: controller.theme.appTextTheme.txt18grey,
                        textAlign: TextAlign.left,
                      ),
                      SizedBox(
                        width: 30,
                      ),
                      DropdownButton<String>(
                        dropdownColor:
                            controller.theme.appColorTheme.colorBackground,
                        icon: Icon(
                          Icons.brightness_medium_rounded,
                          color: controller
                              .theme.appColorTheme.greyButtonInsideColor,
                        ),
                        underline: Container(),
                        value: controller.appSettings.isdefaultTheme
                            ? "sys_def"
                            : controller.appSettings.isDarkMode
                                ? "dark"
                                : "light",
                        items: [
                          DropdownMenuItem(
                            child: Text(
                              "Light",
                              style: controller.theme.appTextTheme.txt18grey,
                            ),
                            value: "light",
                          ),
                          DropdownMenuItem(
                            child: Text(
                              "Dark",
                              style: controller.theme.appTextTheme.txt18grey,
                            ),
                            value: "dark",
                          ),
                          DropdownMenuItem(
                              child: Text(
                                "System Default",
                                style: controller.theme.appTextTheme.txt18grey,
                              ),
                              value: "sys_def"),
                        ],
                        onChanged: (value) {
                          if (value == "light") {
                            controller.appSettings.isDarkMode = false;
                            controller.appSettings.isdefaultTheme = false;
                          } else if (value == "dark") {
                            controller.appSettings.isDarkMode = true;
                            controller.appSettings.isdefaultTheme = false;
                          } else {
                            controller.appSettings.isDarkMode = false;
                            controller.appSettings.isdefaultTheme = true;
                          }
                          controller.setTheme();
                        },
                      )
                    ],
                  ),
                  Row(
                    mainAxisAlignment: MainAxisAlignment.spaceAround,
                    children: [
                      Text(
                        "Weather Updates",
                        style: controller.theme.appTextTheme.txt18grey,
                        textAlign: TextAlign.left,
                      ),
                      Switch(
                          activeColor:
                              controller.theme.appColorTheme.graphBorderColor,
                          value: controller.appSettings.weatherUpdate,
                          onChanged: (val) =>
                              controller.onWeatherAlertClicked(val)),
                      controller.appSettings.weatherUpdate
                          ? DropdownButton<int>(
                              dropdownColor: controller
                                  .theme.appColorTheme.colorBackground,
                              underline: Container(),
                              value: controller.appSettings.updateTime,
                              items: [
                                DropdownMenuItem(
                                  child: Text(
                                    "every 2 hours",
                                    style:
                                        controller.theme.appTextTheme.txt18grey,
                                  ),
                                  value: 2,
                                ),
                                DropdownMenuItem(
                                  child: Text(
                                    "every 6 hours",
                                    style:
                                        controller.theme.appTextTheme.txt18grey,
                                  ),
                                  value: 6,
                                ),
                                DropdownMenuItem(
                                    child: Text(
                                      "every 12 hours",
                                      style: controller
                                          .theme.appTextTheme.txt18grey,
                                    ),
                                    value: 12),
                              ],
                              onChanged: (value) {
                                controller.appSettings.updateTime = value ?? 2;
                                controller.update();
                              },
                            )
                          : Container()
                    ],
                  )
                ],
              ),
            ),
            Row(
              mainAxisAlignment: MainAxisAlignment.spaceBetween,
              children: [
                Container(
                  width: controller.size.width * 0.3,
                  height: controller.size.height * 0.04,
                  decoration: BoxDecoration(
                      color: controller
                          .theme.appColorTheme.greyButtonInsideColor
                          .withOpacity(0.4),
                      borderRadius: BorderRadius.circular(15),
                      boxShadow: [controller.theme.appColorTheme.shadowMild]),
                  child: Material(
                    color: Colors.transparent,
                    child: InkWell(
                      borderRadius: BorderRadius.circular(15),
                      onTap: () {
                        controller.settingsBackClicked();
                      },
                      child: Container(
                        alignment: Alignment.center,
                        width: double.infinity,
                        height: double.infinity,
                        child: Text(
                          "Cancel",
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
                        controller.onSettingsSaveClicked();
                        controller.settingsBackClicked();
                      },
                      child: Container(
                        alignment: Alignment.center,
                        width: double.infinity,
                        height: double.infinity,
                        child: Text(
                          "Save",
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
}
