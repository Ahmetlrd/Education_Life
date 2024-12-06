// Ahmet Cavusoglu 32394
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Node structure for the linked list
// This is like a box that hold coordinates and a value in the linked list
struct Box {
    int x, y, z; // coordinates
    double value; // value at those coordinates
    Box* next; // pointer to next box in list

    // Constructor
    // Box will be created with given coordinates and value, next is set to nullptr
    Box(int a, int b, int c, double val) : x(a), y(b), z(c), value(val), next(nullptr) {}
};



// Linked list class to store nodes
// This class is used for keeping all the boxes together in a link list
class Linklist {
private:
    Box* head; // first box in the list, or the start of it

public:
    // Constructor
    // When we create a Linklist, it starts empty (head is nothing)
    Linklist() : head(nullptr) {}

    // Method to add a new box to the linked list
    // Adding new Box to the front of the list, like stacking boxes on top of each other
    void add(int a, int b, int c, double value) {
        Box* newBox = new Box(a, b, c, value);
        newBox->next = head; // new node points to old head, so it connects
        head = newBox; // now new node is the head
    }

    // This returns the first box (head) of the list
    Box *findHead(){
        return head;
    }

    // Method to find the value at specific coordinates
    // We check if the coordinates are in the list, if yes we return the value there
    double find(int a, int b, int c) {
        Box* current = head; // start from the head box
        while (current) { // while there is a box in the list
            if (current->x == a && current->y == b && current->z == c) {
                return current->value; // if we find match, return the value
            }
            current = current->next; // go to next box in the list
        }
        return 0.0; // if no box found at (a, b, c), return 0.0
    }
};



int main(int argc, char *argv[]) {
    // Check if filename is given from terminal
    
    if (argc < 2) {
        cout << "Please enter filename as (.txt) form... " << endl;
        return 31; // error if no file name given
    }

    int width, height, depth, nonzero; // cube size and number of nonzero values
    double target;

    string input = argv[1]; // file name we get from command line
    
    ifstream input_File(input); // open the file

    // if file not found or not openable, return error
    if (!input_File) {
        cout << "File cannot open." << endl;
        return 31; // return error code 31 if file not openable
    }

    input_File >> width >> height >> depth >> target >> nonzero;//get other values
   
    Linklist cube; // Create the linked list

    // Read non-zero values from file and add them to the linked list
    for (int i = 0; i < nonzero; i++) {
        int a, b, c;
        double d_number;
        input_File >> a >> b >> c >> d_number;
        cube.add(a, b, c, d_number); // put the box with these coords and value in the list
    }

    
    int count = 0; // to count how many subcubes match the target value

    // Iterate through all possible subcubes
    for (int startW = 0; startW < width; ++startW) {
        for (int startH = 0; startH < height; ++startH) {
            for (int startD = 0; startD < depth; ++startD) {
                for (int finishW = startW; finishW < width; ++finishW) {
                    for (int finishH = startH; finishH < height; ++finishH) {
                        for (int finishD = startD; finishD < depth; ++finishD) {
                            
                            double sum = 0.0; // sum value of this subcube we checking
                            Box *current = cube.findHead(); // start from the head of list
                            bool control = true; // control variable to stop early if needed

                            // Check each box if it's inside this subcube
                            while(current && control){
                                if(current->x <= finishW && current->x >= startW &&
                                   current->y <= finishH && current->y >= startH &&
                                   current->z <= finishD && current->z >= startD) {
                                    sum += current->value; // add the value if inside range
                                
                                    if(sum > target) { // if sum is more than target, no need to continue , it is for efficiency
                                        control = false;
                                        break;
                                    }
                                }
                                current = current->next; // move to next box
                            }

                            // If we find that sum of subcube is exactly equal to target
                            if (sum == target) {
                                count++; // increase count for each matching subcube
                            }
                        }
                    }
                }
            }
        }
    }

    input_File.close(); // close file after work is done
    
    cout << count << endl; // print how many matching subcubes we found
    
    return 0;
    
}
