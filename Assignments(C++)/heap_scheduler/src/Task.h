//Ahmet Çavuşoğlu 32394

#ifndef TASK_H
#define TASK_H

#include <iostream>
using namespace std;

// I create Task class

class Task {
public:
    int taskid;
    int priority;
    string location;
    string category;

    // I write constructor here
    Task(int id, int prio, const string& loc = "", const string& cat = "")
        : taskid(id), priority(prio), location(loc), category(cat) {}
};

#endif // TASK_H
