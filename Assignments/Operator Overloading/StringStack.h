//Other than TODOs (...) - you cannot change anything in this file. 
//Ahmet Çavuşoğlu 32394

#pragma once

#include <string>
#include <iostream>

class StringStack {
private:
    struct StackNode {
        std::string data;
        StackNode* next;
        StackNode(std::string value, StackNode* nextNode = nullptr)
            : data(value), next(nextNode) {}
    };
    StackNode* top;

public:
    StringStack();
    ~StringStack();
    void push(const std::string& value);
    std::string pop();
    bool isEmpty() const;
    void printStack() const; 
    void clear();

    //Overload the necessary operator (TODO: Introduce the function here and implementation goes to StringStack.cpp)
    //...
    StringStack& operator<<(const std::string& value);
    StringStack& operator>>(std::string& outputValue);
};
