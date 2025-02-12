import 'package:flutter/material.dart';

class page_3 extends StatefulWidget {
  const page_3({super.key});

  @override
  State<page_3> createState() => _page_3State();
}

class _page_3State extends State<page_3> {
  @override
  Widget build(BuildContext context) {
    return const Center(
      child: Text(
        "Page 3",
        style: TextStyle(
            fontSize: 20, fontWeight: FontWeight.bold, color: Colors.black),
      ),
    );
    ;
  }
}
