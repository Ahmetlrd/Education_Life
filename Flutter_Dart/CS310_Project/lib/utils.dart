import 'package:firebase_auth/firebase_auth.dart';
import 'package:flutter/material.dart';
import "app_state.dart";
import 'package:cloud_firestore/cloud_firestore.dart';

class SuEvent {
  final String title;
  final DateTime date;
  final String duration;
  final String category;
  final String info;

  SuEvent({
    required this.title,
    required this.date,
    required this.duration,
    required this.category,
    required this.info,
  });
}

class Utilities {
  static AppBar appBar(String title, Color color_) {
    return AppBar(
      title: Text(
        title,
        style: const TextStyle(fontSize: 30, fontWeight: FontWeight.bold),
      ),
      centerTitle: true,
      backgroundColor: color_, // veya istediğin renk
    );
  }

  static TextFormField customTextField({
    required String label,
    required TextEditingController controller,
    int maxLines = 1,
    String? Function(String?)? validator,
  }) {
    return TextFormField(
      controller: controller,
      maxLines: maxLines,
      decoration: InputDecoration(
        labelText: label,
        border: const OutlineInputBorder(),
      ), 
      validator:
          validator ??
          (value) {
            if (value == null || value.isEmpty) {
              return 'Please enter $label';
            }
            return null;
          },
    );
  }

  static Text privacy_info() {
    return Text(
      "By using this app, you agree to our Terms of Service and Privacy Policy. We respect your privacy and only collect the information necessary to provide and improve our services. Your data will never be shared with third parties without your consent. You can read the full Terms and Policy in the settings menu. If you have any questions, feel free to contact us.",
      style: TextStyle(fontSize: 20),
    );
  }

 
static ElevatedButton createEventButton({
  required GlobalKey<FormState> formKey,
  required TextEditingController titleController,
  required TextEditingController dateController,
  required TextEditingController durationController,
  required TextEditingController categoryController,
  required TextEditingController infoController,
  required BuildContext context,
  required TextEditingController hour_controller,
}) {
  return ElevatedButton(
    onPressed: () async {
      if (formKey.currentState!.validate()) {
        // Saat doğrulama
        final timeInput = hour_controller.text.trim();
        final timeRegex = RegExp(r'^\d{2}:\d{2}$');

        if (!timeRegex.hasMatch(timeInput)) {
          ScaffoldMessenger.of(context).showSnackBar(
            const SnackBar(content: Text("Invalid time format. Use HH:mm (e.g., 14:30)")),
          );
          return;
        }

        
        final parts = timeInput.split(":");
        final hour = int.tryParse(parts[0]);
        final minute = int.tryParse(parts[1]);

        if (hour == null || minute == null || hour < 0 || hour > 23 || minute < 0 || minute > 59) {
          ScaffoldMessenger.of(context).showSnackBar(
            const SnackBar(content: Text("Hour must be 00-23 and minute must be 00-59")),
          );
          return;
        }

        SuEvent? newEvent;
        try {
          final parsedDate = DateTime.parse("${dateController.text} $timeInput");

          newEvent = SuEvent(
            title: titleController.text,
            date: parsedDate,
            duration: durationController.text,
            category: categoryController.text,
            info: infoController.text,
          );
        } catch (e) {
          ScaffoldMessenger.of(context).showSnackBar(
            const SnackBar(content: Text("Invalid date format. Use YYYY-MM-DD")),
          );
          return;
        }

        try {
          await FirebaseFirestore.instance.collection('events').add({
            'title': newEvent.title,
            'date': newEvent.date.toIso8601String(),
            'duration': newEvent.duration,
            'category': newEvent.category,
            'info': newEvent.info,
            'attendees': 0
          });

          ScaffoldMessenger.of(context).showSnackBar(
            const SnackBar(
              content: Text('Event Successfully Created!'),
              backgroundColor: Colors.green,
            ),
          );

          Future.delayed(const Duration(milliseconds: 800), () {
            Navigator.pop(context, newEvent);
          });
        } catch (e) {
          ScaffoldMessenger.of(context).showSnackBar(
            SnackBar(
              content: Text('Firebase error: ${e.toString()}'),
              backgroundColor: Colors.red,
            ),
          );
        }
      }
    },
    style: ElevatedButton.styleFrom(
      backgroundColor: Colors.black,
      padding: const EdgeInsets.all(16),
      shape: RoundedRectangleBorder(borderRadius: BorderRadius.circular(8)),
    ),
    child: const Text(
      'Create Event',
      style: TextStyle(color: Colors.white, fontSize: 16),
    ),
  );
}





  static Padding customPaddingTextField({
    required String label,
    required TextEditingController controller,
    EdgeInsetsGeometry padding = const EdgeInsets.all(10),
    TextInputType keyboardType = TextInputType.text,
  }) {
    return Padding(
      padding: padding,
      child: TextField(
        controller: controller,
        keyboardType: keyboardType,
        decoration: InputDecoration(
          labelText: label,
          border: const OutlineInputBorder(),
        ),
      ),
    );
  }

  static Widget buildAuthButton({
    required BuildContext context,
    required String label,
    required Widget destination,
  }) {
    return TextButton(
      onPressed: () {
        Navigator.push(
          context,
          MaterialPageRoute(builder: (context) => destination),
        );
      },
      style: TextButton.styleFrom(
        minimumSize: const Size(150, 60),
        backgroundColor: Colors.black,
        shape: const RoundedRectangleBorder(
          borderRadius: BorderRadius.all(Radius.circular(8)),
        ),
      ),
      child: Text(label, style: const TextStyle(color: Colors.white)),
    );
  }

  static Text buildText({required String label, required double size}) {
    return Text(label, style: TextStyle(fontSize: size,fontWeight: FontWeight.bold));
  }

  static Widget sectionTitle(String title) {
  return Padding(
    padding: const EdgeInsets.fromLTRB(16, 20, 0, 10),
    child: Text(
      title,
      style: const TextStyle(fontSize: 18, fontWeight: FontWeight.w800),
    ),
  );
}

static Widget sectionTitleWithIcon(String title, IconData icon) {
  return Padding(
    padding: const EdgeInsets.fromLTRB(16, 20, 0, 10),
    child: Row(
      children: [
        Text(
          title,
          style: const TextStyle(fontSize: 18, fontWeight: FontWeight.w800),
        ),
        const SizedBox(width: 8),
        Icon(icon, size: 20),
      ],
    ),
  );
}

static Widget customTile({
  required BuildContext context,
  required String title,
  Widget? destinationPage,
}) {
  return ListTile(
    title: Text(
      title,
      style: const TextStyle(fontSize: 16),
    ),
    onTap: destinationPage != null
        ? () {
            Navigator.push(
              context,
              MaterialPageRoute(builder: (context) => destinationPage),
            );
          }
        : null,
    tileColor: Colors.white,
    contentPadding: const EdgeInsets.symmetric(horizontal: 16),
  );
}

static Widget logOut({
  required BuildContext context,
  required String title,
}) {
  return ListTile(
    title: Text(
      title,
      style: const TextStyle(fontSize: 16),
    ),
    onTap: () async {
      await FirebaseAuth.instance.signOut();
      Navigator.pop(context);
    },
    tileColor: Colors.white,
    contentPadding: const EdgeInsets.symmetric(horizontal: 16),
  );
}

}

// options







