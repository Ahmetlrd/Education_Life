//Other than TODOs (...) - you cannot change anything in this file. 
//Ahmet Çavuşoğlu 32394

#pragma once

#include "StringStack.h"
#include <string>
#include <iostream>

class BSTStringStack {
private:
    struct BSTNode {
        int id;
        StringStack stack;
        BSTNode* left;
        BSTNode* right;
        BSTNode(int idValue) : id(idValue), left(nullptr), right(nullptr) {}
    };
    BSTNode* root;

    // Helper function to insert a node into the BST and count nodes checked
    int insert(BSTNode*& node, int id, const std::string& value); 

    // Helper function to search for a node in the BST and count nodes checked
    int search(BSTNode* node, int id, std::string& value); 

    // Helper function for in-order traversal
    void printInOrder(BSTNode* node) const;

    // Helper function to delete all nodes
    void clear(BSTNode* node); 

    // Helper function to copy all nodes
    BSTNode* copyTree(const BSTNode* root);

public:
    BSTStringStack(); 
    ~BSTStringStack();

    // Method to print the tree in in-order traversal
    void printInOrder() const; 

    //Overload a necessary operator (TODO: Introduce the function here and implementation goes to BSTStringStack.cpp)
    //....

    //Overload a necessary operator (TODO: Introduce the function here and implementation goes to BSTStringStack.cpp)
    //....
    int operator<<(const std::pair<int, std::string>& inputPair);
    int operator>>(std::pair<int, std::string>& outputPair);
};
