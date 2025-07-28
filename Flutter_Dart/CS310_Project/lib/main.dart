import 'package:flutter/material.dart';
import 'package:firebase_core/firebase_core.dart';
import 'package:flutter_demo/home_page1.dart';
import 'package:provider/provider.dart';
import 'app_state.dart';
import 'main_screen.dart';

void main() async {
  WidgetsFlutterBinding.ensureInitialized();
  await Firebase.initializeApp();
  runApp(
    ChangeNotifierProvider(
      create: (context) => ApplicationState(),
      child: const MyApp(),
    ),
  );
}

class MyApp extends StatelessWidget {
  const MyApp({super.key});

  @override
  Widget build(BuildContext context) {
    final appState = Provider.of<ApplicationState>(context);

    return MaterialApp(
      debugShowCheckedModeBanner: false,
      home: appState.loggedIn ? EventListScreen() : HomePage1(),
    );
  }
}