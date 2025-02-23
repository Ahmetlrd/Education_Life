import 'package:flutter/material.dart';
import 'package:flutter_productsapp/data/entity/products.dart';
import 'package:flutter_productsapp/ui/views/detail.dart';

class Homepage extends StatefulWidget {
  const Homepage({super.key});

  @override
  State<Homepage> createState() => _HomepageState();
}

class _HomepageState extends State<Homepage> {
  Future<List<Products>> uploadProducts() async {
    var productList = <Products>[];
    var u1 = Products(
        id: 1, name: "Macbook Pro 14", photo: "macbook.png", price: 43000);
    var u2 = Products(
        id: 2,
        name: "Rayban Club Master",
        photo: "sunglasses.png",
        price: 2500);
    var u3 = Products(
        id: 3, name: "Sony ZX Series", photo: "headphones.png", price: 40000);
    var u4 =
        Products(id: 4, name: "Gio Armani", photo: "parfume.png", price: 2000);
    var u5 = Products(
        id: 5, name: "Casio X Series", photo: "watch.png", price: 8000);
    var u6 =
        Products(id: 6, name: "Dyson V8", photo: "broom.png", price: 18000);
    var u7 =
        Products(id: 7, name: "Iphone X", photo: "iphone.png", price: 32000);
    productList.addAll([u1, u2, u3, u4, u5, u6, u7]);
    return productList;
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
        appBar: AppBar(
          title: const Text("Products"),
        ),
        body: SingleChildScrollView(
          child: FutureBuilder<List<Products>>(
              future: uploadProducts(),
              builder: (context, snapshot) {
                if (snapshot.hasData) {
                  var productsList = snapshot.data;
                  return ListView.builder(
                    shrinkWrap: true, // İç içe kaydırma hatasını önler
                    physics:
                        NeverScrollableScrollPhysics(), // Liste kendi kaydırmasını yapmaz
                    itemCount: productsList!.length,
                    itemBuilder: (context, index) {
                      var product = productsList[index];
                      return GestureDetector(
                        onTap: () {
                          Navigator.push(
                              context,
                              MaterialPageRoute(
                                  builder: (context) =>
                                      Detail(product: product)));
                        },
                        child: Card(
                          child: Row(
                            children: [
                              SizedBox(
                                  width: 128,
                                  height: 128,
                                  child:
                                      Image.asset("photos/${product.photo}")),
                              Column(
                                crossAxisAlignment: CrossAxisAlignment.start,
                                children: [
                                  Text(product.name),
                                  SizedBox(
                                    height: 10,
                                  ),
                                  Padding(
                                    padding: const EdgeInsets.all(8.0),
                                    child: Text(
                                      "${product.price}₺",
                                      style: TextStyle(fontSize: 20),
                                    ),
                                  ),
                                  ElevatedButton(
                                      onPressed: () {
                                        print("${product.name} added to cart");
                                      },
                                      child: Text("Add to cart"))
                                ],
                              )
                            ],
                          ),
                        ),
                      );
                    },
                  );
                } else {
                  return const Center(child: CircularProgressIndicator());
                }
              }),
        ));
  }
}
