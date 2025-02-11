// Ahmet Cavusoglu 32394
// Please run this code with: "g++ -std=c++11 main.cpp BST.cpp Stack.cpp -o program"

#ifndef BST_H
#define BST_H

#include "Stack.h"
#include <iostream>
#include <utility> // for std::pair

template <class T>
class BST {
private:
    struct Node {
        int startByte;  // starting address of memory
        int size;       // size of memory block
        Stack<T> stack; // stack that store variables
        Node* left;     // left child of node
        Node* right;    // right child of node
        Node(int start, int s) : startByte(start), size(s), left(nullptr), right(nullptr) {}
    };

    Node* root; // root node of tree

    void inorderTraversal(Node* node) const; // print tree in order
    Node* findNode(Node* node, int address) const; // search a node with address
    Node* removeNode(Node* node, int address); // remove node

public:
    BST(); // constructor
    ~BST(); // destructor
    void clear(Node* node); // delete all nodes

    BST<T>& operator+=(const std::pair<int, int>& allocation); // add new memory allocation
    BST<T>& operator-=(int address); // deallocate memory
    Stack<T>* operator[](int address); // find stack in specific memory address
    void inorder() const; // call inorderTraversal
};

#include "BST.cpp"
#endif
