import 'package:flutter/material.dart';

class HomePage extends StatefulWidget {
  const HomePage({super.key});

  @override
  State<HomePage> createState() => _HomePageState();
}

class _HomePageState extends State<HomePage> {
  List<String> equation = [];
  var data = "Result: ";
  @override
  Widget build(BuildContext context) {
    return Scaffold(
        backgroundColor: Colors.blueGrey,
        appBar: AppBar(
          title: Text(
            "CALCULATOR",
            style: TextStyle(
                color: Colors.teal[50],
                fontWeight: FontWeight.w900,
                fontSize: 31),
          ),
          backgroundColor: Colors.black54,
        ),
        body: Column(
          mainAxisAlignment: MainAxisAlignment.spaceEvenly,
          children: [
            Padding(
              padding: const EdgeInsets.only(left: 16, right: 16),
              child: SizedBox(
                  width: 300,
                  height: 100,
                  child: Text(
                    data,
                    style: TextStyle(
                        fontSize: 25,
                        fontWeight: FontWeight.bold,
                        color: Colors.white),
                  )),
            ),
            Row(
              mainAxisAlignment: MainAxisAlignment.spaceEvenly,
              children: [
                ElevatedButton(
                    onPressed: () {
                      setState(() {
                        data += "1";
                        equation.add("1");
                      });
                    },
                    child: Text(
                      "1",
                      style: TextStyle(fontSize: 50),
                    )),
                ElevatedButton(
                    onPressed: () {
                      setState(() {
                        data += "2";
                        equation.add("2");
                      });
                    },
                    child: Text(
                      "2",
                      style: TextStyle(fontSize: 50),
                    )),
                ElevatedButton(
                    onPressed: () {
                      setState(() {
                        data += "3";
                        equation.add("3");
                      });
                    },
                    child: Text(
                      "3",
                      style: TextStyle(fontSize: 50),
                    )),
                ElevatedButton(
                    onPressed: () {
                      setState(() {
                        data = "Result : ";
                        equation.clear();
                      });
                    },
                    child: Text(
                      "AC",
                      style: TextStyle(fontSize: 50),
                    )),
              ],
            ),
            Row(
              mainAxisAlignment: MainAxisAlignment.spaceEvenly,
              children: [
                ElevatedButton(
                    onPressed: () {
                      setState(() {
                        data += "4";
                        equation.add("4");
                      });
                    },
                    child: Text(
                      "4",
                      style: TextStyle(fontSize: 50),
                    )),
                ElevatedButton(
                    onPressed: () {
                      setState(() {
                        data += "5";
                        equation.add("5");
                      });
                    },
                    child: Text(
                      "5",
                      style: TextStyle(fontSize: 50),
                    )),
                ElevatedButton(
                    onPressed: () {
                      setState(() {
                        data += "6";
                        equation.add("6");
                      });
                    },
                    child: Text(
                      "6",
                      style: TextStyle(fontSize: 50),
                    )),
                ElevatedButton(
                    onPressed: () {
                      setState(() {
                        data += "+";
                        equation.add("+");
                      });
                    },
                    child: Text(
                      "+",
                      style: TextStyle(fontSize: 50),
                    )),
              ],
            ),
            Row(
              mainAxisAlignment: MainAxisAlignment.spaceEvenly,
              children: [
                ElevatedButton(
                    onPressed: () {
                      setState(() {
                        data += "7";
                        equation.add("7");
                      });
                    },
                    child: Text(
                      "7",
                      style: TextStyle(fontSize: 50),
                    )),
                ElevatedButton(
                    onPressed: () {
                      setState(() {
                        data += "8";
                        equation.add("8");
                      });
                    },
                    child: Text(
                      "8",
                      style: TextStyle(fontSize: 50),
                    )),
                ElevatedButton(
                    onPressed: () {
                      setState(() {
                        data += "9";
                        equation.add("9");
                      });
                    },
                    child: Text(
                      "9",
                      style: TextStyle(fontSize: 50),
                    )),
                ElevatedButton(
                    onPressed: () {
                      setState(() {
                        data = "Result : ${(calculate(equation))}";
                      });
                    },
                    child: Text(
                      "=",
                      style: TextStyle(fontSize: 50),
                    )),
              ],
            ),
          ],
        ));
  }
}

String calculate(List<String> equation) {
  List<String> numbers = equation.join("").split("+");
  int sum = 0;
  for (int i = 0; i < numbers.length; i++) {
    if (int.tryParse(numbers[i]) != null) {
      sum += int.parse(numbers[i]);
    }
  }
  return sum.toString();
}
