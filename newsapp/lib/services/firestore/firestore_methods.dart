import 'dart:developer';

import 'package:cloud_firestore/cloud_firestore.dart';
import 'package:flutter_riverpod/flutter_riverpod.dart';
import 'package:newsapp/services/auth/firebase_auth.dart';

final firestoreprovider = Provider(
  (ref) => FirestoreMethods(),
);

class FirestoreMethods {
  final _fireStore = FirebaseFirestore.instance;
  String email = FirebaseMethods().getCurrentUser()?.email ?? "";
  Future addFav(
    String title,
    String author,
    String content,
    String urlToImg,
    String url,
  ) async {
    final doc = _fireStore.collection(email).doc(title + author);
    await doc.set({
      'title': title,
      'author': author,
      'des': content,
      'urlToImage': urlToImg,
      'link': url,
    });
  }

  Future getFav(String key) async {
    log(key);
    QuerySnapshot querySnapshot = await _fireStore.collection(key).get();
    final newsData = querySnapshot.docs.map((doc) => doc.data()).toList();
    return newsData;
  }

  Stream getSavedData() {
    final newsData = _fireStore.collection(email).snapshots();
    return newsData;
  }
}
