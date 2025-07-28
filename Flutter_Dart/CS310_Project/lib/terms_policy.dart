import 'package:flutter/material.dart';
import 'package:flutter_demo/utils.dart';

class TermsPolicy extends StatelessWidget {
  const TermsPolicy({super.key});

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text(
          "SuConnect",
          style: TextStyle(fontSize: 30, fontWeight: FontWeight.bold),
        ),
      ),
      body: Column(
        mainAxisAlignment: MainAxisAlignment.start,
        children: [
          Padding(
            padding: const EdgeInsets.all(20.0),
            child: Text(
              "Terms & Privacy Policy",
              style: TextStyle(
                color: Colors.red,
                fontSize: 30,
                fontWeight: FontWeight.w800,
              ),
            ),
          ),
          Padding(
            padding: const EdgeInsets.all(15.0),
            child: Utilities.privacy_info(),
          ),
        ],
      ),
    );
  }
}
