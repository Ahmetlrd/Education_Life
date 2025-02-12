import 'package:flutter/material.dart';
import 'package:flutter_project/Hw/sayfa_Y.dart';

class pageB extends StatefulWidget {
  const pageB({super.key});

  @override
  State<pageB> createState() => _pageBState();
}

class _pageBState extends State<pageB> {
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text("PAGE B"),
      ),
      body: Center(
        child: Column(
          mainAxisAlignment: MainAxisAlignment.spaceEvenly,
          children: [
            ElevatedButton(
                onPressed: () {
                  Navigator.push(context,
                      MaterialPageRoute(builder: (context) => pageY()));
                },
                child: Text("GO > Y"))
          ],
        ),
      ),
    );
  }
}
