import 'package:geolocator/geolocator.dart';

enum LocatorStatus {
  LOCATION_OFF,
  PERMISSIONS_DISABLED,
  PERMISSIONS_DISABLED_FOREVER,
  CANT_FETCH
}

Future<Position> determinePosition() async {
  bool serviceEnabled;
  LocationPermission permission;

  serviceEnabled = await Geolocator.isLocationServiceEnabled();
  if (!serviceEnabled) {
    return Future.error(LocatorStatus.LOCATION_OFF);
  }

  permission = await Geolocator.checkPermission();
  if (permission == LocationPermission.denied) {
    permission = await Geolocator.requestPermission();
    if (permission == LocationPermission.denied) {
      return Future.error(LocatorStatus.PERMISSIONS_DISABLED);
    }
  }

  if (permission == LocationPermission.deniedForever) {
    return Future.error(LocatorStatus.PERMISSIONS_DISABLED_FOREVER);
  }

  var coordinates, locError;
  await Geolocator.getCurrentPosition(timeLimit: Duration(seconds: 10))
      .then((value) {
    coordinates = value;
  }).onError((error, stackTrace) {
    locError = error;
  });
  if (coordinates != null) {
    return coordinates;
  } else {
    return Future.error(LocatorStatus.CANT_FETCH);
  }
}
