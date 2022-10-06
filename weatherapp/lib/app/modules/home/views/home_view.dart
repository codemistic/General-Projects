import 'dart:ui';
import 'package:flutter/material.dart';
import 'package:flutter_svg/flutter_svg.dart';
import 'package:get/get.dart';
import 'package:epic_weather/app/modules/home/views/fore_ground_down_view.dart';
import 'package:epic_weather/app/modules/home/views/fore_ground_up_view.dart';
import 'package:epic_weather/app/routes/app_pages.dart';

import '../controllers/home_controller.dart';

class HomeView extends GetView<HomeController> {
  @override
  Widget build(BuildContext context) {
    return Scaffold(
        body: GetBuilder<HomeController>(
            init: controller,
            builder: (controller) {
              return GestureDetector(
                onTap: () {
                  if (controller.isDrawerOpen) controller.closeDrawer();
                },
                child: Container(
                  color: controller.theme.appColorTheme.colorBackground,
                  child: Stack(
                    clipBehavior: Clip.hardEdge,
                    children: [
                      Container(
                        margin: EdgeInsets.only(top: 50, left: 10),
                        child: Column(
                          crossAxisAlignment: CrossAxisAlignment.start,
                          children: [
                            controller.components.menuButton(
                                onClick: () {
                                  controller.closeDrawer();
                                },
                                shadow: controller.theme.appColorTheme.shadowMedium,
                                icon: Icon(
                                  Icons.menu_open_rounded,
                                  color: controller.theme.appColorTheme.greyButtonInsideColor,
                                ),
                                color: controller.theme.appColorTheme.colorWhite),
                            SizedBox(
                              height: controller.size.height * 0.1,
                            ),
                            controller.components.menuItem(
                                controller: controller,
                                title: "Location",
                                onClick: () {
                                  controller.onLocationPageClicked();
                                },
                                icon: Icons.location_on_rounded),
                            SizedBox(
                              height: controller.size.height * 0.03,
                            ),
                            controller.components.menuItem(
                                controller: controller,
                                title: "Settings",
                                onClick: () => controller.settingsOptionClicked(),
                                icon: Icons.settings),
                            SizedBox(
                              height: controller.size.height * 0.03,
                            ),
                            controller.components.menuItem(
                                controller: controller,
                                title: "App Info",
                                onClick: () => controller.onAppInfoClicked(),
                                icon: Icons.info_rounded),
                          ],
                        ),
                      ),
                      Container(
                        padding: EdgeInsets.only(top: 50),
                      ),
                      AnimatedPositioned(
                        duration: Duration(milliseconds: 200),
                        left: controller.isDrawerOpen ? 200 : 0,
                        top: controller.isDrawerOpen ? 50 : 0,
                        right: controller.isDrawerOpen ? -200 : 0,
                        bottom: controller.isDrawerOpen ? -50 : 0,
                        child: AbsorbPointer(
                            absorbing: controller.isDrawerOpen,
                            child: Container(
                                decoration: BoxDecoration(
                                    borderRadius: BorderRadius.circular(20),
                                    color: controller.theme.appColorTheme.colorBackground,
                                    boxShadow: [controller.theme.appColorTheme.shadowMediumUp]),
                                child: !controller.loadingState
                                    ? Stack(
                                        clipBehavior: Clip.hardEdge,
                                        children: [
                                          Container(
                                            decoration: BoxDecoration(
                                              color: controller.theme.appColorTheme.colorBackground,
                                              borderRadius: BorderRadius.circular(20),
                                            ),
                                          ),
                                          Container(
                                              decoration: BoxDecoration(
                                                  borderRadius: BorderRadius.circular(20)),
                                              height: controller.size.height / 1.6,
                                              child: Stack(
                                                clipBehavior: Clip.hardEdge,
                                                children: [
                                                  AnimatedContainer(
                                                      duration: Duration(milliseconds: 200),
                                                      decoration: BoxDecoration(
                                                          color: controller
                                                              .theme.appColorTheme.graphColor,
                                                          borderRadius: BorderRadius.circular(20)),
                                                      height: controller.size.height / 1.6,
                                                      child: ClipRRect(
                                                        borderRadius: controller.isDrawerOpen
                                                            ? BorderRadius.circular(20)
                                                            : BorderRadius.zero,
                                                        child: SvgPicture.asset(
                                                          controller.theme.appSvgImages.getAnImage(
                                                              controller
                                                                  .appSettings.currentLocation),
                                                          fit: BoxFit.cover,
                                                          width: controller.size.width,
                                                        ),
                                                      )),
                                                  Container(
                                                    decoration: BoxDecoration(
                                                        borderRadius: controller.isDrawerOpen
                                                            ? BorderRadius.circular(14)
                                                            : BorderRadius.zero,
                                                        color: controller.theme.appColorTheme
                                                                    .colorBackground ==
                                                                0xFF212121
                                                            ? controller
                                                                .theme.appColorTheme.colorBackground
                                                                .withOpacity(0.3)
                                                            : Colors.black.withOpacity(0.06)),
                                                  ),
                                                  ForeGroundUpView(),
                                                ],
                                              )),
                                          Container(
                                            decoration: BoxDecoration(
                                                borderRadius: BorderRadius.circular(20)),
                                            child: Stack(
                                                // overflow: Overflow.clip,
                                                children: [
                                                  Container(
                                                    margin: EdgeInsets.only(
                                                        top: controller.size.height / 4),
                                                    child: SvgPicture.asset(
                                                      controller.theme.appSvgImages.mainVector,
                                                      fit: BoxFit.fill,
                                                      width: controller.size.width,
                                                    ),
                                                  ),
                                                  Column(
                                                    children: [
                                                      SizedBox(
                                                        height: controller.size.height / 2.4,
                                                      ),
                                                      ForeGroundDownView()
                                                    ],
                                                  ),
                                                ]),
                                          ),
                                          AnimatedContainer(
                                              duration: Duration(milliseconds: 200),
                                              margin: EdgeInsets.only(
                                                  top: controller.size.height * 0.04),
                                              child: controller.isDrawerOpen
                                                  ? Container()
                                                  : Column(children: [
                                                      controller.components.menuButton(
                                                          onClick: () {
                                                            controller.openDrawer();
                                                          },
                                                          color: Colors.transparent,
                                                          icon: Icon(
                                                            Icons.menu_rounded,
                                                            color: controller
                                                                .theme.appColorTheme.colorBlack,
                                                          )),
                                                      controller.components.menuButton(
                                                          onClick: () {
                                                            controller.onRefresh();
                                                          },
                                                          color: Colors.transparent,
                                                          icon: Icon(
                                                            Icons.refresh_rounded,
                                                            color: controller
                                                                .theme.appColorTheme.colorBlack,
                                                          )),
                                                    ])),
                                          ClipRRect(
                                            borderRadius: BorderRadius.circular(20),
                                            child: Container(
                                                child: controller.isDrawerOpen
                                                    ? BackdropFilter(
                                                        filter: ImageFilter.blur(
                                                            sigmaX: 1.0, sigmaY: 1.0),
                                                        child: Container(
                                                            width: controller.size.width,
                                                            height: controller.size.height,
                                                            color: Colors.transparent),
                                                      )
                                                    : Container()),
                                          ),
                                          AnimatedOpacity(
                                              opacity: controller.isSettingsOpen ? 1.0 : 0.0,
                                              duration: Duration(milliseconds: 500),
                                              child: controller.isSettingsOpen
                                                  ? controller.components
                                                      .settingsMenu(controller: controller)
                                                  : Container()),
                                        ],
                                      )
                                    : Container(
                                        alignment: Alignment.center,
                                        child: RefreshProgressIndicator(
                                          backgroundColor:
                                              controller.theme.appColorTheme.colorBackground,
                                        ),
                                      ))),
                      ),
                    ],
                  ),
                ),
              );
            }));
  }
}
