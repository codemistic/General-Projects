/*
** EPITECH PROJECT, 2020
** matchstick
** File description:
** display the board during the game
*/

#include "matchstick.h"

void display_board(char **board, int line_nbr)
{
    for (int i = 0; i != line_nbr; i++) {
        my_putstr(board[i]);
        my_putchar('\n');
    }
}
