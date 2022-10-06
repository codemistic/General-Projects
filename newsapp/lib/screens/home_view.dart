import 'package:flutter/material.dart';
import 'package:newsapp/screens/bottom_nav_screens/bookmarks_screen.dart';
import 'package:newsapp/screens/bottom_nav_screens/home_screen.dart';
import 'package:newsapp/screens/bottom_nav_screens/profile_screen.dart';
import 'package:newsapp/widgets/snackbar.dart';

class Home extends StatefulWidget {
  const Home({super.key});

  @override
  State<Home> createState() => _HomeState();
}

class _HomeState extends State<Home> {
  int _index = 0;
  bool isNotificationON = false;
  final screens = [
    const HomeScreen(),
    const Bookmarks(),
    const Profile(),
  ];

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: const Text(
          'News App',
          style: TextStyle(
            color: Colors.black,
          ),
        ),
        actions: [
          IconButton(
            onPressed: () {
              if (!isNotificationON) {
                showSnackBar(context, 'Notification ON');
              } else {
                showSnackBar(context, 'Notifications OFF');
              }
              setState(() {
                isNotificationON = !isNotificationON;
              });
            },
            icon: !isNotificationON
                ? const Icon(
                    Icons.notifications_outlined,
                    color: Colors.black,
                  )
                : const Icon(
                    Icons.notifications_active,
                    color: Colors.black,
                  ),
          ),
        ],
        backgroundColor: Colors.white,
      ),
      body: screens[_index],
      bottomNavigationBar: Container(
        margin: const EdgeInsets.all(12),
        decoration: BoxDecoration(
          color: Colors.black,
          borderRadius: BorderRadius.circular(16),
        ),
        child: BottomNavigationBar(
          elevation: 10,
          currentIndex: _index,
          selectedItemColor: Colors.orange.shade900,
          items: const [
            BottomNavigationBarItem(
              backgroundColor: Colors.transparent,
              icon: Icon(Icons.home),
              label: 'Home',
            ),
            BottomNavigationBarItem(
                icon: Icon(Icons.bookmark),
                label: 'Bookmarks',
                backgroundColor: Colors.transparent),
            BottomNavigationBarItem(
                icon: Icon(Icons.account_circle_rounded), label: 'Profile'),
          ],
          type: BottomNavigationBarType.shifting,
          onTap: (value) {
            setState(() {
              _index = value;
            });
          },
        ),
      ),
    );
  }
}
