import 'package:firebase_auth/firebase_auth.dart';
import 'package:flutter_riverpod/flutter_riverpod.dart';
import 'package:newsapp/services/auth/auth_providers.dart';
import 'package:newsapp/services/firestore/firestore_methods.dart';

final saveListProvider = FutureProvider(
  (ref) async {
    User? user = ref.refresh(authProvider).getCurrentUser();
    String mail = user?.email ?? "";
    return ref.refresh(firestoreprovider).getFav(mail);
  },
);
