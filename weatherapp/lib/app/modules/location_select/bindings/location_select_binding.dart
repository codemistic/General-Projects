import 'package:get/get.dart';

import '../controllers/location_select_controller.dart';

class LocationSelectBinding extends Bindings {
  @override
  void dependencies() {
    Get.lazyPut<LocationSelectController>(
      () => LocationSelectController(),
    );
  }
}
