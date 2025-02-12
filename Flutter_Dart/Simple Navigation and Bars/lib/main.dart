import 'package:flutter/material.dart';
import 'package:flutter_project/bottom_nav_kullanimi/page_home.dart';
import 'package:flutter_project/homepage.dart';
import 'package:flutter_project/user_interaction.dart/user.dart';

void main() {
  runApp(const MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({super.key});

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'Flutter Demo',
      debugShowCheckedModeBanner: false,
      theme: ThemeData(
        colorScheme: ColorScheme.fromSeed(seedColor: Colors.deepPurple),
        useMaterial3: true,
      ),
      home: const user_interaction(),
    );
  }
}
