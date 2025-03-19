//Ahmet Çavuşoğlu 32394
#include <iostream>
#include <vector>
using namespace std;

// This class represents a move on the board
// I'm using this to keep track of row and column positions
class Change {
public:
    int row;
    int column;
    // Default constructor that sets things to -1 if no values given
    Change(int r = -1, int c = -1) : row(r), column(c) {}
};

// This class represents the tic-tac-toe board
// I'm using a 1D array to store the board which makes some calculations easier
class Board {
private:
    char board[9]; // 1D array to represent 3x3 grid

public:
    // Constructor that initializes the board with empty spaces
    // I'm using space character to represent empty cells
    Board() {
        for (int i = 0; i < 9; i++) {
            board[i] = ' ';
        }
    }

    // Copy constructor to make a duplicate of another board
    // I need this for the AI to simulate moves without changing the actual board
    Board(const Board& other) {
        for (int i = 0; i < 9; i++) {
            board[i] = other.board[i];
        }
    }

    // Makes a move on the board if the position is valid
    // This converts 2D coordinates to 1D index using row*3+col formula
    void makeMove(int row, int col, char player) {
        int index = row * 3 + col;
        if (index >= 0 && index < 9 && board[index] == ' ') {
            board[index] = player;
        }
    }

    // Checks if a move is valid (empty cell and within bounds)
    // Return true if the move is valid, false otherwise
    bool isValidMove(int row, int col) const {
        int index = row * 3 + col;
        return (index >= 0 && index < 9 && board[index] == ' ');
    }

    // Checks if the board is full (no empty spaces)
    // I think I named this function weird, it should be isFull() but whatever
    bool isNotEmpty() const {
        for (int i = 0; i < 9; i++) {
            if (board[i] == ' ') {
                return false;
            }
        }
        return true;
    }

    // Checks if there's a winner or not
    // I called it checkpoint which is confusing but it checks for win conditions
    // Returns the winning player's symbol or space if no winner
    char checkpoint() const {
        // Check rows (I wrote this in Turkish originally lol)
        if (board[0] == board[1] && board[1] == board[2] && board[0] != ' ') return board[0];
        if (board[3] == board[4] && board[4] == board[5] && board[3] != ' ') return board[3];
        if (board[6] == board[7] && board[7] == board[8] && board[6] != ' ') return board[6];
        
        // Check columns
        if (board[0] == board[3] && board[3] == board[6] && board[0] != ' ') return board[0];
        if (board[1] == board[4] && board[4] == board[7] && board[1] != ' ') return board[1];
        if (board[2] == board[5] && board[5] == board[8] && board[2] != ' ') return board[2];
        
        // Check diagonals
        if (board[0] == board[4] && board[4] == board[8] && board[0] != ' ') return board[0];
        if (board[2] == board[4] && board[4] == board[6] && board[2] != ' ') return board[2];
        return ' ';
    }

    // Gets the symbol at a specific location
    // Used to display the board
    char getLoc(int row, int col) const {
        return board[row * 3 + col];
    }

    // Gets all available moves on the board
    // I need this for the AI to know what moves it can make
    vector<Change> getAvailableChanges() const {
        vector<Change> moves;
        for (int i = 0; i < 9; i++) {
            if (board[i] == ' ') {
                moves.push_back(Change(i / 3, i % 3)); // Calculate row, col from index
            }
        }
        return moves;
    }
};


// This class represents a node in the game tree
// Each node has a board state and possible moves from that state
class TreeNode {
public:
    Board gameState;
    Change move;
    int value;
    vector<TreeNode*> children;
    
    // Constructor that sets up the node with a game state and move
    TreeNode(const Board& state, const Change& m) : gameState(state), move(m), value(0) {}
    
    // Destructor to clean up memory
    // I have to delete all children recursively to avoid memory leaks
    ~TreeNode() {
        for (TreeNode* child : children) {
            delete child;
        }
    }
    
