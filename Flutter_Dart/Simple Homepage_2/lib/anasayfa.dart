import 'package:flutter/material.dart';
import 'package:flutter_test_21/renkler.dart';
import 'package:flutter_gen/gen_l10n/app_localizations.dart';

class Anasayfa extends StatefulWidget {
  const Anasayfa({super.key});

  @override
  State<Anasayfa> createState() => _AnasayfaState();
}

class _AnasayfaState extends State<Anasayfa> {
  @override
  Widget build(BuildContext context) {
    var ekranbilgisi = MediaQuery.of(context);
    final double ekranheight = ekranbilgisi.size.height;
    final double ekranwidth = ekranbilgisi.size.width;
    print("Ekran yüksekliği: $ekranheight");
    print("Ekran genişliği: $ekranwidth");

    var d = AppLocalizations.of(context);
    if (d == null) {
      return Scaffold(
        body: Center(
          child: Text("Dil dosyaları yüklenemedi!"),
        ),
      );
    }

    return Scaffold(
        appBar: AppBar(
          title: Text(
            "Pizza",
            style: TextStyle(
                color: yaziRengi1,
                fontFamily: "Kranky",
                fontSize: ekranwidth / 10),
          ),
          centerTitle: true,
          backgroundColor: (anaRenk),
        ),
        body: Column(
          children: [
            Padding(
              padding: const EdgeInsets.only(top: 40),
              child: Text(
                d.pizzaBaslik,
                style: TextStyle(
                    fontSize: 36,
                    color: (anaRenk),
                    fontWeight: FontWeight.bold),
              ),
            ),
            Padding(
              padding: const EdgeInsets.only(top: 40.0, bottom: 40),
              child: Image.asset(
                "resimler/pizza.png",
                width: 200, // Genişlik
                height: 200, // Yükseklik
                fit: BoxFit.cover, // Görüntünün sığdırma şeklini belirler
              ),
            ),
            Padding(
              padding: const EdgeInsets.only(top: 16.0, bottom: 20),
              child: Row(
                mainAxisAlignment: MainAxisAlignment.spaceEvenly,
                children: [
                  buton(isim: d.peynirYazi),
                  buton(isim: d.sosisYazi),
                  buton(isim: d.zeytinYazi),
                  buton(isim: d.biberYazi),
                ],
              ),
            ),
            Padding(
              padding: const EdgeInsets.all(20.0),
              child: Column(
                children: [
                  Text(
                    d.dakikaYazi,
                    style: TextStyle(
                        fontSize: 22,
                        color: (yaziRengi2),
                        fontWeight: FontWeight.bold),
                  ),
                  Padding(
                    padding: const EdgeInsets.all(16.0),
                    child: Text(
                      d.teslimatBaslik,
                      style: TextStyle(
                          fontSize: 22,
                          color: (anaRenk),
                          fontWeight: FontWeight.bold),
                    ),
                  ),
                  Text(
                    d.pizzaAciklama,
                    style: TextStyle(
                      fontSize: 20,
                      color: (yaziRengi2),
                    ),
                    textAlign: TextAlign.center,
                  ),
                ],
              ),
            ),
            Row(
              mainAxisAlignment: MainAxisAlignment.spaceEvenly,
              children: [
                Text(
                  d.fiyat,
                  style: TextStyle(
                      fontSize: 44,
                      color: (anaRenk),
                      fontWeight: FontWeight.bold),
                ),
                SizedBox(
                  width: 180,
                  height: 80,
                  child: TextButton(
                    onPressed: () {},
                    style: TextButton.styleFrom(
                        backgroundColor: anaRenk,
                        shape: const RoundedRectangleBorder(
                            borderRadius:
                                BorderRadius.all(Radius.circular(8)))),
                    child: Text(
                      d.butonYazi,
                      style: TextStyle(color: yaziRengi1, fontSize: 18),
                    ),
                  ),
                ),
              ],
            ),
          ],
        ));
  }
}

class buton extends StatelessWidget {
  final String isim;
  const buton({super.key, required this.isim});
  @override
  Widget build(BuildContext context) {
    return TextButton(
      onPressed: () {},
      style: TextButton.styleFrom(backgroundColor: anaRenk),
      child: Text(
        isim,
        style: TextStyle(color: yaziRengi1),
      ),
    );
  }
}
