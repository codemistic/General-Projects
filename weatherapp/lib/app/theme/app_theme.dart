import 'package:flutter/material.dart';

class AppTextTheme {
  late TextStyle txt18grey;
  late TextStyle txt18white;
  late TextStyle txt40white;
  late TextStyle txt32white;
  late TextStyle txt32grey;
  late TextStyle txt60white;
  late TextStyle txt12white;
  late TextStyle txt18brown;
  AppTextTheme.lightTheme() {
    this.txt18grey = TextStyle(color: Color(0xFF8F8B8B), fontSize: 18);
    this.txt18white = TextStyle(color: Color(0xFFFFFFFF), fontSize: 18);
    this.txt40white = TextStyle(fontSize: 40, color: Color(0xFFFFFFFF));
    this.txt32white =
        TextStyle(fontSize: 32, color: Color(0xFFFFFFFF), height: 0.4);
    this.txt32grey =
        TextStyle(fontSize: 32, color: Color(0xFF8F8B8B), height: 0.4);
    this.txt60white =
        TextStyle(fontSize: 60, color: Color(0xFFFFFFFF), height: 0.4);
    this.txt12white =
        TextStyle(fontSize: 12, color: Color(0xFFFFFFFF), height: 0.4);
    this.txt18brown =
        TextStyle(fontSize: 18, color: Color(0xFF7B5959), height: 0.4);
  }

  AppTextTheme.darkTheme() {
    this.txt18grey = TextStyle(color: Color(0xFFD6D6D6), fontSize: 18);
    this.txt18white = TextStyle(color: Color(0xFFD6D6D6), fontSize: 18);
    this.txt40white = TextStyle(fontSize: 40, color: Color(0xFFD6D6D6));
    this.txt32white =
        TextStyle(fontSize: 32, color: Color(0xFFFFFFFF), height: 0.4);
    this.txt32grey =
        TextStyle(fontSize: 32, color: Color(0xFFD6D6D6), height: 0.4);
    this.txt60white =
        TextStyle(fontSize: 60, color: Color(0xFFFFFFFF), height: 0.4);
    this.txt12white =
        TextStyle(fontSize: 12, color: Color(0xFFFFFFFF), height: 0.4);
    this.txt18brown =
        TextStyle(fontSize: 18, color: Color(0xFF7B5959), height: 0.4);
  }
}

class AppColorTheme {
  late Color colorBackground;
  late Color primaryColor;
  late Color secondaryColor;
  late Color thirdColor;
  late Color greyButtonColor;
  late Color greyButtonInsideColor;
  late Color color1;
  late Color color2;
  late Color color3;
  late Color graphColor;
  late Color graphBorderColor;
  late Color colorWhite;
  late Color colorBlack;
  late Color shadowColor1;
  late BoxShadow shadowMild;
  late BoxShadow shadowMedium;
  late BoxShadow shadowMediumUp;

  AppColorTheme.darkTheme() {
    graphColor = Color(0xFFFFFFFF).withOpacity(0.2);
    graphBorderColor = Color(0xFFFFFFFF);
    colorBlack = Color(0x90F3F3F3);
    colorBackground = Color(0xFF212121);
    primaryColor = Color(0xFFFFFFFF);
    secondaryColor = Color(0x00000000);
    thirdColor = Color(0xFF565656);
    greyButtonColor = Color(0xFFFFFFFF);
    greyButtonInsideColor = Color(0xFFD6D6D6);
    color1 = Color(0xFF3C3F62);
    color2 = Color(0xFF353641);
    color3 = Color(0xFF4A4D70);
    colorWhite = Color(0xFF565656);
    shadowColor1 = Colors.black.withOpacity(0.2);
    shadowMild = BoxShadow(
        offset: Offset(2, 2),
        blurRadius: 10,
        spreadRadius: 2,
        color: shadowColor1.withOpacity(0.1));
    shadowMedium = BoxShadow(
        offset: Offset(1, 1),
        blurRadius: 2,
        spreadRadius: 2,
        color: shadowColor1);
    shadowMediumUp = BoxShadow(
        offset: Offset(-2, -2),
        blurRadius: 10,
        spreadRadius: 10,
        color: shadowColor1);
  }

  AppColorTheme.lightTheme() {
    graphColor = Color(0xFFACA2C0).withOpacity(0.2);
    graphBorderColor = Color(0xFFACA2C0);
    colorBlack = Color(0xFFFFFFFF);
    colorBackground = Color(0xFFFFFFFF);
    primaryColor = Color(0xFFACA2C0);
    secondaryColor = Color(0xFFFFFFFF);
    thirdColor = Color(0xFFACA2C0);
    greyButtonColor = Color(0xFFEBEBEB);
    greyButtonInsideColor = Color(0xFF8F8B8B);
    color1 = Color(0xFF525893);
    color2 = Color(0xFF535568);
    color3 = Color(0xFF7A7FB9);
    colorWhite = Color(0xFFFFFFFF);
    shadowColor1 = Color(0x20616161);
    shadowMild = BoxShadow(
        offset: Offset(2, 2),
        blurRadius: 10,
        spreadRadius: 2,
        color: shadowColor1.withOpacity(0.04));
    shadowMedium = BoxShadow(
        offset: Offset(1, 1),
        blurRadius: 2,
        spreadRadius: 2,
        color: shadowColor1);
    shadowMediumUp = BoxShadow(
        offset: Offset(-2, -2),
        blurRadius: 10,
        spreadRadius: 10,
        color: shadowColor1);
  }
}

class AppSvgImages {
  var src = "lib/assets/images/svg/";
  var mainVector;
  var droplet;
  var uvi;
  var wind;
  var temp;
  var locSelect;
  var logo;

  AppSvgImages.lightTheme() {
    logo = src + "icons/logo.svg";
    mainVector = src + "vectors/main_page_vector.svg";
    droplet = src + "icons/droplet.svg";
    uvi = src + "icons/uvi.svg";
    wind = src + "icons/wind.svg";
    temp = src + "icons/temp.svg";
    locSelect = src + "vectors/location_select.svg";
  }

  AppSvgImages.darkTheme() {
    logo = src + "icons/logo.svg";
    mainVector = src + "vectors/main_page_vector_dark.svg";
    droplet = src + "icons/droplet.svg";
    uvi = src + "icons/uvi.svg";
    wind = src + "icons/wind.svg";
    temp = src + "icons/temp.svg";
    locSelect = src + "vectors/location_select.svg";
  }

  String getAnImage(int index) {
    if (0 <= index)
      return src + "images/" + ((index % 8) + 1).toString() + ".svg";
    else
      return src + "images/1.svg";
  }
}

class AppPngImages {
  var src = "lib/assets/images/png/";

  String getWeatherIcon(String weatherIcon) {
    return (src + "weather_icons/" + weatherIcon + "@2x.png");
  }
}

class AppTheme {
  late AppTextTheme appTextTheme;
  late AppColorTheme appColorTheme;
  late AppSvgImages appSvgImages;
  late AppPngImages appPngImages;
  AppTheme.lightTheme() {
    appSvgImages = AppSvgImages.lightTheme();
    appColorTheme = AppColorTheme.lightTheme();
    appTextTheme = AppTextTheme.lightTheme();
    appPngImages = AppPngImages();
  }
  AppTheme.darkTheme() {
    appSvgImages = AppSvgImages.darkTheme();
    appTextTheme = AppTextTheme.darkTheme();
    appColorTheme = AppColorTheme.darkTheme();
    appPngImages = AppPngImages();
  }
}
