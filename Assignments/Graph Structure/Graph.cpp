//Ahmet Cavusoglu 32394
#include <iostream>//cout/cin
#include <vector>//vector and matrix
#include <fstream>//writing or reading the file
#include <sstream>//seperate the numbers in lines
using namespace std;
//creating node structure/class to implement graph structure

class Node {
public:
    int value;
    Node* next;

    Node(int val) : value(val), next(nullptr) {}
};
//Creating Quene class to implement BFS

class Queue {
private:
    Node* head;
    Node* tail;

public:
    Queue() : head(nullptr), tail(nullptr) {}

    void enqueue(int x) {
        Node* newNode = new Node(x);
        if (tail == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    int dequeue() {
        //cheks the quene is empty
        if (head == nullptr) {
            return -1;//error 
        }
        int value = head->value;
        Node* temp = head;
        head = head->next;
        if (head == nullptr) {
            tail = nullptr;
        }
        delete temp;
        return value;
    }

    bool isEmpty() {
        return head == nullptr;
    }
};

//Creating stack class to implement DFS
class Stack {
private:
    Node* top;  // creating top pointer as private.

public:
    Stack() : top(nullptr) {}

    // push to top function.
    void push(int x) {
        Node* newNode = new Node(x);
        newNode->next = top;
        top = newNode;
    }

    // pop from the top function.
    int pop() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        int value = top->value;
        Node* temp = top;
        top = top->next;
        delete temp;
        return value;
    }

    // check if the stack is empty or not.
    bool isEmpty() {
        return top == nullptr;
    }
};


// Graph class
class Graph {
private:
    struct Vertex {
        int value;
        Node* neighbors; // Linked list of neighbors
        Vertex* nextVertex;
        
        Vertex(int val) : value(val), neighbors(nullptr), nextVertex(nullptr) {}
    };

    Vertex* head; // Linked list of vertices
    Vertex* tail; // To keep track of the last vertex (for adding in order)

public:
    // Constructor
    Graph() : head(nullptr), tail(nullptr) {}

    // Add a vertex to the graph (maintaining the order of vertices)
    void addVertex(int value) {
        if (!findVertex(value)) {
            Vertex* newVertex = new Vertex(value);

            if (!head) {
                // If the graph is empty, set both head and tail to the new vertex
                head = newVertex;
                tail = newVertex;
            } else {
                // Append new vertex to the end of the list
                tail->nextVertex = newVertex;
                tail = newVertex;
            }
        }
    }

    // Add an edge between two vertices
    void addEdge(int from, int to) {
        addVertex(from);
        addVertex(to);

        Vertex* fromVertex = findVertex(from);
        if (!findNeighbor(fromVertex->neighbors, to)) {
            appendNeighbor(fromVertex->neighbors, to);
            cout<<"The new edge is added."<<endl;

            
        } else {
            cout << "Edge from " << from << " to " << to << " already exists." << endl;
            
        }
        
        
    }
    //it is for the beggining creation of graph
    void addEdgeFirst(int from, int to) {
        addVertex(from);
        addVertex(to);

        Vertex* fromVertex = findVertex(from);
        if (!findNeighbor(fromVertex->neighbors, to)) {
            appendNeighbor(fromVertex->neighbors, to);

            
        } else {
            cout << "Edge from " << from << " to " << to << " already data." << endl;
            
        }
        
        
    }

    // Print the graph
    void printGraph(int max) {
        for (int i = 0; i <= max; ++i) { // Ensure all vertices from 0 to size are printed
            Vertex* vertex = findVertex(i);
            cout << i << " -> ";
            if (vertex && vertex->neighbors) {
                Node* neighbor = vertex->neighbors;
                while (neighbor) {
                    cout << neighbor->value;
                    if (neighbor->next) {
                        cout << " -> ";
                    }
                    neighbor = neighbor->next;
                }
            }
            cout << endl;
        }
    }

