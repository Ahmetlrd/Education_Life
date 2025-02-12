import 'package:flutter/material.dart';
import 'package:flutter_project/bottom_nav_kullanimi/page_1.dart';
import 'package:flutter_project/bottom_nav_kullanimi/page_2.dart';
import 'package:flutter_project/bottom_nav_kullanimi/page_3.dart';

class page_home extends StatefulWidget {
  const page_home({super.key});

  @override
  State<page_home> createState() => _page_homeState();
}

class _page_homeState extends State<page_home> {
  int index_n = 0;
  var pages = [page_1(), page_2(), page_3()];
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text(
          "Bottom_Navigation",
          style: TextStyle(fontWeight: FontWeight.bold, color: Colors.white70),
        ),
        backgroundColor: Colors.deepPurple,
      ),
      body: pages[index_n],
      bottomNavigationBar: BottomNavigationBar(
          items: const [
            BottomNavigationBarItem(
                icon: Icon(Icons.looks_one_outlined), label: "One"),
            BottomNavigationBarItem(
                icon: Icon(Icons.looks_two_outlined), label: "Two"),
            BottomNavigationBarItem(
                icon: Icon(Icons.looks_3_outlined), label: "Three"),
          ],
          currentIndex: index_n,
          backgroundColor: (Colors.deepPurple),
          selectedItemColor: (Colors.white),
          selectedFontSize: 15,
          unselectedItemColor: Colors.white54,
          onTap: (a) {
            setState(() {
              index_n = a;
            });
          }),
    );
  }
}
