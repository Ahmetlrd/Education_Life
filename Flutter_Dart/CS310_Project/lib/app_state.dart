
import 'package:firebase_auth/firebase_auth.dart';
import 'package:firebase_core/firebase_core.dart';
import 'package:flutter/material.dart';

class ApplicationState extends ChangeNotifier {
  ApplicationState() {
    init();
  }

  bool _loggedIn = false;
  bool get loggedIn => _loggedIn;

  Future<void> init() async {
   
        
    FirebaseAuth.instance.userChanges().listen((user) {
     
       _loggedIn = user != null && user.emailVerified;
      notifyListeners();
    });
  }
}