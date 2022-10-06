import 'package:flutter/material.dart';
import 'package:flutter_riverpod/flutter_riverpod.dart';
import 'package:newsapp/screens/full_news_view.dart';
// import 'package:newsapp/services/local_storage.dart';
import 'package:newsapp/services/providers/provider.dart';
import 'package:newsapp/widgets/snackbar.dart';
import 'package:url_launcher/url_launcher.dart';

class CardView extends ConsumerWidget {
  final String title, img, content, articleUrl;
  final int index;
  final bool isFromSaved;
  const CardView({
    super.key,
    required this.img,
    required this.title,
    required this.index,
    required this.content,
    required this.isFromSaved,
    required this.articleUrl,
  });

  @override
  Widget build(BuildContext context, WidgetRef ref) {
    // final count = ref.watch(localStorageProvider);
    return GestureDetector(
      onTap: () async {
        ref.read(counterController.notifier).increase();
        ref.read(counterController.notifier).save();
        if (!isFromSaved) {
          Navigator.push(
            context,
            MaterialPageRoute(
              builder: ((context) => FullView(
                    index: index,
                  )),
            ),
          );
        } else {
          final url = Uri.parse(articleUrl);
          if (!await launchUrl(url)) {
            showSnackBar(context, 'Could not launch $url');
          }
        }
      },
      child: Container(
        width: double.infinity,
        margin: const EdgeInsets.only(
          bottom: 20,
        ),
        padding: const EdgeInsets.all(12),
        height: 130,
        decoration: BoxDecoration(
          color: Colors.black,
          borderRadius: BorderRadius.circular(26),
        ),
        child: Row(
          children: [
            Flexible(
              flex: 3,
              child: Hero(
                tag: title,
                child: Container(
                  height: 100,
                  decoration: BoxDecoration(
                    borderRadius: BorderRadius.circular(16),
                    image: DecorationImage(
                      image: NetworkImage(img),
                      fit: BoxFit.fitHeight,
                    ),
                  ),
                ),
              ),
            ),
            const SizedBox(
              width: 10,
            ),
            Flexible(
              flex: 5,
              child: Column(
                children: [
                  Flexible(
                    flex: 5,
                    child: Text(
                      title,
                      softWrap: true,
                      style: const TextStyle(
                        color: Colors.white,
                        fontWeight: FontWeight.bold,
                      ),
                    ),
                  ),
                  const SizedBox(
                    height: 8,
                  ),
                  Flexible(
                    child: Text(
                      content,
                      overflow: TextOverflow.clip,
                      style: const TextStyle(
                        color: Colors.white54,
                      ),
                    ),
                  )
                ],
              ),
            )
          ],
        ),
      ),
    );
  }
}
