//Ahmet Çavuşoğlu 32394

#include "DaryHeap.h"
#include <iostream>

// constructor for DaryHeap
DaryHeap::DaryHeap(int d) : d(d) {}

void DaryHeap::insert(int taskid, int priority) {
    Task* t = new Task(taskid, priority); // create new task
    heap.push_back(t); // add to heap
    size_t index = heap.size() - 1;
    inxmap[taskid] = index; // save index
    shiftd(index); // move up if needed
}

int DaryHeap::extract_min() {
    if (heap.empty()) return -1; // if no task return -1
    int minid = heap[0]->taskid;
    delete heap[0]; // delete min task
    Task* last = heap.back(); // take last task
    heap.pop_back();
    if (!heap.empty()) {
        heap[0] = last;
        inxmap[last->taskid] = 0;
        shiftd(0); // move down if needed
    }
    inxmap.erase(minid); // remove from map
    return minid;
}

void DaryHeap::decrease_key(int task_id, int new_priority) {
    auto it = inxmap.find(task_id);
    if (it == inxmap.end()) return;
    size_t idx = it->second;
    if (new_priority >= heap[idx]->priority) return;
    heap[idx]->priority = new_priority;
    shiftu(idx); // move up after decrease
}

void DaryHeap::merge_with(Heap& other) {
    if (auto* dh = dynamic_cast<DaryHeap*>(&other)) {
        for (auto* t : dh->heap) insert(t->taskid, t->priority); // I insert all from other
    }
}

void DaryHeap::print_heap() const {
    for (auto* t : heap) {
        std::cout << "TaskID: " << t->taskid << ", Priority: " << t->priority << "\n";
    }
}

void DaryHeap::shiftu(size_t i) {
    while (i > 0) {
        size_t p = parentinx(i);
        if (heap[i]->priority < heap[p]->priority) {
            std::swap(heap[i], heap[p]);
            inxmap[heap[i]->taskid] = i;
            inxmap[heap[p]->taskid] = p;
            i = p;
        } else break;
    }
}

void DaryHeap::shiftd(size_t i) {
    while (true) {
        size_t best = i;
        for (int k = 1; k <= d; ++k) {
            size_t c = childidx(i, k);
            if (c < heap.size() && heap[c]->priority < heap[best]->priority) {
                best = c;
            }
        }
        if (best != i) {
            std::swap(heap[i], heap[best]);
            inxmap[heap[i]->taskid] = i;
            inxmap[heap[best]->taskid] = best;
            i = best;
        } else break;
    }
}

size_t DaryHeap::parentinx(size_t i) const { return (i - 1) / d; }
size_t DaryHeap::childidx(size_t i, int k) const { return d * i + k; }
