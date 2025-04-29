//Ahmet Çavuşoğlu 32394

#include "BinomialHeap.h"
#include <iostream>
using namespace std;

// Node constructor
// I set default links and degree = 0
BinomialHeap::Node::Node(Task* t)
    : task(t), degree(0), parent(nullptr), child(nullptr), sibling(nullptr) {}

BinomialHeap::BinomialHeap() {} // empty constructor

BinomialHeap::~BinomialHeap() {
    for (auto root : roots) deltree(root); // delete all root trees
}

void BinomialHeap::deltree(Node* root) {
    if (!root) return;
    deltree(root->child); // delete child tree
    deltree(root->sibling); // delete sibling tree
    delete root->task;
    delete root;
}

void BinomialHeap::linktrees(Node* y, Node* z) {
    y->parent = z;
    y->sibling = z->child;
    z->child = y;
    z->degree++;
}

void BinomialHeap::insert(int taskid, int priority) {
    BinomialHeap temp; // I use temp heap to merge
    Task* t = new Task(taskid, priority);
    Node* node = new Node(t);
    temp.roots.push_back(node);
    temp.task_map[taskid] = node;
    merge_with(temp);
}

void BinomialHeap::merge_with(Heap& other) {
    if (BinomialHeap* i = dynamic_cast<BinomialHeap*>(&other)) merge_with(*i);
}

void BinomialHeap::merge_with(BinomialHeap& other) {
    roots.insert(roots.end(), other.roots.begin(), other.roots.end()); // add other roots
    for (auto& mv : other.task_map) task_map[mv.first] = mv.second; // copy task map
    other.roots.clear(); other.task_map.clear(); // clear other
    join(); // join trees with same degree
}

void BinomialHeap::join() {
    if (roots.empty()) return;
    sort(roots.begin(), roots.end(), [](Node* a, Node* b){ return a->degree < b->degree; });
    vector<Node*> new_roots;
    size_t i = 0;
    while (i < roots.size()) {
        Node* current= roots[i];
        if (i+1 < roots.size() && current->degree == roots[i+1]->degree) {
            Node* next = roots[i+1];
            if (current->task->priority <= next->task->priority) {
                linktrees(next, current);
                roots[i+1] = current;
            } else {
                linktrees(current, next);
                roots[i] = next;
            }
            i += 1;
        } else {
            new_roots.push_back(current);
            i += 1;
        }
    }
    roots.swap(new_roots); // I update root list
}

int BinomialHeap::extract_min() {
    if (roots.empty()) return -1;
    auto minitem = min_element(roots.begin(), roots.end(),
        [](Node* a, Node* b){ return a->task->priority < b->task->priority; });
    Node* min_root = *minitem;
    int minid = min_root->task->taskid;
    roots.erase(minitem); // remove from root list
    BinomialHeap temp;
    Node* child = min_root->child;
    while (child) {
        Node* next = child->sibling;
        child->parent = nullptr;
        child->sibling = nullptr;
        temp.roots.push_back(child);
        temp.task_map[child->task->taskid] = child;
        child = next;
    }
    delete min_root;
    task_map.erase(minid);
    merge_with(temp); // I merge back children
    return minid;
}

void BinomialHeap::decrease_key(int taskid, int newpri) {
    auto it = task_map.find(taskid);
    if (it == task_map.end()) return;
    Node* node = it->second;
    if (newpri >= node->task->priority) return;
    node->task->priority = newpri;
    Node* current = node;
    while (current->parent && current->task->priority < current->parent->task->priority) {
        swap(current->task, current->parent->task); // I swap tasks
        task_map[current->task->taskid] = current;
        task_map[current->parent->task->taskid] = current->parent;
        current = current->parent;
    }
}

void BinomialHeap::print_heap() const {
    function<void(Node*, int)> srch = [&](Node* n, int height) {
        if (!n) return;
        cout
                  << "TaskID: " << n->task->taskid
                  << ", Priority: " << n->task->priority << "\n";
        srch(n->child, height+1);
        srch(n->sibling, height);
    };
    for (auto root : roots) srch(root, 0);
}
