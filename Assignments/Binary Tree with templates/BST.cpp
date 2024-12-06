// Ahmet Cavusoglu 32394
// Please run this code with: "g++ -std=c++11 main.cpp BST.cpp Stack.cpp -o program"

#ifndef BST_CPP
#define BST_CPP

#include "BST.h"
#include <iostream>

template <class T>
BST<T>::BST() : root(nullptr) {} // Initialize root as null

template <class T>
BST<T>::~BST() {
    clear(root); // delete all nodes when tree destroyed
}

template <typename T>
void BST<T>::clear(Node* node) {
    if (node) {
        clear(node->left); // clear left child
        clear(node->right); // clear right child
        delete node; // delete the current node
    }
}

template <typename T>
void BST<T>::inorderTraversal(Node* node) const {
    if (node) {
        inorderTraversal(node->left); // visit left first
        std::cout << "Memory allocation starting at byte " << node->startByte
                  << " with size " << node->size << " bytes:\n";
        std::cout << "Stack starting at byte " << node->startByte << ":\n";
        node->stack.display(); // print the stack
        inorderTraversal(node->right); // visit right after
    }
}

template <typename T>
void BST<T>::inorder() const {
    inorderTraversal(root); // start printing from root
}

template <typename T>
typename BST<T>::Node* BST<T>::findNode(Node* node, int address) const {
    if (!node || address < node->startByte || address >= node->startByte + node->size)
        return nullptr; // no match found
    if (address >= node->startByte && address < node->startByte + node->size)
        return node; // match found
    if (address < node->startByte)
        return findNode(node->left, address); // search in left child
    return findNode(node->right, address); // search in right child
}

template <typename T>
BST<T>& BST<T>::operator+=(const std::pair<int, int>& allocation) {
    int startByte = allocation.first;
    int size = allocation.second;

    Node** current = &root;
    while (*current) {
        if (startByte < (*current)->startByte) {
            current = &((*current)->left); // move left
        } else if (startByte >= (*current)->startByte + (*current)->size) {
            current = &((*current)->right); // move right
        } else {
            std::cout << "Error"; // overlapping memory error
            return *this;
        }
    }
    *current = new Node(startByte, size); // create new node
    std::cout << "Allocated " << size << " bytes starting at byte " << startByte << ".\n";
    return *this;
}

template <typename T>
BST<T>& BST<T>::operator-=(int address) {
    root = removeNode(root, address); // remove memory containing address
    return *this;
}

template <typename T>
typename BST<T>::Node* BST<T>::removeNode(Node* node, int address) {
    if (!node) return nullptr;

    if (address < node->startByte) {
        node->left = removeNode(node->left, address); // go left
    } else if (address >= node->startByte + node->size) {
        node->right = removeNode(node->right, address); // go right
    } else {
        std::cout << "Deallocated memory containing byte " << address << ".\n";
        if (!node->left) {
            Node* rightChild = node->right;
            delete node;
            return rightChild;
        } else if (!node->right) {
            Node* leftChild = node->left;
            delete node;
            return leftChild;
        }
        Node* successor = node->right;
        while (successor->left)
            successor = successor->left; // find smallest in right subtree
        node->startByte = successor->startByte;
        node->size = successor->size;
        node->stack = successor->stack;
        node->right = removeNode(node->right, successor->startByte); // delete successor
    }
    return node;
}

template <typename T>
Stack<T>* BST<T>::operator[](int address) {
    Node* node = findNode(root, address); // find node containing address
    if (!node) return nullptr; // return null if not found
    return &(node->stack); // return stack in that node
}

#endif
