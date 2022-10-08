import 'package:flutter/material.dart';
import 'package:flutter_riverpod/flutter_riverpod.dart';
import 'package:newsapp/constants/constants.dart';
import 'package:newsapp/services/auth/auth_providers.dart';

class Profile extends ConsumerWidget {
  const Profile({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context, WidgetRef ref) {
    final auth = ref.watch(authProvider);
    final user = ref.read(authProvider).getCurrentUser();
    return Container(
      margin: const EdgeInsets.only(
        top: 30,
      ),
      padding: const EdgeInsets.all(20),
      child: Center(
        child: Column(
          children: [
            CircleAvatar(
              radius: 120,
              backgroundColor: Colors.black,
              child: CircleAvatar(
                radius: 118,
                backgroundColor: Colors.white,
                child: CircleAvatar(
                  backgroundImage: NetworkImage(user?.photoURL ?? profileImg),
                  radius: 110,
                ),
              ),
            ),
            const SizedBox(
              height: 20,
            ),
            Text(
              user?.displayName ?? "Anonymous",
              style: const TextStyle(
                color: Colors.black,
                fontSize: 26,
                fontWeight: FontWeight.bold,
              ),
            ),
            const SizedBox(
              height: 5,
            ),
            Text(
              user?.email ?? "Invalid Mail",
              style: const TextStyle(
                color: Colors.purple,
                fontSize: 12,
                fontWeight: FontWeight.normal,
              ),
            ),
            const Spacer(),
            GestureDetector(
              onTap: () async {
                await auth
                    .signOut()
                    .whenComplete(() => auth.authStateChange.listen((event) {
                          return;
                        }));
              },
              child: Text('Not ${user?.displayName ?? "Anonymous"}? Sign Out'),
            ),
          ],
        ),
      ),
    );
  }
}
