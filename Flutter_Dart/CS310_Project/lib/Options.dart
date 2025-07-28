import 'package:flutter/material.dart';
import 'package:flutter_demo/categories.dart';
import 'package:flutter_demo/utils.dart';

class SettingsPage extends StatefulWidget {
  const SettingsPage({super.key});

  @override
  State<SettingsPage> createState() => _SettingsPageState();
}

class _SettingsPageState extends State<SettingsPage> {
  bool _notificationsEnabled = true;

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: Utilities.appBar("SuConnect", Colors.white),
      body: ListView(
        children: [
          Utilities.sectionTitle('Account'),
          Utilities.customTile(context: context, title: 'Name'),
          Utilities.customTile(context: context, title: 'Last Name'),
          Utilities.customTile(context: context, title: 'Age'),
          const SizedBox(height: 60),
          Utilities.sectionTitleWithIcon('Notifications', Icons.notifications_none),
          SwitchListTile(
            title: const Text('Allow Notifications', style: TextStyle(fontSize: 16)),
            value: _notificationsEnabled,
            onChanged: (bool value) {
              setState(() {
                _notificationsEnabled = value;
              });
            },
            activeColor: Colors.blue,
            contentPadding: const EdgeInsets.symmetric(horizontal: 16),
          ),
          Utilities.customTile(
            context: context,
            title: 'Categories',
            destinationPage: const CategoriesPage(),
          ),

          const SizedBox(height: 20),
          const SizedBox(height: 60),
          Utilities.sectionTitle('Locations'),
          Utilities.customTile(context: context, title: 'Campus'),
          Utilities.customTile(context: context, title: 'Istanbul'),
          Utilities.customTile(context: context, title: 'Other'),
          Utilities.logOut(context: context, title: 'LogOut')
        ],
      ),
    );
  }
}
