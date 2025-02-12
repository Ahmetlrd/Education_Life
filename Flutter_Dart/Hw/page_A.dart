import 'package:flutter/material.dart';
import 'package:flutter_project/Hw/sayfa_B.dart';

class pageA extends StatefulWidget {
  const pageA({super.key});

  @override
  State<pageA> createState() => _pageAState();
}

class _pageAState extends State<pageA> {
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text("PAGE A"),
      ),
      body: Center(
        child: Column(
          mainAxisAlignment: MainAxisAlignment.spaceEvenly,
          children: [
            ElevatedButton(
                onPressed: () {
                  Navigator.push(context,
                      MaterialPageRoute(builder: (context) => pageB()));
                },
                child: Text("GO > B"))
          ],
        ),
      ),
    );
  }
}
