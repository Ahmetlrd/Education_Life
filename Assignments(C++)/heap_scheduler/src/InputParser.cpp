//Ahmet Çavuşoğlu 32394

#include "InputParser.h"
#include "BinomialHeap.h"
#include "DaryHeap.h"
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

// destructor, I delete the heap
InputParser::~InputParser() {
    delete heap;
}

// I check heap type and create right object
void InputParser::ensure_heap_type(const string& type, int d) {
    delete heap;
    heap = nullptr;
    if (type == "BINOMIAL") heap = new BinomialHeap();
    else if (type == "DARY") heap = new DaryHeap(d);
}

// I read commands from input file
void InputParser::parse(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cout << "Cannot open file: " << filename << endl;
        return;
    }
    string line;
    while (getline(file, line)) {
        if (line.empty()) continue;
        istringstream iss(line);
        string cmd;
        iss >> cmd;

        if (cmd == "HEAP_TYPE") {
            string type;
            iss >> type;
            if (type == "BINOMIAL") ensure_heap_type(type);
            else if (type == "DARY") {
                int d;
                iss >> d;
                ensure_heap_type(type, d);
            }
        } else if (cmd == "INSERT") {
            int id, pr;
            iss >> id >> pr;
            heap->insert(id, pr); // insert task
        } else if (cmd == "DECREASE_KEY") {
            int id, np;
            iss >> id >> np;
            heap->decrease_key(id, np); // decrease task priority
        } else if (cmd == "EXTRACT_MIN") {
            int m = heap->extract_min();
            cout << "Extracted: " << m << endl; // show removed task
        } else if (cmd == "PRINT") {
            cout << "Heap:" << endl;
            heap->print_heap(); // print current heap
        } else if (cmd == "MERGE") {
            string fname;
            iss >> fname;
            ifstream mf(fname);
            if (!mf) {
                cout<< "Cannot open merge file: " << fname << endl;
                continue;
            }
            string mline;
            while (getline(mf, mline)) {
                if (mline.empty()) continue;
                istringstream miss(mline);
                string mcmd;
                miss >> mcmd;
                if (mcmd == "HEAP_TYPE") continue;
                if (mcmd == "INSERT") {
                    int id, pr;
                    miss >> id >> pr;
                    heap->insert(id, pr);
                } else if (mcmd == "DECREASE_KEY") {
                    int id, np;
                    miss >> id >> np;
                    heap->decrease_key(id, np);
                } else if (mcmd == "EXTRACT_MIN") {
                    int m2 = heap->extract_min();
                    cout << "Extracted: " << m2 << endl;
                } else if (mcmd == "PRINT") {
                    cout << "Heap:" << endl;
                    heap->print_heap();
                }
            }
        }
    }
}
