import 'package:flutter/material.dart';
import 'package:flutter_riverpod/flutter_riverpod.dart';
import 'package:newsapp/screens/error_view.dart';
import 'package:newsapp/screens/home_view.dart';
import 'package:newsapp/screens/loading_page.dart';
import 'package:newsapp/screens/login_view.dart';
import 'package:newsapp/services/auth/auth_providers.dart';

class AuthChecker extends ConsumerWidget {
  const AuthChecker({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context, WidgetRef ref) {
    final authState = ref.watch(authStateProvider);
    return authState.when(
      data: (data) {
        if (data != null) {
          return const Home();
        } else {
          return const LoginPage();
        }
      },
      error: (e, s) => ErrorPage(
        e: e.toString(),
      ),
      loading: () => const LoadingPage(),
    );
  }
}
