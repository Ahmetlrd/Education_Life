import 'package:flutter/material.dart';
import 'package:flutter_project/contacts.dart';
import 'package:flutter_project/gamepage.dart';

class Homepage extends StatefulWidget {
  const Homepage({super.key});

  @override
  State<Homepage> createState() => _HomepageState();
}

class _HomepageState extends State<Homepage> {
  int sayac = 0;
  @override
  void initState() {
    super.initState();
    sayac = 10;
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        backgroundColor: Colors.black,
        centerTitle: false,
        title: (const Text(
          "Homepage",
          style: TextStyle(
              color: Colors.white, fontWeight: FontWeight.bold, fontSize: 31),
        )),
      ),
      backgroundColor: const Color.fromARGB(255, 255, 17, 0),
      body: Center(
        child: Column(
          mainAxisAlignment: MainAxisAlignment.spaceEvenly,
          children: [
            Text("Result : $sayac",
                style: TextStyle(
                    fontWeight: FontWeight.bold,
                    fontSize: 30,
                    color: Colors.blue)),
            ElevatedButton(
              onPressed: () {
                setState(() {
                  sayac++;
                });
              },
              child: const Text(
                "Increment",
                style:
                    TextStyle(color: Colors.black, fontWeight: FontWeight.bold),
              ),
              style: ElevatedButton.styleFrom(backgroundColor: Colors.green),
            ),
            ElevatedButton(
              onPressed: () {
                setState(() {
                  sayac = 0;
                });
              },
              child: const Text(
                "Reset",
                style:
                    TextStyle(color: Colors.black, fontWeight: FontWeight.bold),
              ),
              style: ElevatedButton.styleFrom(backgroundColor: Colors.green),
            ),
            ElevatedButton(
              onPressed: () {
                var contact =
                    Contacts(isim: "John", yas: 21, boy: 1.85, bekar: true);
                Navigator.push(
                    context,
                    MaterialPageRoute(
                        builder: ((context) => Gamepage(contact: contact))));
              },
              child: const Text(
                "Enter",
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
