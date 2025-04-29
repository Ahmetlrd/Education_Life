//Ahmet Çavuşoğlu 32394

#include "InputParser.h"
#include <iostream>
using namespace std;

// I write main function

int main(int argc, char* argv[]) {
    if (argc < 2) { // I check if input file given
        cout << "Usage: " << argv[0] << " <input_file>\n";
        return 1;
    }
    InputParser parser; // I create parser object
    parser.parse(argv[1]); // I call parse function
    return 0; // end of the program
}
