// main.cpp

#include "BST.h"
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
using namespace std;

/*
This main program simulates a memory management system using Binary Search Tree (BST) and Stack data structures.
It processes commands from an input file to allocate and deallocate memory, define and undefine variables, and display the current state of memory allocations.

Important Concepts Used:

1. std::pair:
   - A pair is a container from the C++ Standard Library that holds two values of possibly different types.
   - In this program, we use std::pair to pass two values together, such as (startByte, size) for allocations.

2. std::make_pair:
   - A utility function to create a std::pair without specifying the types explicitly.
   - Example: std::make_pair(1000, 12) creates a pair with first = 1000 and second = 12.

3. static_cast<Type>(value):
   - A way to convert a value from one type to another in C++.
   - In this program, we use static_cast to convert an int value to a char or short when defining variables of those types.

*/

/*
Note:
For the purposes of this assignmet, we are using fixed sizes for data types:
int: 4 bytes
short: 2 bytes
char: 1 byte
This ensures consistent behavior across different systems.
*/

int main(int argc, char* argv[]) {
    // Initialize BSTs for different data types
    BST<int> intBST;
    BST<short> shortBST;
    BST<char> charBST;

    // Check if input file is provided
    if (argc < 2) {
        cout << "Error: No input file provided." << endl;
        return 1;
    }

    // Open the input file
    ifstream inputFile(argv[1]);
    if (!inputFile) {
        cout << "Error: Cannot open input file." << endl;
        return 1;
    }

    string line;

    // Process each line in the input file
    while (getline(inputFile, line)) {
        istringstream iss(line);
        string command;
        iss >> command;

        if (command == "+") {  // Allocation command
            int start, size;
            string typeStr;

            // Read arguments in the order: startByte, type, size
            if (!(iss >> start >> typeStr >> size)) {
                cout << "Error: Invalid arguments for allocation command." << endl;
                continue;
            }

            // Allocate memory based on type
            if (typeStr == "int") {
                // Fixed size for int is 4 bytes
                if (size % 4 != 0) {
                    cout << "Error: Size must be a multiple of the size of type 'int'." << endl;
                    continue;
                }
                intBST += make_pair(start, size);  // Allocate memory in intBST
            }
            else if (typeStr == "short") {
                // Fixed size for short is 2 bytes
                if (size % 2 != 0) {
                    cout << "Error: Size must be a multiple of the size of type 'short'." << endl;
                    continue;
                }
                shortBST += make_pair(start, size);  // Allocate memory in shortBST
            }
            else if (typeStr == "char") {
                // Fixed size for char is 1 byte
                // No need to check for multiples since any size is acceptable
                charBST += make_pair(start, size);  // Allocate memory in charBST
            }
            else {
                cout << "Error: Invalid type '" << typeStr << "' for allocation." << endl;
            }
        }

        else if (command == "<<") {  // Define variable command
            int addr;
            string typeStr;
            int value;

            if (!(iss >> addr >> typeStr >> value)) {
                cout << "Error: Invalid arguments for define variable command." << endl;
                continue;
            }

            // Define variable based on type
            if (typeStr == "int") {
                Stack<int>* stack = intBST[addr];  // Get the stack containing the address
                if (stack) {
                    *stack << make_pair(addr, value);  // Define variable in the stack
                }
                else {
                    cout << "Error: No allocation found containing address " << addr << "." << endl;
                }
            }
            else if (typeStr == "short") {
                Stack<short>* stack = shortBST[addr];  // Get the stack containing the address
                if (stack) {
                    *stack << make_pair(addr, static_cast<short>(value));  // Define variable in the stack
                }
                else {
                    cout << "Error: No allocation found containing address " << addr << "." << endl;
                }
            }
            else if (typeStr == "char") {
                Stack<char>* stack = charBST[addr];  // Get the stack containing the address
                if (stack) {
                    *stack << make_pair(addr, static_cast<char>(value));  // Define variable in the stack
                }
                else {
                    cout << "Error: No allocation found containing address " << addr << "." << endl;
                }
            }
            else {
                cout << "Error: Invalid type '" << typeStr << "' for variable definition." << endl;
            }

        }
        else if (command == ">>") {  // Undefine variable command
            int addr;
            string typeStr;

            if (!(iss >> addr >> typeStr)) {
                cout << "Error: Invalid arguments for undefine variable command." << endl;
                continue;
            }

            // Undefine variable based on type
            if (typeStr == "int") {
                Stack<int>* stack = intBST[addr];  // Get the stack containing the address
                if (stack) {
                    if (!(*stack >> addr)) {
                        // Error messages should be handled within operator>>
                    }
                }
                else {
                    cout << "Error: No allocation found containing address " << addr << "." << endl;
                }
            }
            else if (typeStr == "short") {
                Stack<short>* stack = shortBST[addr];  // Get the stack containing the address
                if (stack) {
                    if (!(*stack >> addr)) {
                        // Error messages should be handled within operator>>
                    }
                }
                else {
                    cout << "Error: No allocation found containing address " << addr << "." << endl;
                }
            }
            else if (typeStr == "char") {
                Stack<char>* stack = charBST[addr];  // Get the stack containing the address
                if (stack) {
                    if (!(*stack >> addr)) {
                        // Error messages should be handled within operator>>
                    }
                }
                else {
                    cout << "Error: No allocation found containing address " << addr << "." << endl;
                }
            }
            else {
                cout << "Error: Invalid type '" << typeStr << "' for variable undefinition." << endl;
            }

        }
        else if (command == "-") {  // Deallocate command
            int byteNumber;
            string typeStr;

            if (!(iss >> byteNumber >> typeStr)) {
                cout << "Error: Invalid arguments for deallocate command." << endl;
                continue;
            }

            // Deallocate memory based on type
            if (typeStr == "int") {
                intBST -= byteNumber;  // Deallocate memory in intBST
            }
            else if (typeStr == "short") {
                shortBST -= byteNumber;  // Deallocate memory in shortBST
            }
            else if (typeStr == "char") {
                charBST -= byteNumber;  // Deallocate memory in charBST
            }
            else {
                cout << "Error: Invalid type '" << typeStr << "' for deallocation." << endl;
            }

        }
        else if (command == "display") {  // Display command
            cout << "\nCurrent state of memory allocations:" << endl;
            cout << "Integer Allocations:" << endl;
            intBST.inorder();  // Display integer allocations
            cout << "\nShort Allocations:" << endl;
            shortBST.inorder();  // Display short allocations
            cout << "\nChar Allocations:" << endl;
            charBST.inorder();  // Display char allocations
            cout << endl;
        }
        else {
            cout << "Error: Invalid command '" << command << "'." << endl;
        }
    }

    // Display final state of memory allocations
    cout << "\nFinal state of memory allocations:" << endl;
    cout << "Integer Allocations:" << endl;
    intBST.inorder();  // Display integer allocations
    cout << "\nShort Allocations:" << endl;
    shortBST.inorder();  // Display short allocations
    cout << "\nChar Allocations:" << endl;
    charBST.inorder();  // Display char allocations

    inputFile.close();
    return 0;
}
