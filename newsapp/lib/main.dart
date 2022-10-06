import 'package:flutter/material.dart';
import 'package:flutter_dotenv/flutter_dotenv.dart';
import 'package:flutter_riverpod/flutter_riverpod.dart';
import 'package:newsapp/screens/error_view.dart';
import 'package:newsapp/screens/loading_page.dart';
import 'package:newsapp/services/auth/auth_checker.dart';
import 'package:newsapp/services/auth/auth_providers.dart';

Future<void> main() async {
  WidgetsFlutterBinding.ensureInitialized();
  await dotenv.load(fileName: ".env");
  runApp(
    ProviderScope(
      child: MaterialApp(
        theme: ThemeData(
          useMaterial3: true,
          primaryColor: Colors.black,
        ),
        debugShowCheckedModeBanner: false,
        home: const MyApp(),
      ),
    ),
  );
}

class MyApp extends ConsumerWidget {
  const MyApp({super.key});

  @override
  Widget build(BuildContext context, WidgetRef ref) {
    final intializeApp = ref.watch(firebaseinitializerProvider);
    return intializeApp.when(
        data: (data) => const AuthChecker(),
        error: ((error, stackTrace) => ErrorPage(
              e: error.toString(),
            )),
        loading: (() => const LoadingPage()));
  }
}
