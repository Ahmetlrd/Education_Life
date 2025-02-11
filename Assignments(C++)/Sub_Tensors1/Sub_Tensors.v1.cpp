//Ahmet Cavusoglu 32394
#include <iostream> // we include this for coding with input and output
#include <fstream> // we include this to read files
#include <vector> // we include this to create list (3D cube)

using namespace std; // we use this to make writing codes like cout easier

int main(int argc, char * argv[]) {// our main code starts here
    if (argc < 2) { // checks if the file name is given as argument
            cout << "Please enter filename as (.txt) form... " << endl;// Error message if no file name is given
            return 31; // program stops with error code
        }
    
    
    
    int width, height, depth, nonzero; // create values for coordinates and size of cube
    
    
    
    double target; // we create target value, it’s a double
    
    
    string input= argv[1]; // this will be the name of file user gives in terminal
    
    ifstream input_File(input); // we use input from user to open file
    
    
    if (!input_File) { // if file not opened, we show error message
        cout << "File cannot open." << endl;
        return 31;// stops program if file not open
    }
   
    
    input_File >> width >> height >> depth >> target >> nonzero; // we get first 5 values from file, they tell about cube and target
    
    
    
    // create 3D vector called inc (it stands for "includes") with 0.0 value
    vector<vector<vector<double> > > inc (width, vector<vector<double> >(height, vector<double>(depth, 0.0)));

    // We fill our 3D vector with values from file, if they are not zero
    
    
    for (int i = 0; i < nonzero; i++) {
        int a, b, c;
        double d_number;// "d" is for double number
        input_File >> a >> b >> c >> d_number;
        inc[a][b][c] = d_number;
    }
   
    int count = 0;  // start counting from zero

    // Start checking the vector from (0,0,0) till the borders of the cube
    
    
    
    for (int startW = 0; startW < width; ++startW) {
        for (int startH = 0; startH < height; ++startH) {
            for (int startD = 0; startD < depth; ++startD) {

                // Creates second point to check values in the interval
                for (int finishW = startW; finishW < width; ++finishW) {
                    for (int finishH = startH; finishH < height; ++finishH) {
                        for (int finishD = startD; finishD < depth; ++finishD) {
                            
                            double sum = 0.0;// we create sum again in every interval, because sum changes
                            
                            bool control = true; // this to check if sum goes over target, we don't want to continue if it does
                            
                            // Checking the numbers inside the interval, calculate the sum of doubles
                            // if sum equal to target, we add +1 to count
                            for (int x = startW; x <= finishW && control; ++x) {
                                for (int y = startH; y <= finishH && control; ++y) {
                                    for (int z = startD; z <= finishD && control; ++z) {
                                        if ((inc[x][y][z]) != 0.0) {// skips 0.0 values for efficiency
                                            sum += inc[x][y][z];// adds the valid number to find the sum of interval
                                            if (sum > target) {
                                                control = false;
                                                break; // stops if sum bigger than target
                                            }
                                            
                                        }
                                    }
                                }
                            }

                            // If sum is same with target and control is true, we increase count by one
                            if (sum == target && control) {
                                count++;
                            }
                        }
                    }
                }
            }
        }
    }

    input_File.close();  // closes the file after finishing
    cout << count << endl;  // shows the result of count
    return 0; // program ends
}
