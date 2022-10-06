import 'package:flutter/material.dart';
import 'package:flutter_svg/flutter_svg.dart';
import 'package:epic_weather/app/data/models/location_model.dart';
import 'package:epic_weather/app/modules/location_select/controllers/location_select_controller.dart';
import 'package:epic_weather/app/theme/app_theme.dart';
import 'package:cached_network_image/cached_network_image.dart';
import 'package:epic_weather/app/utils/connectivity.dart';

class LocationViewComponents {
  late Size size;
  late AppTheme theme;
  LocationViewComponents({required Size size, required AppTheme theme}) {
    this.size = size;
    this.theme = theme;
  }

  Widget buildAppbar(
      {required double offset,
      required FocusNode node,
      required Function onClickBack,
      required Function onTextChanged,
      required Function onLocationIconClicked,
      required LocationSelectController controller}) {
    return Container(
      margin: EdgeInsets.only(top: size.height * 0.04),
      child: Row(children: [
        this.greyBackButton(onClick: onClickBack, offset: offset),
        this.searchBar(
            node: node,
            onLocationIconClicked: onLocationIconClicked,
            offset: offset,
            controller: controller,
            onTextChanged: onTextChanged)
      ]),
    );
  }

  Widget greyBackButton({
    required Function onClick,
    required double offset,
  }) {
    return Container(
      decoration: BoxDecoration(
        boxShadow: offset > 100 ? [theme.appColorTheme.shadowMild] : null,
      ),
      margin: EdgeInsets.all(10),
      child: Material(
        color: theme.appColorTheme.colorBackground != 0xFF212121
            ? Color.fromRGBO(
                235 + (offset / 100).toInt() * 20,
                235 + (offset / 100).toInt() * 20,
                235 + (offset / 100).toInt() * 20,
                offset + 40 > 100 ? 1 : (offset + 40) / 100)
            : Color.fromRGBO(
                50 + (offset / 100).toInt() * 20,
                50 + (offset / 100).toInt() * 20,
                50 + (offset / 100).toInt() * 20,
                offset + 40 > 100 ? 1 : (offset + 40) / 100),
        borderRadius: BorderRadius.circular(10),
        child: InkWell(
          borderRadius: BorderRadius.circular(10),
          onTap: () => onClick(),
          child: Container(
            width: 50,
            height: 50,
            child: Icon(
              Icons.arrow_back_rounded,
              color: theme.appColorTheme.greyButtonInsideColor,
            ),
          ),
        ),
      ),
    );
  }

  Widget searchBar(
      {required double offset,
      required FocusNode node,
      required Function onLocationIconClicked,
      required LocationSelectController controller,
      required Function onTextChanged}) {
    return Expanded(
      child: Container(
        margin: EdgeInsets.only(right: 10),
        height: 50,
        width: size.width * 0.8,
        decoration: BoxDecoration(
            boxShadow: offset > 100 ? [theme.appColorTheme.shadowMild] : null,
            color: theme.appColorTheme.colorBackground != 0xFF212121
                ? Color.fromRGBO(
                    235 + (offset / 100).toInt() * 20,
                    235 + (offset / 100).toInt() * 20,
                    235 + (offset / 100).toInt() * 20,
                    offset + 40 > 100 ? 1 : (offset + 40) / 100)
                : Color.fromRGBO(
                    50 + (offset / 100).toInt() * 20,
                    50 + (offset / 100).toInt() * 20,
                    50 + (offset / 100).toInt() * 20,
                    offset + 40 > 100 ? 1 : (offset + 40) / 100),
            borderRadius: BorderRadius.circular(10)),
        child: Row(
          children: [
            ConstrainedBox(
              constraints: BoxConstraints(minWidth: 48, maxWidth: 200),
              child: IntrinsicWidth(
                child: Padding(
                  padding: EdgeInsets.only(left: 10),
                  child: TextField(
                    focusNode: node,
                    onTap: () {},
                    controller: controller.searchTextConroller,
                    onChanged: (value) => onTextChanged(value),
                    style: theme.appTextTheme.txt18grey,
                    decoration: InputDecoration(
                        isCollapsed: true,
                        border: InputBorder.none,
                        hintText: "Add Location",
                        hintStyle: theme.appTextTheme.txt18grey),
                  ),
                ),
              ),
            ),
            Spacer(),
            Container(
              margin: EdgeInsets.all(10),
              child: Material(
                color: Colors.transparent,
                child: InkWell(
                  borderRadius: BorderRadius.circular(10),
                  onTap: () {
                    onLocationIconClicked();
                  },
                  child: Container(
                    width: 30,
                    height: 30,
                    child: Icon(
                      Icons.location_on_outlined,
                      color: theme.appColorTheme.greyButtonInsideColor,
                    ),
                  ),
                ),
              ),
            )
          ],
        ),
      ),
    );
  }

