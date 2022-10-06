import 'package:flutter/material.dart';
import 'package:get/get.dart';
import 'package:epic_weather/app/modules/home/controllers/home_controller.dart';
import 'package:epic_weather/app/modules/home/views/period_chooser_view.dart';
import 'package:epic_weather/app/modules/home/views/switcher_view.dart';

class ForeGroundDownView extends GetView<HomeController> {
  @override
  Widget build(BuildContext context) {
    return GetBuilder<HomeController>(
        init: controller,
        builder: (controller) {
          var chart = controller.chart;
          return Container(
            color: Colors.transparent,
            child: Column(children: [
              Container(
                padding: EdgeInsets.only(left: controller.size.width * 0.01),
                child: Row(
                  mainAxisAlignment: MainAxisAlignment.start,
                  children: [
                    controller.components.squareButton(
                        controller: controller,
                        title: "Uv index",
                        icon: controller.theme.appSvgImages.uvi,
                        value: ((controller.switcherState
                                ? controller.data.uvi
                                : controller.data.tommorrowData.uvi))
                            .ceilToDouble()
                            .toString(),
                        unit: "mW/sqm",
                        color: controller.theme.appColorTheme.color1),
                    controller.components.squareButton(
                        controller: controller,
                        title: "Wind",
                        icon: controller.theme.appSvgImages.wind,
                        value: controller.switcherState
                            ? controller.data.currentWind.toString()
                            : controller.data.tommorrowData.wind.toString(),
                        unit: "km/h",
                        color: controller.theme.appColorTheme.color2),
                    controller.components.squareButton(
                        controller: controller,
                        title: "Humidity",
                        icon: controller.theme.appSvgImages.droplet,
                        value: controller.switcherState
                            ? controller.data.currentHumidity.toString()
                            : controller.data.tommorrowData.humidity.toString(),
                        unit: "g.m",
                        color: controller.theme.appColorTheme.color3),
                  ],
                ),
              ),
              Container(
                margin: EdgeInsets.only(top: 10),
                height: controller.locations.length > 1
                    ? (controller.size.aspectRatio < 0.7
                        ? controller.size.height *
                            controller.size.height *
                            (Get.context!.textScaleFactor > 1.0
                                ? 0.0003
                                : 0.00033)
                        : controller.size.height * 0.27)
                    : controller.size.height *
                        controller.size.height *
                        (Get.context!.textScaleFactor > 1.0
                            ? 0.00043
                            : 0.00046),
                child: Row(
                  children: [
                    Expanded(child: chart),
                    FittedBox(
                        child: controller.components.squareButton(
                            controller: controller,
                            title: "Highest Temperature",
                            icon: controller.theme.appSvgImages.temp,
                            value: (controller.appSettings.isCelciuis
                                    ? (controller.highestTemperature - 273)
                                    : (controller.highestTemperature - 273) *
                                            (9 / 5) +
                                        32)
                                .ceilToDouble()
                                .toString(),
                            unit:
                                controller.appSettings.isCelciuis ? "°C" : "°F",
                            color: controller.theme.appColorTheme.thirdColor)),
                  ],
                ),
              ),
              Container(
                  alignment: Alignment.centerLeft, child: PeriodChooserView()),
              controller.locations.length > 1
                  ? Container(
                      margin: EdgeInsets.only(
                          left: 10,
                          top: controller.size.height / 40,
                          bottom: controller.size.height / 100),
                      alignment: Alignment.centerLeft,
                      child: Text(
                        "Recent Locations",
                        style: controller.theme.appTextTheme.txt12white
                            .copyWith(
                                color: controller
                                    .theme.appColorTheme.greyButtonInsideColor),
                      ),
                    )
                  : Container(),
              controller.locations.length > 1
                  ? Container(
                      width: double.infinity,
                      height: controller.size.height * 0.07,
                      child: ListView.builder(
                        physics: BouncingScrollPhysics(),
                        scrollDirection: Axis.horizontal,
                        itemBuilder: (context, index) {
                          return controller.locations[index].locId !=
                                  controller.currentLocation
                              ? FittedBox(
                                  child: controller.components.locationBuilder(
                                  controller: controller,
                                  onClick: () =>
                                      controller.onLocationClicked(index),
                                  data: controller.locations,
                                  index: index,
                                ))
                              : Container();
                        },
                        itemCount: controller.locations.length,
                      ),
                    )
                  : Container(),
              Container(
                margin: EdgeInsets.only(top: 2),
                child: SwitcherView(),
              )
            ]),
          );
        });
  }
}
