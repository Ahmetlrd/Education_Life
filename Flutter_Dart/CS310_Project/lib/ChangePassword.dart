
import 'package:flutter/material.dart';
import 'package:firebase_auth/firebase_auth.dart';

import 'utils.dart';

class ChangePassword extends StatefulWidget {
const ChangePassword  ({super.key});

@override
  State<ChangePassword> createState() => _ChangePasswordState();

}

class _ChangePasswordState extends State<ChangePassword> {

  final TextEditingController emailController = TextEditingController();
  final FirebaseAuth _auth = FirebaseAuth.instance;


  Future<void> _sendResetEmail() async {
    final email = emailController.text.trim();
    if (email.isEmpty || !email.endsWith('@sabanciuniv.edu')) {
      ScaffoldMessenger.of(context).showSnackBar(
        const SnackBar(
           content: Text("Please enter a valid Sabanci University email."),
           backgroundColor: Colors.orange
        ),
    );
         return;
         }
 
    try {
      await _auth.sendPasswordResetEmail(email: email);
      ScaffoldMessenger.of(context).showSnackBar(
        const SnackBar(
          content: Text("Password reset link sent. Please check your inbox."),
          backgroundColor: Colors.green,
          ),
        );
         Navigator.pop(context);
    
    } on FirebaseAuthException catch (e) {

    String message = "";
    switch (e.code) {
      case 'user-not-found':
        message = "No user found with this email.";
        break;
      default:
        message = "Error: ${e.message}";
    } 
      ScaffoldMessenger.of(context).showSnackBar(
        SnackBar(
          content: Text(message),
          backgroundColor: Colors.red,
          ),
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
                const Text(
                  "Reset Password",
                  style: TextStyle(fontWeight: FontWeight.bold, fontSize: 24),
                  ),
                    const SizedBox(height: 10),
                     const Text(
                      "Enter your sabanci University mail for reset link",
                      style: TextStyle(fontSize: 16),
                      textAlign: TextAlign.center,
                      ),
                      const SizedBox(height: 30),
                      Utilities.customPaddingTextField(
                         label: 'email@sabanciuniv.edu',
                          controller: emailController,
                           keyboardType: TextInputType.emailAddress,
                           ),
                            const SizedBox(height: 30),
                            TextButton(
                    onPressed: () => _sendResetEmail(),
                  style: TextButton.styleFrom(
                    minimumSize: const Size(345, 60),
                    backgroundColor: Colors.black,
                    shape: const RoundedRectangleBorder(
                      borderRadius: BorderRadius.all(Radius.circular(8)),
                    ),
                  ),
                  child: const Text("Send Reset Link", style: TextStyle(color: Colors.white)),
                ),
              ],
            ),
          ),
        ),
      ),
    );
  }
}


