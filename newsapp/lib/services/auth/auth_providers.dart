import 'package:firebase_auth/firebase_auth.dart';
import 'package:firebase_core/firebase_core.dart';
import 'package:flutter_riverpod/flutter_riverpod.dart';
import 'package:newsapp/firebase_options.dart';
import 'package:newsapp/services/auth/firebase_auth.dart';

final firebaseinitializerProvider = FutureProvider(
  (ref) async {
    await Firebase.initializeApp(
      options: DefaultFirebaseOptions.currentPlatform,
    );
  },
);

final authProvider = Provider(
  (ref) => FirebaseMethods(),
);

final authStateProvider = StreamProvider<User?>((ref) {
  return ref.read(authProvider).authStateChange;
});
