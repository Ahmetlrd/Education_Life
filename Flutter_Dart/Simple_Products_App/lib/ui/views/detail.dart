import 'package:flutter/material.dart';
import 'package:flutter_productsapp/data/entity/products.dart';

class Detail extends StatefulWidget {
  Products product;
  Detail({
    required this.product,
  });

  @override
  State<Detail> createState() => _DetailState();
}

class _DetailState extends State<Detail> {
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text(widget.product.name),
      ),
      body: Center(
        child: Column(
          mainAxisAlignment: MainAxisAlignment.spaceEvenly,
          children: [
            SizedBox(
                width: 600,
                height: 600,
                child: Image.asset("photos/${widget.product.photo}")),
            Text(
              "${widget.product.price}₺",
              style: TextStyle(fontSize: 50),
            ),
          ],
        ),
      ),
    );
  }
}
