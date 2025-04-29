//Ahmet Çavuşoğlu 32394

#ifndef INPUT_PARSER_H
#define INPUT_PARSER_H

#include <string>
#include "Heap.h"
using namespace std;

// this class for reading input file

class InputParser {
public:
    void parse(const string& filename); // read file and run commands
    ~InputParser(); // I delete heap when done

private:
    Heap* heap = nullptr; // I keep heap pointer
    void ensure_heap_type(const string& type, int d = 2); // check heap type
};

#endif
