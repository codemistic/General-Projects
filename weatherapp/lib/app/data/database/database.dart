import 'dart:async';
import 'package:sembast/sembast.dart';
import 'package:sembast/sembast_io.dart';
import 'package:path/path.dart';
import 'package:path_provider/path_provider.dart';
import 'package:epic_weather/app/data/models/location_model.dart';

class AppDatabase {
  static final _singleton = AppDatabase._();
  static AppDatabase get instance => _singleton;

  var _openDbCompleter;

  AppDatabase._();

  Future get database async {
    if (_openDbCompleter == null) {
      _openDbCompleter = Completer();
      final dir = await getApplicationDocumentsDirectory();
      final dbPath = join(dir.path, "location.db");
      final db = await databaseFactoryIo.openDatabase(dbPath);
      _openDbCompleter.complete(db);
    }
    return _openDbCompleter.future;
  }

  Future<Database> get _db async => await AppDatabase.instance.database;

  static const String SETTINGS = 'settings';
  final _settings = intMapStoreFactory.store(SETTINGS);

  Future setSettings(Map<String, dynamic> settings) async {
    int count = await _settings.count(await _db);
    if (count == 0) {
      await _settings.add(await _db, settings);
    } else {
      final finder = Finder(filter: Filter.equals('id', '1'));
      await _settings.update(await _db, settings, finder: finder);
    }
  }

  Future getSettings() async {
    final finder = Finder(filter: Filter.equals('id', '1'));
    return await _settings.findFirst(await _db, finder: finder);
  }

  static const String LOCATION_STORE = 'locations';
  final _location_store = intMapStoreFactory.store(LOCATION_STORE);

  Future getLocation(String locId) async {
    final finder = Finder(filter: Filter.equals('locId', locId));
    final finded = await _location_store.findFirst(await _db, finder: finder);
    return finded != null ? Location.fromDatabase(finded.value) : null;
  }

  Future findLocation(Location location) async {
    final finder = Finder(filter: Filter.equals('locId', location.locId));
    final finded = await _location_store.findFirst(await _db, finder: finder);
    return finded != null ? Location.fromDatabase(finded.value) : null;
  }

  Future updateLocation(Location location) async {
    final finder = Finder(filter: Filter.equals('locId', location.locId));
    await _location_store.update(await _db, location.toDatabase(),
        finder: finder);
  }

  Future<bool> addLocation(Location location) async {
    if ((await findLocation(location)) == null) {
      await _location_store.add(await _db, location.toDatabase());
      return true;
    } else
      return false;
  }

  Future<bool> deleteLocation(Location location) async {
    if ((await findLocation(location)) != null) {
      final finder = Finder(filter: Filter.equals('locId', location.locId));
      await _location_store.delete(await _db, finder: finder);
      return true;
    } else
      return false;
  }

  Future<List<Location>> getAllLocations() async {
    return (await _location_store.find(await _db))
        .toList()
        .map((e) => Location.fromDatabase(e.value))
        .toList();
  }

  Future printAllLocations() async {
    print((await _location_store.find(await _db)).toList());
  }

  Future<bool> clearLocations() async {
    await _location_store.delete(await _db);
    return true;
  }

  Future<int> getLocationCount() async {
    return _location_store.count(await _db);
  }

  Future closeDatabase() async {
    (await _db).close();
  }
}
