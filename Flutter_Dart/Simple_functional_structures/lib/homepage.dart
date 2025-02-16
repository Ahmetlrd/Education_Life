import 'dart:math';

import 'package:flutter/material.dart';

class Homepage extends StatefulWidget {
  const Homepage({super.key});

  @override
  State<Homepage> createState() => _HomepageState();
}

class _HomepageState extends State<Homepage> {
  var data = TextEditingController();
  bool switchControl = false;
  bool checkboxControl = false;
  String gotData = "";
  int radioval = 0;
  double stick = 30.0;
  var tfClock = TextEditingController();

  var tfDate = TextEditingController();
  var countryList = <String>[];
  String varsayilan = "Türkiye";
  @override
  void initState() {
    super.initState();
    countryList.add("Türkiye");
    countryList.add("Italy");
    countryList.add("Japan");
  }

  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text("WIDGETS"),
        titleTextStyle: TextStyle(
            color: Colors.white, fontSize: 20, fontWeight: FontWeight.bold),
        backgroundColor: Colors.redAccent,
      ),
      body: SingleChildScrollView(
        child: Center(
          child: Column(
            children: [
              Text(gotData),
              Padding(
                padding: const EdgeInsets.all(8.0),
                child: TextField(
                  controller: data,
                  keyboardType: TextInputType.number,
                  obscureText: true,
                  decoration: const InputDecoration(hintText: "Veri"),
                ),
              ),
              ElevatedButton(
                  onPressed: () {
                    setState(() {
                      FocusScope.of(context).unfocus();
                      gotData = data.text;
                    });
                  },
                  child: Text("Click")),
              Row(
                mainAxisAlignment: MainAxisAlignment.spaceEvenly,
                children: [
                  SizedBox(
                    width: 200,
                    child: SwitchListTile(
                        title: const Text("Dart"),
                        controlAffinity: ListTileControlAffinity.leading,
                        value: switchControl,
                        onChanged: (y) {
                          setState(() {
                            switchControl = y;
                          });
                        }),
                  ),
                  SizedBox(
                    width: 180,
                    child: CheckboxListTile(
                        title: Text("Flutter"),
                        controlAffinity: ListTileControlAffinity.leading,
                        value: checkboxControl,
                        onChanged: (y) {
                          setState(() {
                            checkboxControl = y!;
                          });
                        }),
                  ),
                ],
              ),
              Row(
                mainAxisAlignment: MainAxisAlignment.spaceEvenly,
                children: [
                  SizedBox(
                    width: 200,
                    child: RadioListTile(
                        title: const Text("Madrid"),
                        value: 1,
                        groupValue: radioval,
                        onChanged: (y) {
                          setState(() {
                            radioval = y!;
                          });
                        }),
                  ),
                  SizedBox(
                    width: 180,
                    child: RadioListTile(
                        title: Text("Barcelona"),
                        value: 2,
                        groupValue: radioval,
                        onChanged: (y) {
                          setState(() {
                            radioval = y!;
                          });
                        }),
                  ),
                ],
              ),
              if (switchControl) Text("Clicked"),
              if (checkboxControl) Text("Clicked"),
              Visibility(
                  visible: true, child: const CircularProgressIndicator()),
              Text(stick.toInt().toString()),
              Slider(
                  max: 100.0,
                  min: 0.0,
                  value: stick,
                  onChanged: (k) {
                    setState(() {
                      stick = k;
                    });
                  }),
              Row(
                mainAxisAlignment: MainAxisAlignment.spaceEvenly,
                children: [
                  SizedBox(
                    width: 120,
                    child: TextField(
                      controller: tfClock,
                      decoration: const InputDecoration(
                        hintText: "Clock",
                      ),
                    ),
                  ),
                  IconButton(
                    onPressed: () {
                      showTimePicker(
                        context: context,
                        initialTime: TimeOfDay.fromDateTime(DateTime.now()),
                      ).then((value) {
                        if (value != null) {
                          // Kullanıcı iptal ederse hata olmaması için
                          tfClock.text = "${value.hour}:${value.minute}";
                        }
                      });
                    },
                    icon: const Icon(Icons.access_time),
                  ),
                  SizedBox(
                    width: 120,
                    child: TextField(
                      controller: tfDate,
                      decoration: const InputDecoration(
                        hintText: "Date",
                      ),
                    ),
                  ),
                  IconButton(
                    onPressed: () {
                      showDatePicker(
                        context: context,
                        initialDate: DateTime.now(),
                        firstDate: DateTime(2000),
                        lastDate: DateTime(2030),
                      ).then((value) {
                        if (value != null) {
                          tfDate.text =
                              "${value.day} / ${value.month} / ${value.year}";
                        }
                      });
                    },
                    icon: const Icon(Icons.date_range),
                  ),
                ],
              ),
              DropdownButton(
                  value: varsayilan,
                  icon: Icon(Icons.arrow_drop_down),
                  items: countryList.map((country) {
                    return DropdownMenuItem(
                      value: country,
                      child: Text(country),
                    );
                  }).toList(),
                  onChanged: (data) {
                    setState(() {
                      varsayilan = data!;
                    });
                  }),
              GestureDetector(
                onTap: () {
                  print("31");
                },
                child: Container(
                  width: 200,
                  height: 100,
                  color: Colors.red,
                ),
              )
            ],
          ),
        ),
      ),
    );
  }
}
