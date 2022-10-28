#include <string.h>
#include "inc/game.h"

int main () {
   int board[3][3];
   int player = 1;

   memset (board, 0, 9*sizeof(int));                      // Used to initialize the board with 0's (empty spaces)
   drawBoard(board);                                                    // Draws the board
   do {                                                                 // Loop that keeps the game running
      game(board, player);
      if (player == 1) {                                                // Changes the player after each turn
         player = 2;
      } else {
         player = 1;
      }
   }
   while (( !win(board)) && (!endGame(board)) );                        // Checks if there is a winner or if the game is over
   return 0;
}