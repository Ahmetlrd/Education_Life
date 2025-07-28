import 'package:flutter/material.dart';
import 'package:firebase_auth/firebase_auth.dart';
import 'package:flutter_demo/terms_policy.dart';
import 'package:flutter_demo/utils.dart';

class Register extends StatefulWidget {
  const Register({super.key});

  @override
  State<Register> createState() => _RegisterState();
}

class _RegisterState extends State<Register> {
  final TextEditingController emailController = TextEditingController();
  final TextEditingController passwordController = TextEditingController();
  final TextEditingController passwordAgainController = TextEditingController();

  final FirebaseAuth _auth = FirebaseAuth.instance;

  @override
  void dispose() {
    emailController.dispose();
    passwordController.dispose();
    passwordAgainController.dispose();
    super.dispose();
  }

  

  Future<void> _registerUser() async {

      if (!emailController.text.trim().endsWith('@sabanciuniv.edu')) {
    ScaffoldMessenger.of(context).showSnackBar(
      SnackBar(content: Text("Please use your Sabancı University email.")),
    );
    return;
  }

    if (passwordController.text != passwordAgainController.text) {
      ScaffoldMessenger.of(context).showSnackBar(
        SnackBar(content: Text("Passwords do not match")),
      );
      return;
    }

    try {
      UserCredential userCredential = await _auth.createUserWithEmailAndPassword(
        email: emailController.text.trim(),
        password: passwordController.text.trim(),
      );

      User? user = userCredential.user;
      if (user != null && !user.emailVerified) {
        await user.sendEmailVerification();
        ScaffoldMessenger.of(context).showSnackBar(
          SnackBar(
            content: Text(
              "Verification email sent! Please check your inbox.",
            ),
          ),
        );
        await _auth.signOut(); // Sign the user out after registration to ensure only the verified enter
      }
    } on FirebaseAuthException catch (e) {
      String message = "";
      switch (e.code) {
        case 'email-already-in-use':
          message = "This email is already in use.";
          break;
        case 'weak-password':
          message = "The password is too weak.";
          break;
        case 'invalid-email':
          message = "The email address is not valid.";
          break;
        default:
          message = "Registration failed: ${e.message}";
      }

      ScaffoldMessenger.of(context).showSnackBar(
        SnackBar(content: Text(message)),
      );
    } catch (e) {
      ScaffoldMessenger.of(context).showSnackBar(
        SnackBar(content: Text("Unexpected error: ${e.toString()}")),
      );
    }
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text(
          "SuConnect",
          style: TextStyle(fontSize: 30, fontWeight: FontWeight.bold),
        ),
      ),
      body: Center(
        child: SingleChildScrollView(
          child: Column(
            mainAxisAlignment: MainAxisAlignment.center,
            children: [
              Text(
                "Create an account",
                style: TextStyle(fontWeight: FontWeight.w800, fontSize: 20),
              ),
              Text(
                "Sign up with your Sabancı Email",
                style: TextStyle(fontSize: 18),
              ),
              Padding(
                padding: const EdgeInsets.all(30.0),
                child: TextField(
                  controller: emailController,
                  decoration: InputDecoration(
                    labelText: 'email@sabanciuniv.edu',
                    border: OutlineInputBorder(),
                  ),
                ),
              ),
              Padding(
                padding: const EdgeInsets.symmetric(horizontal: 30.0),
                child: TextField(
                  controller: passwordController,
                  obscureText: true,
                  decoration: InputDecoration(
                    labelText: 'Password',
                    border: OutlineInputBorder(),
                  ),
                ),
              ),
              Padding(
                padding: const EdgeInsets.all(30.0),
                child: TextField(
                  controller: passwordAgainController,
                  obscureText: true,
                  decoration: InputDecoration(
                    labelText: 'Password Again',
                    border: OutlineInputBorder(),
                  ),
                ),
              ),
              TextButton(
                onPressed: _registerUser,
                style: TextButton.styleFrom(
                  minimumSize: Size(345, 60),
                  backgroundColor: Colors.black,
                  shape: const RoundedRectangleBorder(
                    borderRadius: BorderRadius.all(Radius.circular(8)),
                  ),
                ),
                child: Text("Sign Up", style: TextStyle(color: Colors.white)),
              ),
              Padding(
                padding: const EdgeInsets.only(top: 18.0),
                child: Utilities.buildText(
                  label: "By clicking continue, you agree to our",
                  size: 15,
                ),
              ),
              TextButton(
                onPressed: () {
                  Navigator.push(
                    context,
                    MaterialPageRoute(builder: (context) => TermsPolicy()),
                  );
                },
                style: TextButton.styleFrom(
                  minimumSize: Size(30, 20),
                  backgroundColor: Colors.white10,
                  shape: const RoundedRectangleBorder(
                    borderRadius: BorderRadius.all(Radius.circular(8)),
                  ),
                ),
                child: Utilities.buildText(
                  label: "Terms & Privacy Policy",
                  size: 15,
                ),
              ),
            ],
          ),
        ),
      ),
    );
  }
}
