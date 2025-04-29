//Ahmet Çavuşoğlu 32394

#ifndef DARY_HEAP_H
#define DARY_HEAP_H

#include "Heap.h"
#include "Task.h"
#include <vector>
#include <unordered_map>

// DaryHeap class with d children instead of 2

class DaryHeap : public Heap {
public:
    explicit DaryHeap(int d); // I set how many children each node has
    void insert(int task_id, int priority) override; // insert a task
    int extract_min() override; // get smallest priority task
    void decrease_key(int task_id, int new_priority) override; // change priority
    void merge_with(Heap& other) override; // merge another heap
    void print_heap() const override; // print tasks

private:
    int d; // number of children per node
    vector<Task*> heap; // heap as vector
    unordered_map<int, size_t> inxmap; // task id to index

    void shiftd(size_t i); // move up if smaller
    void shiftu(size_t i); // move down if bigger
    size_t parentinx(size_t i) const; // calculate parent index
    size_t childidx(size_t i, int k) const; // calculate k-th child index
};

#endif
