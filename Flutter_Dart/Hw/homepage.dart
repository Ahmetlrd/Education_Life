import 'package:flutter/material.dart';
import 'package:flutter_project/Hw/sayfa_A.dart';
import 'package:flutter_project/Hw/sayfa_X.dart';

class anasayfa extends StatefulWidget {
  const anasayfa({super.key});

  @override
  State<anasayfa> createState() => _anasayfaState();
}

class _anasayfaState extends State<anasayfa> {
  @override
  Widget build(BuildContext context) {
    return Scaffold(
        appBar: AppBar(
          title: Text("ANASAYFA"),
          backgroundColor: Colors.yellow,
        ),
        body: Center(
          child: Column(
            mainAxisAlignment: MainAxisAlignment.spaceEvenly,
            children: [
              ElevatedButton(
                onPressed: () {
                  Navigator.push(
                    context,
                    MaterialPageRoute(
                      builder: (context) => pageA(),
                    ),
                  );
                },
                child: Text("GO > A"),
                 
              ),
              ElevatedButton(
                onPressed: () {
                  Navigator.push(
                    context,
                    MaterialPageRoute(
                      builder: (context) => pageX(),
                    ),
                  );
                },
                child: Text("GO > X"),
              ),
            ],
          ),
        ));
  }
}
