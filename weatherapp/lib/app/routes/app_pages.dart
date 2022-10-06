import 'package:get/get.dart';

import 'package:epic_weather/app/modules/home/bindings/home_binding.dart';
import 'package:epic_weather/app/modules/home/views/home_view.dart';
import 'package:epic_weather/app/modules/location_select/bindings/location_select_binding.dart';
import 'package:epic_weather/app/modules/location_select/views/location_select_view.dart';

part 'app_routes.dart';

class AppPages {
  static const INITIAL = Routes.HOME;
  static const LOCATION = Routes.LOCATION_SELECT;

  static final routes = [
    GetPage(
      transition: Transition.cupertino,
      transitionDuration: Duration(seconds: 1),
      name: _Paths.HOME,
      page: () => HomeView(),
      binding: HomeBinding(),
    ),
    GetPage(
      transition: Transition.cupertino,
      transitionDuration: Duration(seconds: 1),
      name: _Paths.LOCATION_SELECT,
      page: () => LocationSelectView(),
      binding: LocationSelectBinding(),
    ),
  ];
}
