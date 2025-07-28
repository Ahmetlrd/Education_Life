import 'package:flutter/material.dart';
import 'package:flutter_demo/register.dart';
import 'package:flutter_demo/utils.dart';
import 'Login.dart';

class HomePage1 extends StatelessWidget {
  const HomePage1({super.key});

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(),
      body: Center(
        child: Column(
          mainAxisAlignment: MainAxisAlignment.spaceEvenly,
          children: [
            Utilities.buildText(label: "SuConnect", size: 50),

            Image.asset("assets/sabanci.png"),
            Row(
              mainAxisAlignment: MainAxisAlignment.spaceEvenly,
              children: [
                Utilities.buildAuthButton(
                  context: context,
                  label: "Login",
                  destination: LoginClass(),
                ),
                Utilities.buildAuthButton(
                  context: context,
                  label: "Sign Up",
                  destination: Register(),
                ),
              ],
            ),
            Text(
              "Don't miss the events, live the moment!",
              style: TextStyle(fontSize: 20, fontFamily: 'Montserrat'),
            ),
          ],
        ),
      ),
    );
  }
}
