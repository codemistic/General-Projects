import 'package:carousel_slider/carousel_slider.dart';
import 'package:flutter/material.dart';
import 'package:flutter_riverpod/flutter_riverpod.dart';
import 'package:newsapp/constants/constants.dart';
import 'package:newsapp/services/firestore/firestore_providers.dart';
import 'package:newsapp/services/providers/provider.dart';
import 'package:newsapp/widgets/breaking_news_card.dart';
import 'package:newsapp/widgets/card_view.dart';

class HomeScreen extends ConsumerWidget {
  const HomeScreen({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context, WidgetRef ref) {
    return Consumer(
      builder: ((context, ref, child) {
        ref.refresh(saveListProvider);
        return ref.watch(newsProvider).when(
            data: ((data) {
              return SingleChildScrollView(
                child: Padding(
                  padding: const EdgeInsets.all(16),
                  child: Column(
                    mainAxisAlignment: MainAxisAlignment.start,
                    crossAxisAlignment: CrossAxisAlignment.start,
                    children: [
                      const Text(
                        'Breaking News',
                        style: TextStyle(
                          fontSize: 26,
                          fontWeight: FontWeight.bold,
                        ),
                      ),
                      const SizedBox(
                        height: 20,
                      ),
                      CarouselSlider.builder(
                        itemCount: data.length,
                        itemBuilder: (context, index, id) => BreakingNews(
                          img: data[index].urlToImage,
                          title: data[index].title,
                          index: index,
                        ),
                        options: CarouselOptions(
                          aspectRatio: 16 / 9,
                          enableInfiniteScroll: true,
                          enlargeCenterPage: true,
                        ),
                      ),
                      const SizedBox(
                        height: 40,
                      ),
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
                            isFromSaved: false,
                            index: index,
                            img: data[index].urlToImage,
                            title: data[index].title,
                            content: data[index].content,
                            articleUrl: data[index].articleUrl,
                          );
                        }),
                      ),
                    ],
                  ),
                ),
              );
            }),
            error: ((error, stackTrace) {
              return Text(
                error.toString(),
                style: readCounterTextStyle,
              );
            }),
            loading: (() => const Center(child: CircularProgressIndicator())));
      }),
    );
  }
}
