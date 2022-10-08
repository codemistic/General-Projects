import 'package:flutter/material.dart';
import 'package:flutter_riverpod/flutter_riverpod.dart';
import 'package:newsapp/screens/full_news_view.dart';
import 'package:newsapp/services/providers/provider.dart';

class BreakingNews extends ConsumerWidget {
  final String img, title;
  final int index;
  const BreakingNews(
      {super.key, required this.img, required this.title, required this.index});

  @override
  Widget build(BuildContext context, WidgetRef ref) {
    // print(img);
    return InkWell(
      onTap: () {
        ref.read(counterController.notifier).increase();
        ref.read(counterController.notifier).save();
        Navigator.push(
          context,
          MaterialPageRoute(
              builder: ((context) => FullView(
                    index: index,
                  ))),
        );
      },
      child: Container(
        decoration: BoxDecoration(
          borderRadius: BorderRadius.circular(30.0),
          image: DecorationImage(
            fit: BoxFit.fill,
            image: NetworkImage(img),
          ),
        ),
        child: Container(
          decoration: BoxDecoration(
            borderRadius: BorderRadius.circular(30),
            gradient: const LinearGradient(
              colors: [Colors.transparent, Colors.black],
              begin: Alignment.topCenter,
              end: Alignment.bottomCenter,
            ),
          ),
          padding: const EdgeInsets.all(16),
          child: Column(
            mainAxisAlignment: MainAxisAlignment.end,
            crossAxisAlignment: CrossAxisAlignment.start,
            children: [
              Text(
                title.toString(),
                style: const TextStyle(
                  color: Colors.white,
                  fontSize: 18,
                  fontWeight: FontWeight.bold,
                ),
              )
            ],
          ),
        ),
      ),
    );
  }
}