    // Adds all possible next moves as children to this node
    // This builds the game tree one level deeper
    void insert(char player) {
        vector<Change> availableMoves = gameState.getAvailableChanges();
        
        for (const Change& move : availableMoves) {
            Board newState = gameState;
            newState.makeMove(move.row, move.column, player);
            TreeNode* child = new TreeNode(newState, move);
            children.push_back(child);
        }
    }
};

// This is the main game class that handles the game logic
// It uses a tree structure to determine the best AI moves
class Tree {
private:
    Board currentBoard;
    char playerSymbol;
    char aiSymbol;
    TreeNode* gameTree;
    int nodesExplored;
    
    // Converts user input (1-9) to row and column
    // I'm using this because its easier for user to input a single number
    Change convertPosition(int position) {
        position--; // Convert to 0-based indexing
        int row = position / 3;
        int col = position % 3;
        return Change(row, col);
    }
    
    // Converts row and column back to position (1-9)
    // Need this to tell the user where the AI moved
    int convertToPosition(int row, int col) {
        return row * 3 + col + 1;
    }
    
    // Builds the game tree from the current board state
    // The tree has the current state as root and all possible moves as children
    TreeNode* buildGameTree(const Board& state, char currentPlayer) {
        TreeNode* root = new TreeNode(state, Change());
        root->insert(currentPlayer);
        return root;
    }
    
    // This is the minimax algorithm with alpha-beta pruning
    // I'm using this to find the best move for the AI
    // It evaluates all possible moves and chooses the best one
    int MinimaxAlghoritm(TreeNode* node, int depth, int alfa, int beta, bool maximizingPlayer, char currentPlayer) {
        nodesExplored++;
        
        char winner = node->gameState.checkpoint();
        
        // Check if we reached a terminal state or max depth
        if (winner != ' ' || node->gameState.isNotEmpty() || depth == 0) {
            // Evaluate the board state
            if (winner == aiSymbol) {
                return 10; // AI wins
            } else if (winner == playerSymbol) {
                return -10; // Player wins
            } else {
                return 0; // Draw
            }
        }
        
        // If no children yet, generate them
        if (node->children.empty()) {
            node->insert(currentPlayer);
        }
        
        // Figure out who's turn is next
        char nextPlayer;
        if (currentPlayer == 'X') {
            nextPlayer = 'O';
        } else {
            nextPlayer = 'X';
        }

        
        if (maximizingPlayer) {
            // AI's turn (maximizing)
            int maxEval = -1000; // Start with a really low value
            for (TreeNode* child : node->children) {
                int eval = MinimaxAlghoritm(child, depth - 1, alfa, beta, false, nextPlayer);
                if (eval > maxEval) {
                    maxEval = eval;
                }
                if (eval > alfa) {
                    alfa = eval;
                }
                if (beta <= alfa) {
                    break; // Beta pruning - skip evaluating other branches
                }
            }
            node->value = maxEval;
            return maxEval;
        } else {
            // Player's turn (minimizing)
            int minEval = 1000; // Start with a really high value
            for (TreeNode* child : node->children) {
                int eval = MinimaxAlghoritm(child, depth - 1, alfa, beta, true, nextPlayer);
                if (eval < minEval) {
                    minEval = eval;
                }
                if (eval < beta) {
                    beta = eval;
                }
                if (beta <= alfa) {
                    break; // Alpha pruning - skip evaluating other branches
                }
            }
            node->value = minEval;
            return minEval;
        }
    }
    
