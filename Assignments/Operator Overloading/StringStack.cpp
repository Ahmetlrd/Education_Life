//Ahmet Çavuşoğlu 32394
#include "StringStack.h"

// Constructor
// I use this to create a new StringStack object and set `top` to null (empty stack).
StringStack::StringStack() : top(nullptr) {}

// Destructor
// This function clears the stack when I delete the StringStack object, to avoid memory leaks.
StringStack::~StringStack() {
    clear();
}

// Push function to add a string to the stack
// I use this to add a new value to the top of the stack.
void StringStack::push(const std::string& value) {
    top = new StackNode(value, top);
}

// Pop function to remove and return a string from the stack
// This removes the top element and returns its value. If the stack is empty, it returns a message.
std::string StringStack::pop() {
    if (isEmpty()) {
        return "Stack is empty!!!";
    }
    std::string value = top->data;  // Store value before deleting

    StackNode* temp = top;
    top = top->next;
    delete temp;
    return value;
}

// Check if the stack is empty
// This function checks if there are any elements in the stack.
bool StringStack::isEmpty() const {
    return top == nullptr; // Returns true if `top` is null, means stack is empty.
}

// Print the stack for debugging
// I use this to print all elements in the stack for debugging purposes.
void StringStack::printStack() const {
    StackNode* current = top;
    while (current) {
        std::cout << current->data << " "; // Print each element's data.
        current = current->next; // Move to the next node.
    }
    std::cout << std::endl; // Go to a new line after printing.
}

// Clear the stack
// This function removes all elements from the stack to clean it up.
void StringStack::clear() {
    while (!isEmpty()) {
        pop(); // Keep popping until the stack is empty.
    }
}

// Operator << for pushing a string onto the stack
// This lets me add a string to the stack using the `<<` operator.
StringStack& StringStack::operator<<(const std::string& value) {
    this->push(value);
    return *this; // Return the stack so I can chain operations.
}

// Operator >> for popping a string from the stack
// This lets me remove a string from the stack using the `>>` operator.
StringStack& StringStack::operator>>(std::string& outputValue) {
    if (!isEmpty()) {
        outputValue = this->pop(); // Pop and set the value if not empty.
    } else {
        outputValue = "Stack is empty!!!"; // Set output if stack is empty.
    }
    return *this; // Return the stack so I can chain operations.
}
