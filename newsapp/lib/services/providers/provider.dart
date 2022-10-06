import 'package:flutter_riverpod/flutter_riverpod.dart';
import 'package:newsapp/services/providers/local_storage.dart';

import 'package:newsapp/services/providers/new_api.dart';

import '../../model/article.dart';

final newsProvider = FutureProvider<List<Article>>((ref) async {
  return await ref.read(apiProvider).apiCall();
});

final counterController =
    StateNotifierProvider<AsyncCounterNotifier, AsyncValue<int>>(
  (ref) => AsyncCounterNotifier(
    ref.read,
  ),
);

class AsyncCounterNotifier extends StateNotifier<AsyncValue<int>> {
  AsyncCounterNotifier(this.read) : super(const AsyncLoading()) {
    _init();
  }
  final Reader read;
  void _init() async {
    int value = await read(localStorageProvider).getData();
    state = AsyncData(value);
  }

  void save() async {
    await read(localStorageProvider).saveData();
  }

  void increase() {
    state = const AsyncLoading();
    int value = read(localStorageProvider).increase();
    state = AsyncData(value);
  }
}
