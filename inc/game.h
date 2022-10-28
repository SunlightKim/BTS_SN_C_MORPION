//
// Created by vorge on 28/10/2022.
//

#ifndef C_MORPION_GAME_H
#define C_MORPION_GAME_H

#include <stdio.h>
#include <string.h>

#define TRUE 1          // Define TRUE as 1 (so that we don't use a boolean function)
#define FALSE 0         // Define FALSE as 0

void drawBoard(int board[][3]);                 // Prototype of the function that draws the board
int endGame(int board[][3]);                    // Prototype of the function that checks if the game is over
int inputData(char *invite);                    // Prototype of the function that asks for input
int win(int board[][3]);                        // Prototype of the function that checks if someone won
void game(int board[][3], int player);          // Prototype of the function that runs the game

#endif //C_MORPION_GAME_H