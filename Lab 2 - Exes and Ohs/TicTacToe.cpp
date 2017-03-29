/* Victor Espinoza
* CECS 282, Section 1
* Spring 2014
* Due Date: 2/11/14
* Lab #2- Exes and Ohs
*/

#include <iostream>
#include <regex>
#include <cstdlib>
#include <string>
#include "TicTacToe.h"
using namespace std;
#define BOARD_SIZE 3

int main(int argc, char* argv[]) {
   const int NUMBER_OF_MOVES = 9;
   char player = 'O';
   int row, column, winner=0;
   //create the board game
   char gameBoard[BOARD_SIZE][BOARD_SIZE] = {
      {0, 0, 0},
      {0, 0, 0},
      {0, 0, 0}
   };

   cout << "Thank you for using this Tic-Tac-Toe program!\n" <<
    "Lets get started..." << endl;

   for (int i=0; i<9; i++){
      //print out the board game
      printBoard(gameBoard);
      player = ( player == 'X' ? 'O' : 'X');
      //reset row and column values to verify user input
      row = -1; column = -1;
      //receive the user's move
      getMove(row, column, player);
      //make sure that user's move is not already taken
      while(!moveIsValid(gameBoard, row, column)){
         cout << "That space is already taken, please select " <<
          "another move!" << endl;
         getMove(row, column, player);
      }//end while
      //assign the player's move to the game board.
      gameBoard[row][column] = (player == 'X' ?  1 : -1);
      winner = checkForWinner(gameBoard);
      //if a player won, exit the game immediately!
      if (winner == 3 || winner == -3)
         break;
   }//end while loop

   //print results
   cout << "\nFinal Results:" << endl;
   printBoard(gameBoard);
   if(winner == 3)
      cout << "\nPlayer X Wins!" << endl;
   else if (winner == -3)
      cout << "\nPlayer O Wins!" << endl;
   else
      cout << "\nTie Game!" << endl;

   cout << "\nThank you for playing Tic-Tac-Toe! The program" <<
    " will now exit.\nEnjoy the rest of your day!" << endl;

}//close main()


void printBoard(char board[BOARD_SIZE][BOARD_SIZE]){
   //print the game board
   cout << "\n- 0 1 2";
   for (int i = 0; i < BOARD_SIZE; i++){
      cout << "\n" << i << " ";
      for (int j = 0; j < BOARD_SIZE; j++){
         cout << (board[i][j] == 0 ?  ". " : board[i][j] > 0 ?  "X " : "O ");
      }//close inner for loop
   }//close outer for loop
   cout << endl;
}//close printBoard(...)


bool moveIsValid(char board[BOARD_SIZE][BOARD_SIZE], int row, int col){
   return board[row][col] == 0;
}//close moveIsValid


void getMove(int &row, int &col, char player){
   int pos;
   string input, rowStr, colStr;
   do {
      //prompt user for input
      cout << "\n" << player << "'s turn! " << endl;
      cout << "Please enter a valid move (Ex: 0,1): ";
      //input whole line
      getline(cin, input);
      //split the input into two different row/column strings
      pos = input.find_first_of(',');
      rowStr = input.substr(0, pos);
      colStr = (pos > -1) ? input.substr(pos+1) : input.substr(input.size());

      //make sure both row and column are integers
      if(!regex_match(rowStr, regex("(\\+|-)?[[:digit:]]+")) || 
         !regex_match(colStr, regex("(\\+|-)?[[:digit:]]+")))	
         cout << "You must enter the move in the following format: "
          << "row,column (Ex: 0,1)!" << endl;
      else {
         //assign user input to row and column variables
         row = stoi(rowStr);	
         col = stoi(colStr);	
         //inform user if numbers entered are out of range
         if(row < 0 || row > 2 || col < 0 || col > 2)
            cout << "The row and column numbers must be within the "
             << "range of 0-2!" << endl;
      } //end else
      //end while
   } while(row < 0 || row > 2 || col < 0 || col > 2);

}//close getMove(...)


int checkForWinner(char board[3][3]) {
   //Local Variables:
   const int X = 1, O = -1;

   //Determine the winner
   for (char i = 0; i < BOARD_SIZE; i++) {
      //check rows and columns for winning X moves. Also, check both diagonal
      //cases (we only do this once because it would be inefficient to 
      //check these cases three times).
      if ((board[i][0] == X && board[i][1] == X && board[i][2] == X) ||
       (board[0][i] == X && board[1][i] == X && board[2][i] == X) || (i
       == 0 && ((board[0][0] == X && board[1][1] == X && board[2][2] == X) 
       || (board[0][2] == X && board[1][1] == X && board[2][0] == X))))
         return 3;
      //check rows and columns for winning Y moves. Also, check both diagonal
      //cases (we only do this once because it would be inefficient to 
      //check these cases three times).
      else if ((board[i][0] == O && board[i][1] == O && board[i][2] == O) 
       || (board[0][i] == O && board[1][i] == O && board[2][i] == O) || (i
       == 0 && ((board[0][0] == O && board[1][1] == O && board[2][2] == O) 
       || (board[0][2] == O && board[1][1] == O && board[2][0] == O))))
         return -3;
   }//end for loop
   //If we reach the end of the loop, then that means that nobody has won yet.
   //We return a value of 0 to account for this.
   return 0;
}//close checkForWinner(...)


/*Output:

Thank you for using this Tic-Tac-Toe program!
Lets get started...

- 0 1 2
0 . . .
1 . . .
2 . . .

X's turn!
Please enter a valid move (Ex: 0,1): fasda
You must enter the move in the following format: row,column (Ex: 0,1)!

X's turn!
Please enter a valid move (Ex: 0,1): -1,21
The row and column numbers must be within the range of 0-2!

X's turn!
Please enter a valid move (Ex: 0,1): 1,12
The row and column numbers must be within the range of 0-2!

X's turn!
Please enter a valid move (Ex: 0,1): 0,0

- 0 1 2
0 X . .
1 . . .
2 . . .

O's turn!
Please enter a valid move (Ex: 0,1): 0,1a
You must enter the move in the following format: row,column (Ex: 0,1)!

O's turn!
Please enter a valid move (Ex: 0,1): 0,a
You must enter the move in the following format: row,column (Ex: 0,1)!

O's turn!
Please enter a valid move (Ex: 0,1): 1,0

- 0 1 2
0 X . .
1 O . .
2 . . .

X's turn!
Please enter a valid move (Ex: 0,1): 0,1

- 0 1 2
0 X X .
1 O . .
2 . . .

O's turn!
Please enter a valid move (Ex: 0,1): 1,1

- 0 1 2
0 X X .
1 O O .
2 . . .

X's turn!
Please enter a valid move (Ex: 0,1): 0,2

Final Results:

- 0 1 2
0 X X X
1 O O .
2 . . .

Player X Wins!

Thank you for playing Tic-Tac-Toe! The program will now exit. 
Enjoy the rest of your day!
Press any key to continue . . .

*/