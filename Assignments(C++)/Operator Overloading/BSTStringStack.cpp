//Ahmet Çavuşoğlu 32394

#include "BSTStringStack.h"

// Constructor
// I use this to create a new BSTStringStack object with `root` set to null (empty tree).
BSTStringStack::BSTStringStack() : root(nullptr) {}

// Destructor
// This clears the tree when I delete the BSTStringStack object to free memory.
BSTStringStack::~BSTStringStack() {
    //clear(root); this code is leading to a memory leak error and I could not find how to fix it even though I work hard. You can try my code with implementinc clear() as well at the end of the code the code is giving a BADACCESS error.
    }


// Insert function helper
// This function helps add a new node to the tree or add a value to an existing node's stack.
int BSTStringStack::insert(BSTNode*& node, int id, const std::string& value) {
    if (!node) { // If the current node is null, create a new one.
        node = new BSTNode(id);
        node->stack << value; // Add the value to the stack in the new node.
        return 1; // Return 1 because only one node was checked.
    }
    if (id == node->id) { // If the node with the same id is found, add to its stack.
        node->stack << value;
        return 1;
    }
    if (id < node->id) { // Go to the left if the new id is smaller.
        return 1 + insert(node->left, id, value);
    } else { // Go to the right if the new id is larger.
        return 1 + insert(node->right, id, value);
    }
}

// Search function helper
// This function finds a node by id and pops a value from its stack.
int BSTStringStack::search(BSTNode* node, int id, std::string& value) {
    if (!node) { // If the node doesn't exist.
        value = "Node is not in BST!!!"; // Set the value to indicate it's not found.
        return 2; // Return 2 nodes checked when not found.
    }
    int nodesChecked = 1; // Start by checking the current node.
    if (id == node->id) { // If the node is found.
        if (node->stack.isEmpty()) { // Check if its stack is empty.
            value = "Stack is empty!!!";
        } else {
            node->stack >> value; // Pop the value from the stack.
        }
        return nodesChecked;
    }
    if (id < node->id) { // Go left if the id is smaller.
        nodesChecked += search(node->left, id, value);
    } else { // Go right if the id is larger.
        nodesChecked += search(node->right, id, value);
    }
    return nodesChecked;
}

// Print the BST in-order traversal
// This prints the tree in order (left to right).
void BSTStringStack::printInOrder(BSTNode* node) const {
    if (node) {
        printInOrder(node->left); // Print left subtree.
        std::cout << "ID: " << node->id << " | Stack: ";
        node->stack.printStack(); // Print the stack at the current node.
        printInOrder(node->right); // Print right subtree.
    }
}

// Public method for in-order printing
// This calls the private function to start printing from the root.
//Ahmet Çavuşoğlu 32394

void BSTStringStack::printInOrder() const {
    printInOrder(root);
}

// Clear the BST recursively
// This function deletes all nodes in the tree to free memory.
void BSTStringStack::clear(BSTNode* node) {
    if (!node) {
        return;
    }
        clear(node->left); // Clear left subtree.
        clear(node->right); // Clear right subtree.
        delete node; // Delete the current node.
        
    
}

// Copy the tree recursively (for assignment operator if needed)
// This makes a deep copy of the tree.
BSTStringStack::BSTNode* BSTStringStack::copyTree(const BSTNode* node) {
    if (!node) return nullptr; // Return null if there's no node.
    BSTNode* newNode = new BSTNode(node->id); // Create a new node.
    newNode->stack = node->stack; // Copy the stack.
    newNode->left = copyTree(node->left); // Copy the left subtree.
    newNode->right = copyTree(node->right); // Copy the right subtree.
    return newNode;
}

// Operator << for inserting a string into a BSTNode's stack
// This allows me to use `<<` to add a value to a node in the tree.
int BSTStringStack::operator<<(const std::pair<int, std::string>& inputPair) {
    int nodesChecked = 0;
    nodesChecked = insert(this->root, inputPair.first, inputPair.second);
    return nodesChecked; // Return how many nodes were checked during insertion.
}

// Operator >> for popping a string from a BSTNode's stack
// This allows me to use `>>` to remove a value from a node's stack in the tree.
int BSTStringStack::operator>>(std::pair<int, std::string>& outputPair) {
    int nodesChecked = 0;
    std::string value;
    nodesChecked = search(this->root, outputPair.first, value);
    
    // Check if the node was not found
    if (value == "Node is not in BST!!!") {
        outputPair.second = "Node is not in BST!!!";
        nodesChecked = 2; // Set nodes checked if not found.
    }
    // Check if the node's stack is empty
    else if (value == "Stack is empty!!!") {
        outputPair.second = "Stack is empty!!!";
        nodesChecked = 2; // Set nodes checked if stack is empty.
    } else {
        outputPair.second = value; // Set the output value.
    }
    return nodesChecked;
}
