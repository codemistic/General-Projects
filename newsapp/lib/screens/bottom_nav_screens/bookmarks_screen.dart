import 'package:flutter/material.dart';
import 'package:flutter_riverpod/flutter_riverpod.dart';
import 'package:newsapp/screens/error_view.dart';
import 'package:newsapp/screens/loading_page.dart';
import 'package:newsapp/services/firestore/firestore_providers.dart';
import 'package:newsapp/widgets/card_view.dart';

class Bookmarks extends ConsumerWidget {
  const Bookmarks({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context, WidgetRef ref) {
    return ref.watch(saveListProvider).when(
        data: (data) {
          return Scaffold(
            body: SingleChildScrollView(
              child: Padding(
                padding: const EdgeInsets.all(16),
                child: Column(
                  children: [
                    const Text(
                      'All News',
                      style: TextStyle(
                        fontSize: 26,
                        fontWeight: FontWeight.bold,
                      ),
                    ),
                    const SizedBox(
                      height: 16,
                    ),
                    ListView.builder(
                      itemCount: data.length,
                      physics: const ClampingScrollPhysics(),
                      shrinkWrap: true,
                      itemBuilder: ((context, index) {
                        return CardView(
                          isFromSaved: true,
                          index: index,
                          title: data[index]['title'],
                          content: data[index]['des'],
                          img: data[index]['urlToImage'],
                          articleUrl: data[index]['link'],
                        );
                      }),
                    ),
                  ],
                ),
              ),
            ),
          );
        },
        error: ((error, stackTrace) => ErrorPage(
              e: error.toString(),
            )),
        loading: () => const LoadingPage());
  }
}
