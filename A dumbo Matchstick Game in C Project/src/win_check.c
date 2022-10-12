/*
** EPITECH PROJECT, 2020
** matchstick
** File description:
** check if there is matches remaining
*/

#include "matchstick.h"

int win_check(char **board, int line_nbr)
{
    int nbr = 0;

    for (int i = 0; i != line_nbr; i++)
        for (int j = 0; board[i][j] != '\0'; j++)
            if (board[i][j] == '|')
                nbr++;
    if (nbr == 0)
        return (SUCCESS);
    return (FAIL);
}
