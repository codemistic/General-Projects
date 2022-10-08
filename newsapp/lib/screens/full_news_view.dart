import 'dart:developer';

import 'package:flutter/material.dart';
import 'package:flutter_riverpod/flutter_riverpod.dart';
import 'package:newsapp/constants/constants.dart';
import 'package:newsapp/services/auth/auth_providers.dart';
import 'package:newsapp/services/firestore/firestore_methods.dart';
import 'package:newsapp/services/firestore/firestore_providers.dart';
import 'package:newsapp/services/providers/provider.dart';
import 'package:newsapp/widgets/snackbar.dart';
import 'package:url_launcher/url_launcher.dart';

class FullView extends ConsumerWidget {
  final int index;

  const FullView({
    Key? key,
    required this.index,
  }) : super(key: key);

  @override
  Widget build(BuildContext context, WidgetRef ref) {
    // String articleTitle, articleAuthor, articleImg, articleContent;
    return ref.watch(newsProvider).maybeWhen(
          data: (data) {
            // log(data.toString());
            bool isSaved = false;
            final user = ref.read(authProvider).getCurrentUser();
            return Scaffold(
              appBar: AppBar(
                title: const Text(
                  'Save Article',
                  style: TextStyle(
                    color: Colors.black,
                    fontSize: 18,
                  ),
                ),
                backgroundColor: Colors.white,
                iconTheme: const IconThemeData(
                  color: Colors.orange,
                ),
                actions: [
                  IconButton(
                    onPressed: () async {
                      if (!isSaved) {
                        String email = user?.email ?? '';
                        if (email != '') {
                          try {
                            await FirestoreMethods().addFav(
                              data[index].title,
                              data[index].author,
                              data[index].content,
                              data[index].urlToImage,
                              data[index].articleUrl,
                            );
                            showSnackBar(context, 'Saved');
                            isSaved = true;
                            ref.refresh(saveListProvider);
                          } catch (e) {
                            log(e.toString());
                            showSnackBar(context, e.toString());
                          }
                        } else {
                          showSnackBar(context, 'Login to Save');
                        }
                      } else {
                        showSnackBar(context, 'Already Saved');
                      }
                    },
                    icon: const Icon(Icons.add),
                  ),
                ],
              ),
              body: SingleChildScrollView(
                child: Padding(
                  padding: const EdgeInsets.all(18.0),
                  child: Column(
                    mainAxisAlignment: MainAxisAlignment.start,
                    crossAxisAlignment: CrossAxisAlignment.start,
                    children: [
                      Text(
                        data[index].title,
                        style: const TextStyle(
                          fontSize: 26,
                          fontWeight: FontWeight.bold,
                        ),
                      ),
                      const SizedBox(
                        height: 8,
                      ),
                      Text(
                        data[index].author,
                        style: const TextStyle(
                          color: Colors.black54,
                        ),
                      ),
                      const SizedBox(
                        height: 20,
                      ),
                      Hero(
                        tag: data[index].title,
                        child: ClipRRect(
                          borderRadius: BorderRadius.circular(30),
                          child: Image(
                            image: NetworkImage(data[index].urlToImage),
                            errorBuilder: ((context, error, stackTrace) =>
                                Image.network(imgUrl)),
                          ),
                        ),
                      ),
                      const SizedBox(
                        height: 30,
                      ),
                      Text(data[index].content),
                      const SizedBox(
                        height: 30,
                      ),
                      GestureDetector(
                        onTap: () async {
                          final url = Uri.parse(data[index].articleUrl);
                          if (!await launchUrl(url)) {
                            showSnackBar(context, 'Could not launch $url');
                          }
                        },
                        child: const Text(
                          'Go to Article',
                          style: TextStyle(
                            color: Colors.purple,
                            fontSize: 8,
                            decoration: TextDecoration.underline,
                          ),
                        ),
                      ),
                    ],
                  ),
                ),
              ),
            );
          },
          orElse: () => const CircularProgressIndicator(),
        );
  }
}
