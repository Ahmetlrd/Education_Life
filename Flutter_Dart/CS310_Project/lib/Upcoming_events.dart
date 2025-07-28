import 'package:flutter/material.dart';
import 'package:table_calendar/table_calendar.dart';
import 'utils.dart';




class UpcomingEventsPage extends StatefulWidget {
  const UpcomingEventsPage({super.key});

  @override
  State<UpcomingEventsPage> createState() => _UpcomingEventsPageState();
}

class _UpcomingEventsPageState extends State<UpcomingEventsPage> {
  late Map<DateTime, List<SuEvent>> _events;
  DateTime _focusedDay = DateTime.now();
  DateTime? _selectedDay;

  @override
  void initState() {
    super.initState();

    _events = {
      DateTime.utc(2025, 4, 14): [
        SuEvent(
          title: 'Art Exhibition',
          date: DateTime(2025, 4, 20),
          duration: '2h',
          category: 'Art',
          info: 'Modern art display at campus center.',
        ),
      ],
      DateTime.utc(2025, 4, 16): [
        SuEvent(
          title: 'Hackathon',
          date: DateTime(2025, 4, 16),
          duration: '24h',
          category: 'Tech',
          info: '24-hour coding challenge with prizes.',
        ),
      ],
    };
  }

  List<SuEvent> _getEventsForDay(DateTime day) {
    return _events[DateTime.utc(day.year, day.month, day.day)] ?? [];
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(title: const Text("Upcoming Events")),
      body: Column(
        children: [
          TableCalendar<SuEvent>(
            focusedDay: _focusedDay,
            firstDay: DateTime.utc(2020, 1, 1),
            lastDay: DateTime.utc(2030, 12, 31),
            calendarFormat: CalendarFormat.month,
            selectedDayPredicate: (day) => isSameDay(_selectedDay, day),
            eventLoader: _getEventsForDay,
            onDaySelected: (selectedDay, focusedDay) {
              setState(() {
                _selectedDay = selectedDay;
                _focusedDay = focusedDay;
              });
            },
            calendarStyle: const CalendarStyle(
              todayDecoration: BoxDecoration(
                color: Colors.orange,
                shape: BoxShape.circle,
              ),
              selectedDecoration: BoxDecoration(
                color: Colors.blue,
                shape: BoxShape.circle,
              ),
              markerDecoration: BoxDecoration(
                color: Colors.red,
                shape: BoxShape.circle,
              ),
            ),
          ),
          const SizedBox(height: 10),
          Expanded(
            child: ListView(
              children: _getEventsForDay(_selectedDay ?? _focusedDay)
                  .map(
                    (event) => ListTile(
                      title: Text(event.title),
                      subtitle: Text("${event.category} • ${event.duration}"),
                      trailing: const Icon(Icons.event),
                      onTap: () => _showEventInfo(context, event),
                    ),
                  )
                  .toList(),
            ),
          )
        ],
      ),
    );
  }

  void _showEventInfo(BuildContext context, SuEvent event) {
    showDialog(
      context: context,
      builder: (_) => AlertDialog(
        title: Text(event.title),
        content: Text(event.info),
        actions: [
          TextButton(
            child: const Text("Close"),
            onPressed: () => Navigator.pop(context),
          )
        ],
      ),
    );
  }
}
