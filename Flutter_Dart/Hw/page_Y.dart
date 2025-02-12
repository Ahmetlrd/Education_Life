import 'package:flutter/material.dart';

class pageY extends StatefulWidget {
  const pageY({super.key});

  @override
  State<pageY> createState() => _pageYState();
}

class _pageYState extends State<pageY> {
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text("PAGE Y"),
      ),
      body: Center(
        child: Column(
          mainAxisAlignment: MainAxisAlignment.spaceEvenly,
          children: [
            ElevatedButton(
                onPressed: () {
                  Navigator.of(context).popUntil((route) => route.isFirst);
                },
                child: Text("GO TO HOMEGAPE"))
          ],
        ),
      ),
    );
  }
}
