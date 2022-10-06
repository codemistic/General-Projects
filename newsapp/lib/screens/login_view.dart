import 'package:flutter/material.dart';
import 'package:flutter_riverpod/flutter_riverpod.dart';
import 'package:flutter_signin_button/button_list.dart';
import 'package:flutter_signin_button/button_view.dart';
import 'package:newsapp/services/auth/auth_providers.dart';

class LoginPage extends ConsumerWidget {
  const LoginPage({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context, WidgetRef ref) {
    final auth = ref.watch(authProvider);
    return Scaffold(
      body: Column(
        mainAxisAlignment: MainAxisAlignment.center,
        crossAxisAlignment: CrossAxisAlignment.center,
        children: [
          Padding(
            padding:
                EdgeInsets.only(top: MediaQuery.of(context).size.height * 0.45),
            child: SignInButton(
              Buttons.Google,
              text: "Log In With Google",
              onPressed: () async {
                await auth.googleSignIn(context).whenComplete(
                      () => auth.authStateChange.listen(
                        (event) {
                          return;
                        },
                      ),
                    );
              },
            ),
          ),
          const Spacer(),
          Row(
            mainAxisAlignment: MainAxisAlignment.center,
            children: const [
              Text(
                'Made with ',
                style: TextStyle(
                  fontSize: 12,
                  color: Colors.pink,
                ),
              ),
              Icon(
                Icons.favorite,
                color: Colors.teal,
                size: 16,
              ),
              Text(
                ' by AA',
                style: TextStyle(
                  fontSize: 12,
                  color: Colors.pink,
                ),
              ),
            ],
          ),
        ],
      ),
    );
  }
}