    // Finds the best move for the AI using minimax
    // This is the main function that decides where the AI should move
    Change getBestChange() {
        nodesExplored = 1;
        
        // Build the game tree from current board state
        delete gameTree; // Clean up old tree first
        gameTree = buildGameTree(currentBoard, aiSymbol);
        
       
        int bestScore = -1000; // Start with a bad score
        Change bestMove;
        
        // Evaluate all possible moves
        for (TreeNode* child : gameTree->children) {
            char opponent;
            if (aiSymbol == 'X') {
                opponent = 'O';
            } else {
                opponent = 'X';
            }

            // Calculate score for this move
            int score = MinimaxAlghoritm(child, 9, -1000, 1000, false, opponent);

            // Update best move if this one is better
            if (score > bestScore) {
                bestScore = score;
                bestMove = child->move;
            }
        }
        
        return bestMove;
    }


    
    // Shows the current board state
    void displayBoard() const {
        cout << endl;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (j == 0) {
                    cout << " "; // Add space at start of row
                }
                cout << currentBoard.getLoc(i, j);
                if (j < 2) cout << " | ";
            }
            cout << endl;
            if (i < 2) cout << "---+---+---" << endl;
        }
        cout << endl;
    }

    
    // Shows the board with number positions
    // This helps user know which number corresponds to which position
    void displayBoardWithNumbers() const {
        cout << endl;
            cout << " 1 " << "|" << " 2 " << "|" << " 3 " << endl;
            cout << "---+---+---" << endl;
            cout << " 4 " << "|" << " 5 " << "|" << " 6 " << endl;
            cout << "---+---+---" << endl;
            cout << " 7 " << "|" << " 8 " << "|" << " 9 " << endl << endl;
    }

    
public:
    // Constructor initializes the game
    Tree() : gameTree(nullptr), nodesExplored(0) {
        // Initialize the game with empty symbols
        playerSymbol = ' ';
        aiSymbol = ' ';
    }
    
    // Destructor to clean up memory
    ~Tree() {
        delete gameTree;
    }
    
    // Main game loop function
    // This handles the whole game from start to finish
    void play() {
        // Ask player to choose X or O
        char choice;
        cout << "Do you want to play as X or O? (X goes first): ";
        cin >> choice;
        choice = toupper(choice);
        
        if (choice == 'X') {
            playerSymbol = 'X';
            aiSymbol = 'O';
        } else {
            playerSymbol = 'O';
            aiSymbol = 'X';
        }
        
        cout << "Welcome to Tic Tac Toe!" << endl;
        cout << "You are playing as " << playerSymbol << "." << endl;
        cout << "The AI is playing as " << aiSymbol << "." << endl;
        cout << "Enter a number from 1-9 to make your move:" << endl;
        
        // Show the initial board with numbers
        displayBoardWithNumbers();
        
        // Game loop
        bool playerTurn = (playerSymbol == 'X'); // X always goes first
        
        while (true) {
            if (playerTurn) {
                // Player's turn
                int position;
                while (true) {
                    cout << "Your move (1-9): ";
                    cin >> position;
                    
                    if (position < 1 || position > 9) {
                        cout << "Invalid position. Please enter a number between 1 and 9." << endl;
                        continue;
                    }
                    
                    Change move = convertPosition(position);
                    if (currentBoard.isValidMove(move.row, move.column)) {
                        currentBoard.makeMove(move.row, move.column, playerSymbol);
                        break;
                    } else {
                        cout << "That position is already taken. Try again." << endl;
                    }
                }
            } else {
                // AI's turn
                cout << "AI is making a move..." << endl;
                Change aiMove = getBestChange();
                currentBoard.makeMove(aiMove.row, aiMove.column, aiSymbol);
                int position = convertToPosition(aiMove.row, aiMove.column);
                cout << "AI chose position " << position << "." << endl;
                cout << "Nodes explored: " << nodesExplored << endl;
            }
            
            // Show the updated board
            displayBoard();
            
            // Check if game is over
            char winner = currentBoard.checkpoint();
            if (winner != ' ') {
                if (winner == playerSymbol) {
                    cout << "Congratulations! You win!" << endl;
                } else {
                    cout << "The AI wins!" << endl;
                }
                break;
            } else if (currentBoard.isNotEmpty()) {
                cout << "It's a draw!" << endl;
                break;
            }
            
            // Switch turns
            playerTurn = !playerTurn;
        }
    }
};

// Main function that starts the game
int main() {
    Tree game;
    game.play();
    return 0;
}
