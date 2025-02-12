import 'package:flutter/material.dart';
import 'package:flutter_project/Hw/sayfa_Y.dart';

class pageX extends StatefulWidget {
  const pageX({super.key});

  @override
  State<pageX> createState() => _pageXState();
}

class _pageXState extends State<pageX> {
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text("PAGE X"),
      ),
      body: Center(
        child: Column(
          mainAxisAlignment: MainAxisAlignment.spaceEvenly,
          children: [
            ElevatedButton(
                onPressed: () {
                  Navigator.pushReplacement(context,
                      MaterialPageRoute(builder: (context) => pageY()));
                },
                child: Text("GO > Y"))
          ],
        ),
      ),
    );
  }
}
