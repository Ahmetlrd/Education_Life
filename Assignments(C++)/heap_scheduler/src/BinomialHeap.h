//Ahmet Çavuşoğlu 32394

#ifndef BINOMIAL_HEAP_H
#define BINOMIAL_HEAP_H

#include "Heap.h"
#include "Task.h"
#include <unordered_map>
#include <vector>
using namespace std;

// BinomialHeap class inherite from Heap

class BinomialHeap : public Heap {
public:
    BinomialHeap(); // constructor
    ~BinomialHeap(); // destructor

    void insert(int task_id, int priority) override; // insert task
    int extract_min() override; // return min priority task
    void decrease_key(int task_id, int new_priority) override; // I decrease task priority
    void merge_with(Heap& other) override; // merge heaps
    void merge_with(BinomialHeap& other); // merge with another binomial heap
    void print_heap() const override; // print heap tasks
    
private:
    struct Node {
        Task* task;
        int degree;
        Node* parent;
        Node* child;
        Node* sibling;
        Node(Task* t); // I make node with task
    };

    vector<Node*> roots; // I keep root list here
    unordered_map<int, Node*> task_map; // task id to node map

    void linktrees(Node* y, Node* z); // link two trees
    void join(); // join trees with same degree
    void deltree(Node* root); // delete a tree
};

#endif
