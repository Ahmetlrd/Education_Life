import 'package:cloud_firestore/cloud_firestore.dart';
import 'package:firebase_auth/firebase_auth.dart';
import 'package:flutter/material.dart';
import 'package:flutter_demo/Options.dart';
import 'Create_Event_Screen.dart';
import 'Upcoming_events.dart';
import 'utils.dart';  // SuEvent modelinin olduğu dosya

class EventListScreen extends StatefulWidget {
  const EventListScreen({super.key});

  @override
  State<EventListScreen> createState() => _EventListScreenState();
}

class _EventListScreenState extends State<EventListScreen> {
  final CollectionReference eventsCollection =
      FirebaseFirestore.instance.collection('events');

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        elevation: 1,
        title: Row(
          mainAxisAlignment: MainAxisAlignment.spaceBetween,
          children: [
             const Text(
              'SuConnect',
              style: TextStyle(fontSize: 30, fontWeight: FontWeight.bold),
            ),
            IconButton(
              icon: const Icon(Icons.settings),
              onPressed: () {
                // Navigate to Settings page when settings icon is pressed
                Navigator.push(
                  context,
                  MaterialPageRoute(builder: (context) => const SettingsPage()), // Settings page
                );
              },
            ),
            const SizedBox(width: 48),
          ],
        ),
      ),
      body: Column(
        children: [
          GestureDetector(
            onTap: () {
              Navigator.push(
                context,
                MaterialPageRoute(builder: (context) => const UpcomingEventsPage()),
              );
            },
            child: Padding(
              padding: const EdgeInsets.symmetric(vertical: 16.0, horizontal: 16.0),
              child: Row(
                mainAxisAlignment: MainAxisAlignment.spaceBetween,
                children: const [
                  Text(
                    'Upcoming Events',
                    style: TextStyle(
                      fontSize: 24,
                      fontWeight: FontWeight.bold,
                      color: Colors.black,
                    ),
                  ),
                  Icon(Icons.calendar_today, size: 24, color: Colors.black),
                ],
              ),
            ),
          ),

          Expanded(
            child: StreamBuilder<QuerySnapshot>(
              stream: eventsCollection.orderBy('date').snapshots(),
              builder: (context, snapshot) {
                if (snapshot.hasError) {
                  return Center(child: Text('Bir hata oluştu: ${snapshot.error}'));
                }
                if (snapshot.connectionState == ConnectionState.waiting) {
                  return const Center(child: CircularProgressIndicator());
                }
                if (!snapshot.hasData || snapshot.data!.docs.isEmpty) {
                  return const Center(child: Text('Hiç etkinlik bulunamadı.'));
                }

                final events = snapshot.data!.docs.map((doc) {
                  final data = doc.data() as Map<String, dynamic>;

                  DateTime parsedDate;
                  final dateData = data['date'];

                  if (dateData is Timestamp) {
                    parsedDate = dateData.toDate();
                  } else if (dateData is String) {
                    parsedDate = DateTime.tryParse(dateData) ?? DateTime.now();
                  } else {
                    parsedDate = DateTime.now();
                  }

                  return {
                  'event': SuEvent(
                    title: data['title'] ?? '',
                    date: parsedDate,
                    duration: data['duration']?.toString() ?? '',
                    category: data['category']?.toString() ?? '',
                    info: data['info']?.toString() ?? '',
                  ),
                  'docId': doc.id,
                  'attendees': data['attendees'] ?? 0,
                  'creator': data['creator'] ?? 'Unknown',
                   };
                }).toList();

                return ListView.builder(
                  itemCount: events.length,
                  itemBuilder: (context, index) {
                  final eventData = events[index] as Map<String, dynamic>;
                  final SuEvent event = eventData['event'];
                  final String docId = eventData['docId'];
                  final int attendees = eventData['attendees'];
                  final String creator = eventData['creator'];
                  final currentUser = FirebaseAuth.instance.currentUser;
                  final String? currentEmail = currentUser?.email;

                    return Container(
                      decoration: const BoxDecoration(
                        border: Border(
                          bottom: BorderSide(color: Color(0xFFE0E0E0), width: 1),
                        ),
                      ),
                      child: Theme(
                        data: Theme.of(context).copyWith(dividerColor: Colors.transparent),
                        child: ExpansionTile(
                          tilePadding: const EdgeInsets.symmetric(horizontal: 16),
                          childrenPadding: const EdgeInsets.symmetric(horizontal: 16),
                          title: Text(event.title),
                          subtitle: Text(
                              '${event.date.toLocal().toString().split(" ")[0]} • ${event.category}'),
                          children: [
                            const SizedBox(height: 8),
                            Text('Duration: ${event.duration}'),
                            const SizedBox(height: 4),
                            Text('Info: ${event.info}'),
                            const SizedBox(height: 12),
                              Text('Created by: $creator'),
                              const SizedBox(height: 4),
                              Text('Attendees: $attendees'),
                              const SizedBox(height: 12),
                              if (creator == currentEmail ) ...[
                                const SizedBox(height: 8),
                                ElevatedButton.icon(
                                  onPressed: () async {
                                  await eventsCollection.doc(docId).delete();
                                  ScaffoldMessenger.of(context).showSnackBar(
                                    SnackBar(content: Text('${event.title} deleted.')),
                                    );
                                     },
                                icon: const Icon(Icons.delete,color: Colors.white),
                                label: const Text('Delete'),
                                 style: ElevatedButton.styleFrom(
                                  backgroundColor: Colors.red,
                                  foregroundColor: Colors.white,
                                  shape: RoundedRectangleBorder(
                                  borderRadius: BorderRadius.circular(8),
                                   ),
                                  ),
                                  ),
                              ],

                            ElevatedButton(
                              onPressed: ()  async {
                                 await eventsCollection.doc(docId).update({
                                  'attendees': FieldValue.increment(1),
                                   });
                                ScaffoldMessenger.of(context).showSnackBar(
                                  SnackBar(content: Text('You have joined ${event.title}')),
                                );
                              },
                              child: const Text('Join'),
                              style: ElevatedButton.styleFrom(
                                backgroundColor: Colors.blue,
                                foregroundColor: Colors.white,
                                shape: RoundedRectangleBorder(
                                  borderRadius: BorderRadius.circular(8),
                                ),
                              ),
                            ),
                            const SizedBox(height: 12),
                          ],
                        ),
                      ),
                    );
                  },
                );
              },
            ),
          ),
        ],
      ),
      floatingActionButton: FloatingActionButton(
        onPressed: () async {
          final newEvent = await Navigator.push<SuEvent>(
            context,
            MaterialPageRoute(builder: (context) => const CreateEventScreen()),
          );
        final currentUser = FirebaseAuth.instance.currentUser;
        final userEmail = currentUser?.email!;
          if (newEvent != null) {
            await eventsCollection.add({
              'title': newEvent.title,
              'date': Timestamp.fromDate(newEvent.date),
              'duration': newEvent.duration,
              'category': newEvent.category,
              'info': newEvent.info,
              'attendees': 0,
              'creator': userEmail,
            });

            ScaffoldMessenger.of(context).showSnackBar(
              const SnackBar(content: Text('Yeni etkinlik eklendi!')),
            );
          }
        },
        child: const Icon(Icons.add),
        backgroundColor: Colors.blue,
      ),
    );
  }
}
