import 'package:flutter/material.dart';
import 'package:flutter_project/resultpage.dart';
import 'package:flutter_project/contacts.dart';

class Gamepage extends StatefulWidget {
  Contacts contact;
  Gamepage({
    required this.contact,
  });

  @override
  State<Gamepage> createState() => _GamepageState();
}

class _GamepageState extends State<Gamepage> {
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        backgroundColor: Colors.black,
        centerTitle: false,
        title: (const Text(
          "Gamepage",
          style: TextStyle(
              color: Colors.white, fontWeight: FontWeight.bold, fontSize: 31),
        )),
        leading: IconButton(
          onPressed: () {
            print("Clicked");
          },
          icon: const Icon(Icons.arrow_back),
        ),
      ),
      backgroundColor: const Color.fromARGB(255, 255, 17, 0),
      body: Center(
        child: Column(
          mainAxisAlignment: MainAxisAlignment.spaceEvenly,
          children: [
            Text(
                "${widget.contact.isim} - ${widget.contact.yas} - ${widget.contact.boy} - ${widget.contact.bekar}"),
            ElevatedButton(
              onPressed: () {
                Navigator.push(context,
                    MaterialPageRoute(builder: ((context) => Resultpage())));
              },
              child: const Text(
                "Go",
                style:
                    TextStyle(color: Colors.black, fontWeight: FontWeight.bold),
              ),
              style: ElevatedButton.styleFrom(backgroundColor: Colors.green),
            ),
            ElevatedButton(
              onPressed: () {
                Navigator.of(context).popUntil((route) => route.isFirst);
              },
              child: const Text(
                "Return to Homepage",
                style:
                    TextStyle(color: Colors.black, fontWeight: FontWeight.bold),
              ),
              style: ElevatedButton.styleFrom(backgroundColor: Colors.green),
            )
          ],
        ),
      ),
    );
  }
}