  Widget locationBuilder(
      {required int currLocCount,
      required Location location,
      required Future isOnline,
      required bool isCelcius,
      bool isCurr = true,
      required int count,
      required int currLoc,
      required Function onClick,
      required Function onLongPress}) {
    return Container(
      margin: currLocCount == 0 && isCurr
          ? EdgeInsets.only(top: 0, left: 10, right: 10, bottom: 5)
          : EdgeInsets.symmetric(horizontal: 10, vertical: 5),
      color: Colors.transparent,
      child: Column(
        crossAxisAlignment: CrossAxisAlignment.start,
        children: [
          currLocCount == currLoc && isCurr
              ? Container(
                  margin: EdgeInsets.only(bottom: 20, left: 10),
                  child: Text(
                    "Current Location",
                    style: theme.appTextTheme.txt18grey,
                  ),
                )
              : currLocCount == 0 && count > 1
                  ? Container(
                      margin: EdgeInsets.only(bottom: 20, left: 10),
                      child: Text(
                        "Recent Locations",
                        style: theme.appTextTheme.txt18grey,
                      ),
                    )
                  : Container(),
          currLoc != currLocCount || isCurr
              ? Container(
                  margin: EdgeInsets.all(10),
                  decoration: BoxDecoration(
                      color: theme.appColorTheme.primaryColor,
                      boxShadow: [theme.appColorTheme.shadowMild],
                      borderRadius: BorderRadius.circular(14)),
                  child: Stack(
                    children: [
                      Container(
                        height: size.height * 0.15,
                        width: double.infinity,
                        child: ClipRRect(
                          borderRadius: BorderRadius.circular(14),
                          child: SvgPicture.asset(
                            theme.appSvgImages.getAnImage(currLocCount),
                            fit: BoxFit.cover,
                          ),
                        ),
                      ),
                      Container(
                        width: double.infinity,
                        height: size.height * 0.15,
                        decoration: BoxDecoration(
                            borderRadius: BorderRadius.circular(14),
                            color: theme.appColorTheme.colorBackground ==
                                    0xFF212121
                                ? theme.appColorTheme.colorBackground
                                    .withOpacity(0.22)
                                : Colors.transparent),
                      ),
                      Container(
                        width: double.infinity,
                        height: size.height * 0.15,
                        child: Material(
                          color: Colors.transparent,
                          child: InkWell(
                            splashColor: theme.appColorTheme.primaryColor
                                .withOpacity(0.2),
                            borderRadius: BorderRadius.circular(14),
                            onTap: () {
                              onClick();
                            },
                            onLongPress: () => onLongPress(),
                            child: Container(
                              padding: EdgeInsets.all(20),
                              child: Row(
                                mainAxisAlignment:
                                    MainAxisAlignment.spaceBetween,
                                children: [
                                  Container(
                                    child: FittedBox(
                                      child: Container(
                                        padding: EdgeInsets.only(left: 12),
                                        child: Column(
                                          children: [
                                            Row(
                                              children: [
                                                Text(
                                                  (isCelcius
                                                              ? (location
                                                                      .currentTemperature -
                                                                  273.0)
                                                              : (location.currentTemperature -
                                                                          273.0) *
                                                                      (9 / 5) +
                                                                  32)
                                                          .ceil()
                                                          .toString() +
                                                      "°",
                                                  style: theme
                                                      .appTextTheme.txt40white,
                                                ),
                                                Padding(
                                                  padding: EdgeInsets.only(
                                                      bottom: 10),
                                                  child: Text(
                                                    isCelcius ? "C" : "F",
                                                    style: theme.appTextTheme
                                                        .txt18white,
                                                  ),
                                                )
                                              ],
                                            ),
                                            Image.asset(
                                              theme.appPngImages.getWeatherIcon(
                                                  location.weatherIcon),
                                              height: 60,
                                            )
                                          ],
                                        ),
                                      ),
                                    ),
                                  ),
                                  Spacer(),
                                  Expanded(
                                    child: FittedBox(
                                      child: Column(
                                        crossAxisAlignment:
                                            CrossAxisAlignment.end,
                                        mainAxisAlignment:
                                            MainAxisAlignment.end,
                                        children: [
                                          SizedBox(
                                            height: 50,
                                          ),
                                          FittedBox(
                                            child: Text(
                                              location.cityName,
                                              style:
                                                  theme.appTextTheme.txt32white,
                                            ),
                                          ),
                                          FittedBox(
                                            child: Text(
                                              location.countryName,
                                              style:
                                                  theme.appTextTheme.txt18white,
                                            ),
                                          ),
                                        ],
                                      ),
                                    ),
                                  ),
                                ],
                              ),
                            ),
                          ),
                        ),
                      ),
                    ],
                  ),
                )
              : Container()
        ],
      ),
    );
  }

  Widget locationSelector(LocationSelectController controller, int index,
      {required Function onClick}) {
    return Container(
      margin: EdgeInsets.symmetric(vertical: 20, horizontal: 20),
      child: Column(
        children: [
          Row(
            children: [
              Material(
                color: Colors.transparent,
                child: InkWell(
                  borderRadius: BorderRadius.circular(10),
                  onTap: () => onClick(),
                  child: Container(
                    width: controller.size.width * 0.8,
                    padding: EdgeInsets.symmetric(vertical: 10, horizontal: 8),
                    child: Text(
                      controller.locationList![index].cityName +
                          "," +
                          controller.locationList![index].countryName,
                      style: controller.theme.appTextTheme.txt18grey,
                    ),
                  ),
                ),
              )
            ],
          ),
          Container(
            margin: EdgeInsets.only(top: 8),
            width: double.infinity,
            height: 1,
            color: controller.theme.appColorTheme.greyButtonColor,
          )
        ],
      ),
    );
  }
}
