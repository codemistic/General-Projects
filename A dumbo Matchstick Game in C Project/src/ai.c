/*
** EPITECH PROJECT, 2020
** matchstick
** File description:
** ai turn
*/

#include "matchstick.h"

int safe_random_match(char **board, int line, int max_r)
{
    int rem_m = random() % max_r;
    int nbr = 0;

    for (int i = 0; board[line][i] != '\0'; i++)
        if (board[line][i] == '|')
            nbr++;
    while (rem_m > max_r || rem_m > nbr || rem_m == 0)
        rem_m = random() % max_r;
    return (rem_m);
}

int safe_random_line(char **board, int line_nbr)
{
    int line = random() % line_nbr;
    int nbr = 0;

    while (line == 0 || nbr == 0) {
        line = random() % line_nbr;
        for (int i = 0; board[line][i] != '\0'; i++)
            if (board[line][i] == '|')
                nbr++;
    }
    return (line);
}

char **ai_turn(char **board, int line_nbr, int max_r)
{
    int nbr = 0;
    int line = 0;
    int rem_m = 0;

    my_putstr("\nAI's turn...\n");
    for (int i = 0; i != line_nbr; i++)
        for (int j = 0; board[i][j] != '\0'; j++)
            if (board[i][j] == '|')
                nbr++;
    line = safe_random_line(board, line_nbr);
    rem_m = safe_random_match(board, line, max_r);
    board = remove_matches(board, line, rem_m);
    display_ai(line, rem_m);
    display_board(board, line_nbr);
    return (board);
}
