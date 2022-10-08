class Article {
  String title;
  String author;
  String description;
  String urlToImage;
  String content;
  String articleUrl;
  DateTime publishedAt;

  Article(
      {required this.title,
      required this.description,
      required this.author,
      required this.content,
      required this.urlToImage,
      required this.articleUrl,
      required this.publishedAt});
}
