import 'package:flutter/material.dart';
import 'package:flutter_bloc/flutter_bloc.dart';
import 'package:flutter_blocpattern/ui/cubit/homepage_cubit.dart';

class Homepage extends StatefulWidget {
  const Homepage({super.key});

  @override
  State<Homepage> createState() => _HomepageState();
}

class _HomepageState extends State<Homepage> {
  var tf1 = TextEditingController();
  var tf2 = TextEditingController();

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(title: Text("Bloc Pattern")),
      body: Center(
        child: Padding(
          padding: const EdgeInsets.only(left: 50.0, right: 50.0),
          child: Column(
            mainAxisAlignment: MainAxisAlignment.spaceEvenly,
            children: [
              BlocBuilder<HomepageCubit, int>(
                builder: (context, sonuc) {
                  return Text(sonuc.toString(), style: TextStyle(fontSize: 50));
                },
              ),

              TextField(
                controller: tf1,

                decoration: InputDecoration(hintText: ("Number 1")),
              ),
              TextField(
                controller: tf2,
                keyboardType: TextInputType.number,
                decoration: InputDecoration(hintText: ("Number 2")),
              ),
              Row(
                mainAxisAlignment: MainAxisAlignment.spaceEvenly,
                children: [
                  ElevatedButton(
                    onPressed: () {
                      context.read<HomepageCubit>().doSum(tf1.text, tf2.text);
                    },
                    child: Text("SUM"),
                  ),
                  ElevatedButton(
                    onPressed: () {
                      context.read<HomepageCubit>().doProduct(
                        tf1.text,
                        tf2.text,
                      );
                    },
                    child: Text("PRODUCT"),
                  ),
                ],
              ),
            ],
          ),
        ),
      ),
    );
  }
}
