import 'package:flutter_riverpod/flutter_riverpod.dart';
import 'package:shared_preferences/shared_preferences.dart';

final localStorageProvider = Provider(
  (ref) => LocalStorage(),
);

class LocalStorage {
  int value = 0;
  Future<void> saveData() async {
    final pref = await SharedPreferences.getInstance();
    pref.setInt('score', value);
  }

  Future<int> getData() async {
    final pref = await SharedPreferences.getInstance();
    value = pref.getInt('score') ?? 0;
    return value;
  }

  int increase() => value += 1;
}
