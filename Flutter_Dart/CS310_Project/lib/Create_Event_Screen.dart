import 'package:flutter/material.dart';
import 'package:flutter_demo/main_screen.dart';
import 'utils.dart';

class CreateEventScreen extends StatefulWidget {
  const CreateEventScreen({super.key});

  @override
  State<CreateEventScreen> createState() => _CreateEventScreenState();
}

class _CreateEventScreenState extends State<CreateEventScreen> {
  final _formKey = GlobalKey<FormState>();

  final TextEditingController user_title_controller = TextEditingController();
  final TextEditingController user_date_controller = TextEditingController();
  final TextEditingController user_duration_controller = TextEditingController();
  final TextEditingController user_category_controller = TextEditingController();
  final TextEditingController user_info_controller = TextEditingController();
  final TextEditingController user_hour_controller = TextEditingController();

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: Utilities.appBar("Create Event",Colors.white),
      
      body: Padding(
        padding: const EdgeInsets.all(20.0),
        child: Form(
          key: _formKey,
          child: ListView(
            children: [
              Utilities.customTextField(
                controller: user_title_controller,
                label: "Event Title",
                
              ),
              
              const SizedBox(height: 12),
              Utilities.customTextField(
                controller: user_date_controller,
                label: "Date (YYYY-MM-DD) Year/Month/Day",
              ),
              
              const SizedBox(height: 12),
              Utilities.customTextField(
                controller: user_hour_controller,
                label: "Exact hour and minute (HH:mm)"
              ),

              const SizedBox(height: 12,),

              Utilities.customTextField(
                controller: user_duration_controller,
                label: "Duration (Hours)",
              ),
              
              const SizedBox(height: 12),
              Utilities.customTextField(
                controller: user_category_controller,
                label: "Category",
              ),
              
              const SizedBox(height: 12),
              Utilities.customTextField(
                controller: user_info_controller,
                label: "Specific information (Required)",
              ),
              
              const SizedBox(height: 20),
              Utilities.createEventButton(
                formKey: _formKey,
                titleController: user_title_controller,
                dateController: user_date_controller,
                durationController: user_duration_controller,
                categoryController: user_category_controller,
                infoController: user_info_controller,
                context: context,
                hour_controller: user_hour_controller,
              )
            ],
          ),
        ),
      ),
    );
  }
}
