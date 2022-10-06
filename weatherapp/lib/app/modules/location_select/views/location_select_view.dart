import 'package:flutter/material.dart';
import 'package:flutter_svg/flutter_svg.dart';
import 'package:get/get.dart';
import 'package:epic_weather/app/routes/app_pages.dart';
import 'package:epic_weather/app/theme/app_theme.dart';
import '../controllers/location_select_controller.dart';

class LocationSelectView extends GetView<LocationSelectController> {
  @override
  Widget build(BuildContext context) {
    return Scaffold(
        body: GetBuilder<LocationSelectController>(builder: (controller) {
      return Container(
        color: controller.theme.appColorTheme.colorBackground,
        child: Stack(
          children: [
            !controller.loadingState
                ? !controller.typingState
                    ? controller.locationsAvailable
                        ? Container(
                            margin: EdgeInsets.only(
                                top: controller.size.height * 0.09),
                            child: Scrollbar(
                              controller: controller.scrollController,
                              child: RefreshIndicator(
                                onRefresh: () => controller.onRefresh(),
                                child: ListView(
                                  controller: controller.scrollController,
                                  physics: controller.locations?.length >= 4
                                      ? BouncingScrollPhysics(
                                          parent:
                                              AlwaysScrollableScrollPhysics())
                                      : AlwaysScrollableScrollPhysics(
                                          parent:
                                              AlwaysScrollableScrollPhysics()),
                                  children: [
                                    controller.currentLocation > -1 &&
                                            controller.currentLocation <
                                                controller.locations?.length
                                        ? controller.components.locationBuilder(
                                            isCelcius: controller
                                                .appSettings.isCelciuis,
                                            isOnline: controller.isOnline(),
                                            count: 1,
                                            currLoc: controller.currentLocation,
                                            onLongPress: () =>
                                                controller.deleteLocation(
                                                    controller.currentLocation),
                                            location: controller.locations[
                                                controller.currentLocation],
                                            isCurr: true,
                                            currLocCount:
                                                controller.currentLocation,
                                            onClick: () =>
                                                controller.onLocationClicked(
                                                    controller.currentLocation))
                                        : Container(),
                                    ListView.builder(
                                        scrollDirection: Axis.vertical,
                                        shrinkWrap: true,
                                        itemCount: controller.locations?.length,
                                        physics: ClampingScrollPhysics(),
                                        itemBuilder: (BuildContext context,
                                            int currLocCount) {
                                          return controller.components
                                              .locationBuilder(
                                                  isCelcius: controller
                                                      .appSettings.isCelciuis,
                                                  isOnline:
                                                      controller.isOnline(),
                                                  count: controller
                                                      .locations?.length,
                                                  currLoc: controller
                                                      .currentLocation,
                                                  onLongPress: () =>
                                                      controller.deleteLocation(
                                                          currLocCount),
                                                  location: controller
                                                      .locations[currLocCount],
                                                  currLocCount: currLocCount,
                                                  isCurr: false,
                                                  onClick: () => controller
                                                      .onLocationClicked(
                                                          currLocCount));
                                        })
                                  ],
                                ),
                              ),
                            ))
                        : Container(
                            alignment: Alignment.center,
                            child: Column(
                              children: [
                                Spacer(),
                                SvgPicture.asset(
                                  controller.theme.appSvgImages.locSelect,
                                  alignment: Alignment.center,
                                  width: controller.size.width / 4,
                                  height: controller.size.height / 4,
                                ),
                                SizedBox(
                                  height: controller.size.width / 10,
                                ),
                                FittedBox(
                                  child: Text(
                                    "Please Add a Location",
                                    style:
                                        controller.theme.appTextTheme.txt32grey,
                                  ),
                                ),
                                Spacer()
                              ],
                            ))
                    : Container(
                        color: controller.theme.appColorTheme.colorBackground,
                        margin:
                            EdgeInsets.only(top: controller.size.height * 0.09),
                        child: ListView.builder(
                            physics: BouncingScrollPhysics(),
                            itemCount: controller.locationList == null
                                ? 0
                                : controller.locationList?.length,
                            itemBuilder: (context, index) {
                              return controller.components.locationSelector(
                                  controller, index,
                                  onClick: () => controller.addLocation(index));
                            }),
                      )
                : Container(
                    alignment: Alignment.center,
                    child: RefreshProgressIndicator(
                      backgroundColor:
                          controller.theme.appColorTheme.colorBackground,
                    ),
                  ),
            Container(
              child: controller.components.buildAppbar(
                  node: controller.focusNode,
                  onLocationIconClicked: () => controller.getLocationFromGps(),
                  onTextChanged: (value) =>
                      controller.onSearchBarTextChanged(value),
                  offset: controller.scrollOffset,
                  controller: controller,
                  onClickBack: () => controller.backClicked()),
            ),
          ],
        ),
      );
    }));
  }
}
