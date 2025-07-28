import 'package:flutter/material.dart';
import 'package:flutter_demo/ChangePassword.dart';
import 'package:provider/provider.dart';
import 'package:flutter_demo/Create_Event_Screen.dart';
import 'package:flutter_demo/terms_policy.dart';
import 'package:flutter_demo/utils.dart';
import 'package:firebase_auth/firebase_auth.dart';
import 'main_screen.dart'; 

class LoginClass extends StatefulWidget {
  const LoginClass({super.key});

  @override
  State<LoginClass> createState() => _LoginClassState();
}

class _LoginClassState extends State<LoginClass> {
  final TextEditingController emailController = TextEditingController();
  final TextEditingController passwordController = TextEditingController();

  final FirebaseAuth _auth = FirebaseAuth.instance;

  bool email_checker(String entered_email) {
    return entered_email.endsWith('@sabanciuniv.edu');
  }

  Future<void> _loginUser(BuildContext context) async {
    String email_user = emailController.text.trim();
    String password_user = passwordController.text;

    if (!email_checker(email_user)) {
      ScaffoldMessenger.of(context).showSnackBar(
        SnackBar(
          content: Text("Please use your Sabanci email address."),
          backgroundColor: Colors.red,
        ),
      );
      return;
    }

    if (password_user.isEmpty) {
      ScaffoldMessenger.of(context).showSnackBar(
        SnackBar(
          content: Text("Password cannot be empty."),
          backgroundColor: Colors.orange,
        ),
      );
      return;
    }

    try {
      UserCredential userCredential = await _auth.signInWithEmailAndPassword(
        email: email_user,
        password: password_user,
      );

      User? user = userCredential.user;
      if (user != null) {
        if (!user.emailVerified) {
          await _auth.signOut();
          ScaffoldMessenger.of(context).showSnackBar(
            SnackBar(
              content: Text("Please verify your email before logging in."),
              backgroundColor: Colors.orange,
            ),
          );
        } else {
        
          Navigator.pushReplacement(
            context,
            MaterialPageRoute(builder: (context) => EventListScreen()),
          );
        }
      }
    } on FirebaseAuthException catch (e) {
      String message = "";
      switch (e.code) {
        case 'user-not-found':
          message = "No user found with this email.";
          break;
        case 'wrong-password':
          message = "Incorrect password.";
          break;
        default:
          message = "Login failed: ${e.message}";
      }

      ScaffoldMessenger.of(context).showSnackBar(
        SnackBar(content: Text(message), backgroundColor: Colors.red),
      );
    }
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: Utilities.appBar("SuConnect", Colors.white),
      body: Builder(
        builder: (context) => Center(
          child: SingleChildScrollView(
            child: Column(
              mainAxisAlignment: MainAxisAlignment.center,
              children: [
                Text(
                  "Welcome Back",
                  style: TextStyle(fontWeight: FontWeight.w800, fontSize: 20),
                ),
                Text(
                  "Log in with your Sabanci Email",
                  style: TextStyle(fontSize: 18),
                ),
                Utilities.customPaddingTextField(
                  label: 'email@sabanciuniv.edu',
                  controller: emailController,
                  keyboardType: TextInputType.emailAddress,
                ),
                Utilities.customPaddingTextField(
                  label: "Password",
                  controller: passwordController,
                  keyboardType: TextInputType.visiblePassword,
                ),
                SizedBox(height: 30),
                TextButton(
                  onPressed: () => _loginUser(context),
                  style: TextButton.styleFrom(
                    minimumSize: Size(345, 60),
                    backgroundColor: Colors.black,
                    shape: const RoundedRectangleBorder(
                      borderRadius: BorderRadius.all(Radius.circular(8)),
                    ),
                  ),
                  child: Text("Log In", style: TextStyle(color: Colors.white)),
                ),
                Padding(
                  padding: const EdgeInsets.only(top: 18.0),
                  child: Text(
                    "Forgot your password?",
                    style: TextStyle(fontSize: 15),
                  ),
                ),
                TextButton(
                  onPressed: () {
                    Navigator.push(
                      context,
                      MaterialPageRoute(builder: (context) => const ChangePassword()),
                       );

                  },
                  style: TextButton.styleFrom(
                    minimumSize: Size(30, 20),
                    backgroundColor: Colors.white10,
                    shape: const RoundedRectangleBorder(
                      borderRadius: BorderRadius.all(Radius.circular(8)),
                    ),
                  ),
                  child: Text(
                    "Reset Password",
                    style: TextStyle(color: Colors.black),
                  ),
                ),
              ],
            ),
          ),
        ),
      ),
    );
  }
}