    // Remove an edge between two vertices
    void removeEdge(int from, int to) {
        Vertex* fromVertex = findVertex(from);
        if (fromVertex) {
            Node* prev = nullptr;
            Node* current = fromVertex->neighbors;

            while (current && current->value != to) {
                prev = current;
                current = current->next;
            }

            if (current) {
                if (prev) {
                    prev->next = current->next;
                } else {
                    fromVertex->neighbors = current->next;
                }
                delete current;
            }
        }
    }
    //controls the edge is existing or not.
    bool isEdgeInUsage(int from, int to) {
        Vertex* fromVertex = findVertex(from);
        if (fromVertex) {
            return findNeighbor (fromVertex->neighbors, to);
        }
        return false;
    }
    //DFS research function
    void DFS(Graph& g, int startVertex) {
        int visited[100] = {0};  //to keep all nodes which are visited
        Stack stack;  // creating stack class

        // push the first vertex to the stack
        stack.push(startVertex);

        cout << "Depth-First Search starting from node " << startVertex << ":\n";

        while (!stack.isEmpty()) {
            // get the first element in the stack
            int current = stack.pop();

            // if the node not visited
            if (!visited[current]) {
                // sign as visited
                visited[current] = 1;
                cout << current << " ";

                // add the neighbors of the vertex in the stack in order
                Graph::Vertex* vertex = g.findVertex(current);
                if (vertex) {
                    Node* neighbor = vertex->neighbors;

                    // add the neighbors
                    while (neighbor) {
                        if (!visited[neighbor->value]) {
                            stack.push(neighbor->value);
                        }
                        neighbor = neighbor->next;
                    }
                }
            }
        }

        cout << endl;
    }
    
