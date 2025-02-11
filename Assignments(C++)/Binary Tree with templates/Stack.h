// Ahmet Cavusoglu 32394
// Please run the code by using this term "g++ -std=c++11 main.cpp BST.cpp Stack.cpp -o program"

#ifndef STACK_H
#define STACK_H

#include <vector>    // For storing stack elements
#include <iostream>  // For printing messages
#include <utility>   // For using std::pair

template <class T>
class Stack {
private:
    std::vector<std::pair<int, T>> elements; // Store address-value pairs

public:
    // Overload << operator to add new variable to stack
    void operator<<(const std::pair<int, T>& variable);

    // Overload >> operator to remove variable from stack by address
    bool operator>>(int address);

    // Display all stack variables
    void display() const;
};

#include "Stack.cpp" // Include the implementation
#endif
