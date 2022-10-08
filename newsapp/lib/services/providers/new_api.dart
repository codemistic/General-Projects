import 'dart:convert';
import 'package:flutter_dotenv/flutter_dotenv.dart';
import 'package:flutter_riverpod/flutter_riverpod.dart';
import 'package:http/http.dart' as http;
import 'package:newsapp/constants/constants.dart';
import 'package:newsapp/model/article.dart';
import 'dart:developer' show log;

final apiProvider = Provider(
  (ref) => GetNews(),
);

class GetNews {
  final String apiKey = dotenv.env['new_api_key'] ?? 'inavlid';
  late String apiURL;
  GetNews() {
    apiURL =
        "https://newsdata.io/api/1/news?apikey=$apiKey+&category=science,politics,world,environment,business&language=en&country=in";
  }
  Future<void> checkApi() async {
    await Future.delayed(const Duration(seconds: 1));
  }

  Future<List<Article>> apiCall() async {
    List<Article> newsCollection = [];
    final res = await http.get(Uri.parse(apiURL));
    final jsonData = jsonDecode(res.body);
    if (jsonData['status'] == 'success') {
      jsonData['results'].forEach(
        (e) {
          String des;
          if (e['content'] == null && e['description'] != null) {
            des = e['description'];
          } else if (e['content'] == null && e['description'] == null) {
            des = "No Description provided by API";
          } else {
            des = e['content'];
          }
          Article article = Article(
            title: e['title'] ?? title,
            author: e['source_id'] ?? author,
            description: des,
            urlToImage: e['image_url'] ?? imgUrl,
            publishedAt: DateTime.parse(e['pubDate'] ?? currentDatetime),
            content: des,
            articleUrl: e["link"] ?? articleURL,
          );
          newsCollection.add(article);
        },
      );
    } else {
      log('api failed');
    }
    return newsCollection;
  }
}