    void BFS(int startVertex) {
            Queue queue;
            bool visited[100] = {0};//this is for indicating the visited ones.

            visited[startVertex] = true;
            queue.enqueue(startVertex);
            cout << "BFS starting from vertex " << startVertex << ": "<<endl;
            //searching related to BFS and printing the results
            while (!queue.isEmpty()) {
                int current = queue.dequeue();
                
                cout << current << " ";
                
                Vertex* vertex = findVertex(current);
                Node* neighbor = vertex->neighbors;
                //while neighbor != nullptr search and sign visited as true.
                while (neighbor) {
                    if (!visited[neighbor->value]) {
                        visited[neighbor->value] = true;
                        queue.enqueue(neighbor->value);
                    }
                    neighbor = neighbor->next;
                }
            }

            cout << endl;
        }



private:
    // Find a vertex by value exists or not
    Vertex* findVertex(int value) {
        Vertex* current = head;
        while (current) {
            if (current->value == value) {
                return current;
            }
            current = current->nextVertex;
        }
        return nullptr;
    }
    // Find a neighbor in a linked list again exists or not
    bool findNeighbor(Node* head, int value) {
        Node* current = head;
        while (current) {
            if (current->value == value) {
                return true;
            }
            current = current->next;
        }
        return false;
    }
    // Append a neighbor to the end of the linked list
    void appendNeighbor(Node*& head, int value) {
        Node* newNeighbor = new Node(value);

        if (!head || value < head->value) {
            // if the new neighbor is less then add it to beginning
            newNeighbor->next = head;
            head = newNeighbor;
        } else {
            //append the new value to the graph in ordered way.
            Node* current = head;
            while (current->next && current->next->value < value) {
                current = current->next;
            }
            newNeighbor->next = current->next;
            current->next = newNeighbor;
        }
    }
    

    

    
};
// makeVector function gets a string line and converts it to an integer vector structure to add in matrix(usage)
vector<int> makeVector(const string& line) {
    vector<int> result;
    stringstream ss(line);
    string item;

    while (ss >> item) {
        result.push_back(stoi(item));  //convert all items string to integer.
    }

    return result;
}


bool hasLetter(const string& line) {
    for (char c : line) {
        if (isalpha(c) || c == '-') {  // if the line has alpha or negative sign then returns true.
            return true;
        }
    }
    return false;  //else returns false.
}

void sortMatrix(vector<vector<int>>& matrix) {
    sort(matrix.begin(), matrix.end(), [](const vector<int>& a, const vector<int>& b) {
        if (a[0] == b[0]) {
            return a[1] < b[1];  //if the first elements are equal then sorts respect to second elements.
        }
        return a[0] < b[0];  // sorting resperct to the first elements.
    });
}
//counting numbers to indicate lines which include 3 or more numbers.
int countNumbersInLine(const string& line) {
    int count = 0;
    bool inNumber = false;

    for (int i = 0; i < line.length(); i++) {
        char c = line[i];

        if (isdigit(c)) {
            if (!inNumber) {  // new number just started.
                count++;
                inNumber = true;
            }
        }
        else {
            inNumber = false;  // if the number end.
        }
    }

    return count;
}

//cheks the vector is in matrix already or not.
bool isin(const string& line, const vector<string>& inc) {
    for (const string& l : inc) {
        if (l == line) return true;
    }
    return false;
}

int main() {
    string input;
    ifstream File;
    int choice;
    //asks until file is existing.
        do {
            cout << "Enter the input file name: "<<endl;
            cin >> input;

            // opens the file
            File.open(input);

            if (!File) {
                cout << "Could not open the file " << input << endl;
            }
            
        } while (!File);
    /*
     creating a vector and matrix structure for the first analyses of the data. Due to finding illegal ones, it is required. However in the following parts I am using graph class to indicate duplicated or not existant inputs. In the document, it said we are allowed to use vectors for the begginning part.
     */
    vector<string> inc;
    vector<string> notwanted;
    string line;

    // reads the file line by line
    while (getline(File, line)) {
        // cheks the numbers in the line
        int numberCount = countNumbersInLine(line);
        //if the line has 2 numbers and no negative numbers and no alpha then pushbacks the line to the inc vector.
        if (numberCount == 2 && !hasLetter(line) && !isin(line, inc)) {
            inc.push_back(line);
        }
        //pushback to the notwanted vector due to see illegal lines.
        else {
            notwanted.push_back(line);
        }
    }
    //creating matrix which we will use in our graph structure.
    vector<vector<int>> usage;
    for (int i = 0; i < inc.size(); i++) {//inc vector is string so we have to convert it to integer before pushing in matrix(usage)
        usage.push_back(makeVector(inc[i]));
    }
    int max = 0;
    for (int i = 0; i < usage.size(); i++) {
        if (max < usage[i][0]) {
            max = usage[i][0];  // finding the max value in the matrix to implement add or remove functions.
        }
        if (max < usage[i][1]) {
            max = usage[i][1];
        }
    }
   
    Graph g;//creating graph structure
    sortMatrix(usage);  // sorting the matrix
    for (int i = 0; i < usage.size(); i++) {
        g.addEdgeFirst(usage[i][0], usage[i][1]);  // adding every element into the graph in the correct order(from ,to)
    }
    cout<<endl;
    cout<<"These edges are illegal or repeated: "<<endl;//priting illegal values in the data
        for (const string& l : notwanted) {
            cout << l << endl;
        }
    cout<<endl;
    do{
        cout<<"(1) Add edge"<<endl<<"(2) Remove edge"<<endl<<"(3) Display the graph"<<endl<<"(4) Depth-first search"<<endl<<"(5) Breadth-first search"<<endl<<"(6) Exit"<<endl;
                cout<<"Please enter a number (1-6): "<<endl;
                cin>>choice;
        while(choice<1||choice>6){
                    
                        cout<<"The entered number is not valid! Make another choice: "<<endl;
                        
                        cin>>choice;
                    }
        if (choice==1){
            int from,to;
            cout<<"Enter two nodes as two endings of the new edge "<<endl;
            cin>>from>>to;
            while (from > max || to > max||from<0||to<0) {
                cout << "The entered node IDs are out of range, Enter two other IDs: "<<endl;
                cin >> from >> to;
            }
            if (!g.isEdgeInUsage(from, to)) {
                g.addEdge(from, to);  // Kenar ekleniyor
                // Kenar eklemek için gerekli diğer işlemler...
            } else {
                cout << "Edge from " << from << " to " << to << " already exists in the graph." << endl;
            }
            
            
        }
        else if (choice == 2) {
            int from, to;
            cout << "Enter two nodes as two endings of the edge to be removed: " << endl;
            cin >> from >> to;

            //control of borders
            while (from > max || to > max||from<0||to<0) {
                cout << "The entered node IDs are out of range, enter two other IDs: " << endl;
                cin >> from >> to;
            }

            

            //control of edge existance.
            if (!g.isEdgeInUsage(from, to)) {
                do{
                    cout << "The entered edge does not exist in the graph! Enter two other node IDs: " << endl;
                    cin >> from >> to;

                    
                }while(!g.isEdgeInUsage(from, to));

            } if(g.isEdgeInUsage(from, to)) {
                // removing the edge
                g.removeEdge(from, to);
                cout << "The entered edge is removed." << endl<<endl;

                
            }
        }
        //prints graph
        else if (choice==3){
            cout<<"The graph has this structure:"<<endl;
            g.printGraph(max);
            cout<<"Press any key to continue..."<<endl<<endl;
            cin.ignore();//detects any key pression.
            cin.get();
            
        }
        //DFS printing
        else if (choice==4){
            int start;
            cout << "Please enter starting node: "<<endl;
            cin >> start;
            if(start>max||start<1){
                do{
                    cout << "The entered node number is out of range, enter a valid one: "<<endl;
                    cin >> start;
                }while(start>max||start<1);
            }
            
            
            g.DFS(g, start);
            cout<<endl;
        }
        //BFS printing
        else if (choice==5){
            int start;
            cout << "Please enter starting node: "<<endl;
            cin >> start;
            if(start>max||start<1){
                do{
                    cout << "The entered node number is out of range, enter a valid one: "<<endl;
                    cin >> start;
                }while(start>max||start<1);
            }
            g.BFS( start);
            cout<<endl;
        
        }
        
        
            }while(choice!=6);
    cout<<"Program Exiting…"<<endl;
    
    return 0;
}
