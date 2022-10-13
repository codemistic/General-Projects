/*
** EPITECH PROJECT, 2020
** matchstick
** File description:
** remove the chosen amount of matches
*/

#include "matchstick.h"

char **remove_matches(char **board, int line, int rem_m)
{
    for (int j = my_strlen(board[line]) - 1; j != 0; j--)
        if (board[line][j] == '|') {
            board[line][j] = ' ';
            rem_m--;
            if (rem_m == 0)
                break;
        }
    return (board);
}
