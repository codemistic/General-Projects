import 'package:firebase_auth/firebase_auth.dart';
import 'package:firebase_core/firebase_core.dart';
import 'package:flutter/cupertino.dart';
import 'package:flutter/foundation.dart';
import 'package:google_sign_in/google_sign_in.dart';
import 'package:newsapp/firebase_options.dart';
import 'package:newsapp/widgets/snackbar.dart';

// final authProvider = Provider(
//   (ref) => FirebaseMethods(),
// );

class FirebaseMethods {
  final FirebaseAuth _auth = FirebaseAuth.instance;

  //  This getter will be returning a Stream of User object.
  //  It will be used to check if the user is logged in or not.
  Stream<User?> get authStateChange => _auth.authStateChanges();

  User? getCurrentUser() {
    final User? user = _auth.currentUser;
    return user;
  }

  Future<void> intialiseApp() async {
    await Firebase.initializeApp(
      options: DefaultFirebaseOptions.currentPlatform,
    );
  }

  Future<void> googleSignIn(BuildContext context) async {
    try {
      if (kIsWeb) {
        GoogleAuthProvider googleProvider = GoogleAuthProvider();

        googleProvider
            .addScope('https://www.googleapis.com/auth/contacts.readonly');

        await _auth.signInWithPopup(googleProvider);
      } else {
        final GoogleSignInAccount? googleUser = await GoogleSignIn().signIn();

        //auth details from Sign In request
        final GoogleSignInAuthentication googleAuth =
            await googleUser!.authentication;

        //create credentials
        final credential = GoogleAuthProvider.credential(
          accessToken: googleAuth.accessToken,
          idToken: googleAuth.idToken,
        );

        //try firebase login

        await _auth.signInWithCredential(credential);
      }
    } on FirebaseAuthException catch (e) {
      showSnackBar(context, e.toString());
    }
  }

  Future<void> signOut() async {
    if (getCurrentUser() != null) {
      await GoogleSignIn().signOut();
      await _auth.signOut();
    }
  }
}
