import 'package:flutter/material.dart';

class user_interaction extends StatefulWidget {
  const user_interaction({super.key});

  @override
  State<user_interaction> createState() => _user_interactionState();
}

class _user_interactionState extends State<user_interaction> {
  var ct = TextEditingController();
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text(
          "User Interaction",
          style: TextStyle(fontWeight: FontWeight.bold, color: Colors.black),
        ),
        backgroundColor: Colors.green,
      ),
      body: Center(
        child:
            Column(mainAxisAlignment: MainAxisAlignment.spaceEvenly, children: [
          ElevatedButton(
              onPressed: () {
                ScaffoldMessenger.of(context).showSnackBar(SnackBar(
                  backgroundColor: Colors.red,
                  content: const Text(
                    "Want to delete?",
                    style: TextStyle(
                        fontWeight: FontWeight.bold, color: Colors.amber),
                  ),
                  action: SnackBarAction(
                      label: "Yes",
                      onPressed: () {
                        ScaffoldMessenger.of(context).showSnackBar(
                            SnackBar(content: const Text("Deleted")));
                      }),
                ));
              },
              child: Text("Snackbar")),
          ElevatedButton(onPressed: () {}, child: Text("Snackbar (Special)")),
          ElevatedButton(
            onPressed: () {
              showDialog(
                context: context,
                builder: (BuildContext context) {
                  return AlertDialog(
                    title: const Text("Title"),
                    content: TextField(
                      controller: ct,
                      decoration:
                          const InputDecoration(hintText: "HINTED TEXT"),
                    ),
                    actions: [
                      TextButton(
                        onPressed: () {
                          Navigator.pop(context);
                          ct.text = "";
                        },
                        child: const Text("Cancel"),
                      ),
                    ],
                  );
                },
              );
            },
            child: const Text("Alert"),
          ),
          ElevatedButton(onPressed: () {}, child: Text("Alert (Special)"))
        ]),
      ),
    );
  }
}
