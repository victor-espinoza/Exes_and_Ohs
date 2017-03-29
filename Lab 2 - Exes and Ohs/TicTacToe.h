/* Victor Espinoza
* CECS 282, Section 1
* Spring 2014
* Due Date: 2/11/14
* Lab #2- Exes and Ohs
*/

// printBoard takes a 2-dimensional array parameter representing the game state
// and prints it to cout. See the spec for details on formatting the output.
void printBoard(char board[3][3]);

// getMove uses cin to read the user's choice for where to move next on the 
// board. It does NOT update the game board with the move choice; it simply
// scans in values to the row and col variables, which will update whatever
// variables were used as arguments in the main. Do not check move validity
// in this function.
void getMove(int &row, int &col, char player);

// moveIsValid returns true if the board is empty at the requested row/col,
// and false otherwise. used in main to see if the move is valid and alert
// the user if it is not.
bool moveIsValid(char board[3][3], int row, int col);


// checkForWinner iterates through the game board and checks to see
// if either player has won the game or not. A 3 is returned if  
//	player1 won the game and a -3 is returned if player2 won the game.
int checkForWinner(char board[3][3]);
