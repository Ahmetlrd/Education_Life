import 'package:flutter_uygulamam/colors.dart';
import 'package:flutter/material.dart';

class Anasayfa extends StatefulWidget {
  const Anasayfa({super.key});

  @override
  State<Anasayfa> createState() => _AnasayfaState();
}

class _AnasayfaState extends State<Anasayfa> {
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text(
          "CARS MOVIE",
          style: TextStyle(
              color: yardimciRenk,
              fontWeight: FontWeight.bold,
              fontSize: 40,
              fontFamily: "BebasNeue"),
        ),
        backgroundColor: (anaRenk),
        centerTitle: true,
      ),
      body: Padding(
        padding: const EdgeInsets.only(top: 50.0),
        child: Column(
          children: [
            // Üstteki iki resim (Yan yana olacak)
            Row(
              mainAxisAlignment: MainAxisAlignment.spaceEvenly,
              children: [
                Image.asset(
                  "photos/mcqueen.png",
                  width: 150,
                  height: 200,
                ),
                Image.asset(
                  "photos/mator.png",
                  width: 150,
                  height: 200,
                ),
              ],
            ),

            Padding(
              padding: const EdgeInsets.only(bottom: 45.0),
              child: Row(
                children: [
                  Padding(
                    padding: const EdgeInsets.only(left: 50.0),
                    child: Text(
                      "McQueen",
                      style: TextStyle(
                        fontFamily: "BebasNeue",
                        fontSize: 30,
                        color: anaRenk,
                        fontWeight: FontWeight.bold,
                      ),
                    ),
                  ),
                  Padding(
                    padding: const EdgeInsets.only(left: 55.0),
                    child: Text(
                      "Mator",
                      style: TextStyle(
                        fontFamily: "BebasNeue",
                        fontSize: 30,
                        color: anaRenk,
                        fontWeight: FontWeight.bold,
                      ),
                    ),
                  ),
                ],
              ),
            ),
            // Alttaki iki resim (Yan yana olacak)
            Row(
              mainAxisAlignment: MainAxisAlignment.spaceEvenly,
              children: [
                Image.asset(
                  "photos/mack.png",
                  width: 150,
                  height: 200,
                ),
                Image.asset(
                  "photos/hudson.png",
                  width: 200,
                  height: 200,
                ),
              ],
            ),
            Padding(
              padding: const EdgeInsets.only(bottom: 45.0),
              child: Row(
                children: [
                  Padding(
                    padding: const EdgeInsets.only(left: 60.0),
                    child: Text(
                      "Mack",
                      style: TextStyle(
                        fontFamily: "BebasNeue",
                        fontSize: 30,
                        color: anaRenk,
                        fontWeight: FontWeight.bold,
                      ),
                    ),
                  ),
                  Padding(
                    padding: const EdgeInsets.only(left: 70.0),
                    child: Text(
                      "Dr. Hudson",
                      style: TextStyle(
                        fontFamily: "BebasNeue",
                        fontSize: 30,
                        color: anaRenk,
                        fontWeight: FontWeight.bold,
                      ),
                    ),
                  ),
                ],
              ),
            ),
            Row(
              mainAxisAlignment: MainAxisAlignment.spaceEvenly,
              children: [
                Text(
                  "Change Characters !",
                  style: TextStyle(
                    fontFamily: "BebasNeue",
                    fontSize: 25,
                    color: anaRenk,
                    fontWeight: FontWeight.bold,
                  ),
                ),
                TextButton(
                  style: TextButton.styleFrom(
                    backgroundColor: anaRenk,
                    shape: const RoundedRectangleBorder(
                        borderRadius: BorderRadius.all(Radius.circular(12))),
                  ),
                  onPressed: () {},
                  child: Text(
                    "Shuffle",
                    style: TextStyle(
                      fontFamily: "BebasNeue",
                      fontSize: 23,
                      color: yardimciRenk,
                      fontWeight: FontWeight.bold,
                    ),
                  ),
                )
              ],
            )
          ],
        ),
      ),
      backgroundColor: yardimciRenk,
    );
  }
}
