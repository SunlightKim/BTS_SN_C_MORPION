//
// Created by vorge on 28/10/2022.
//

#include "../inc/game.h"

void drawBoard(int board[][3])                                      // Draws the board
{
    int i, j;
    printf("\n-------\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("|");
            switch (board[i][j])                                    // Checks the value of the board and prints the corresponding symbol
            {
                case 0:
                    printf(" ");
                    break;
                case 1:
                    printf("0");
                    break;
                case 2:
                    printf("X");
                    break;
            }
        }
        printf("|\n");
        printf("-------\n");
    }
}

int endGame(int board[][3])                                         // Checks if the game is over
{
    int i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (board[i][j] == 0)                                 // If there is an empty space, the game is not over
                return FALSE;
        }
    }
    return TRUE;                                                // If there are no empty spaces, the game is over
}

int inputData(char *invite)
{
    int value;
    do                                                          // Loop that keeps asking for input until a valid one is given
    {
        printf("%s", invite);
        scanf_s("%d", &value);
    } while ( value < 1 || value > 3);                          // Checks if the input is valid (1, 2 or 3)
    return value;
}

int win(int board[][3])                                         // Checks if there is a winner
{
    int i;
    /* TESTING ROWS */
    for (i = 0; i < 3; i++)
    {
        if ( (board[i][0] > 0) && (board[i][0] == board[i][1]) && (board[i][1] == board[i][2]) )                // Checks if there is a winner in the rows
        {
            puts ("WIN");
            return TRUE;
        }
    }

    /* TESTING COLUMNS */
    for (i = 0; i < 3; i++)
    {
        if ( (board[0][i] > 0) && (board[0][i] == board[1][i]) && (board[1][i] == board[2][i]) )                // Checks if there is a winner in the columns
        {
            puts ("WIN");
            return TRUE;
        }
    }

    /* TESTING DIAGONALS */
    if ( (board[0][0] > 0) && (board[0][0] == board[1][1]) && (board[1][1] == board[2][2]) )                    // Checks if there is a winner in the first diagonal
    {
        puts ("WIN");
        return TRUE;
    }
    if ( (board[0][2] > 0) && (board[0][2] == board[1][1]) && (board[1][1] == board[2][0]) )                    // Checks if there is a winner in the second diagonal
    {
        puts ("WIN");
        return TRUE;
    }
    return FALSE;
}

void game(int board[][3], int player)                           // Main function of the game
{
    int pos_x, pos_y;
    int correct = FALSE;                                       // Variable that checks if the input is valid

    do
    {
        printf("Player %d\n", player);
        pos_x = inputData("Row: ");
        pos_y = inputData("Column: ");

        if (board[pos_x - 1][pos_y - 1] > 0) { printf("This cell is already filled.\n"); }
        else {
            board[pos_x - 1][pos_y - 1] = player;           // If the input is valid, the board is updated
            correct = TRUE;                                 // The input is valid
        }
    } while (!correct);                                     // Loop that keeps asking for input until a valid one is given

    drawBoard(board);                                       // Draws the board with the updated values
}