/*
** EPITECH PROJECT, 2020
** matchstick
** File description:
** check if the moves are legal
*/

#include "matchstick.h"

int legal_match2(int rem_m)
{
    if (rem_m == -2)
        return (FAIL);
    if (rem_m == -3) {
        my_putstr("Error: you have to remove at least one match\n");
        return (FAIL);
    }
    return (SUCCESS);
}

int legal_match(char **board, int line, int rem_m, int max_rem)
{
    int nbr = 0;

    for (int i = 0; board[line][i] != '\0'; i++)
        if (board[line][i] == '|')
            nbr++;
    if (rem_m > nbr) {
        my_putstr("Error: not enough matches on this line\n");
        return (FAIL);
    }
    if (rem_m > max_rem) {
        my_putstr("Error: you cannot remove more than ");
        my_put_nbr(max_rem);
        my_putstr(" matches per turn\n");
        return (FAIL);
    }
    if (legal_match2(rem_m) == FAIL)
        return (FAIL);
    return (SUCCESS);
}

int legal_line(int line_r, int line_nbr)
{
    if (line_r == -2)
        return (FAIL);
    if (line_r > 0 && line_r < (line_nbr - 1))
        return (SUCCESS);
    my_putstr("Error: this line is out of range\n");
    return (FAIL);
}
