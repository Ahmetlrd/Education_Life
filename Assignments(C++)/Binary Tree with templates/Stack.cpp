// Ahmet Cavusoglu 32394
// Please run the code by using this term "g++ -std=c++11 main.cpp BST.cpp Stack.cpp -o program"

#ifndef STACK_CPP
#define STACK_CPP

#include "Stack.h"

// Add a new variable to the stack
template <class T>
void Stack<T>::operator<<(const std::pair<int, T>& variable) {
    // Check if the new variable is contiguous with the last one
    if (!elements.empty() && elements.back().first + sizeof(T) != variable.first) {
        std::cout << "Error"; // Print error if addresses are not contiguous
        return;
    }
    elements.push_back(variable); // Add the variable to the stack
    std::cout << "Defined variable at address " << variable.first
              << ": Type: i, Value: " << variable.second << ".\n"; // Success message
}

// Remove a variable from the stack
template <typename T>
bool Stack<T>::operator>>(int address) {
    // Check if the stack is empty or the top variable's address doesn't match
    if (elements.empty() || elements.back().first != address) {
        std::cout << "Error:"; // Print error if address doesn't match
        return false;
    }
    elements.pop_back(); // Remove the variable from the stack
    std::cout << "Undefined variable at address " << address << ".\n"; // Success message
    return true;
}

// Display all variables in the stack
template <class T>
void Stack<T>::display() const {
    // Iterate through stack in reverse (top to bottom)
    for (auto it = elements.rbegin(); it != elements.rend(); ++it) {
        int startAddress = it->first; // Start of variable
        int endAddress = startAddress + sizeof(T) - 1; // End of variable
        std::cout << "Variable from address " << startAddress << " to " << endAddress
                  << ", Type: i, Value: " << it->second << "\n"; // Print variable info
    }
}

#endif
