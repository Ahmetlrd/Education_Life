import 'package:flutter/material.dart';

class Resultpage extends StatefulWidget {
  const Resultpage({super.key});

  @override
  State<Resultpage> createState() => _ResultpageState();
}

class _ResultpageState extends State<Resultpage> {
  bool control = false;
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        backgroundColor: Colors.black,
        centerTitle: false,
        title: (const Text(
          "Resultpage",
          style: TextStyle(
              color: Colors.white, fontWeight: FontWeight.bold, fontSize: 31),
        )),
      ),
      backgroundColor: const Color.fromARGB(255, 255, 17, 0),
      body: PopScope(
        canPop: false,
        onPopInvoked: (canPopState) {
          print("anan");
        },
        child: Center(
          child: Column(
            mainAxisAlignment: MainAxisAlignment.spaceEvenly,
            children: [
              Visibility(
                visible: control,
                child: const Text(
                  "hi_0",
                  style: TextStyle(fontSize: 20, fontWeight: FontWeight.bold),
                ),
              ),
              Text(control ? "Hi_1" : "Bye_1",
                  style: TextStyle(
                    color: control ? (Colors.blue) : (Colors.yellow),
                  )),
              (() {
                if (control) {
                  return Text("Hi_2");
                } else {
                  return Text("Bye_2");
                }
              }()),
              ElevatedButton(
                onPressed: () {
                  Navigator.pop(context);
                },
                child: const Text(
                  "Return back",
                  style: TextStyle(
                      color: Colors.black, fontWeight: FontWeight.bold),
                ),
                style: ElevatedButton.styleFrom(backgroundColor: Colors.green),
              ),
              ElevatedButton(
                onPressed: () {
                  setState(() {
                    control = true;
                  });
                },
                child: const Text(
                  "Make visible",
                  style: TextStyle(
                      color: Colors.black, fontWeight: FontWeight.bold),
                ),
                style: ElevatedButton.styleFrom(backgroundColor: Colors.green),
              ),
              ElevatedButton(
                onPressed: () {
                  setState(() {
                    control = false;
                  });
                },
                child: const Text(
                  "Make invisible",
                  style: TextStyle(
                      color: Colors.black, fontWeight: FontWeight.bold),
                ),
                style: ElevatedButton.styleFrom(backgroundColor: Colors.green),
              )
            ],
          ),
        ),
      ),
    );
  }
}
