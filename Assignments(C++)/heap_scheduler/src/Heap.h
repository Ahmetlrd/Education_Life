//Ahmet Çavuşoğlu 32394

#ifndef HEAP_H
#define HEAP_H

// Abstract Heap class for common heap operations

class Heap {
public:
    virtual void insert(int taskid, int priority) = 0; // insert new task
    virtual int extract_min() = 0; // return task with smallest priority
    virtual void decrease_key(int taskid, int newpriority) = 0; // I decrease the priority
    virtual void merge_with(Heap& other) = 0; // merge with another heap
    virtual void print_heap() const = 0; // print all tasks
    virtual ~Heap() = default; // destructor is default
};

#endif
