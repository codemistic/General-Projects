/*
** EPITECH PROJECT, 2020
** matchstick
** File description:
** fill the board at the launch of the game
*/

#include "matchstick.h"

char *fill_playable_part(char *line, int i, int top)
{
    static int match = 1;

    for (int j = 0; j != top; j++) {
        if (j == ((top / 2) -  i + 1))
            for (int z = 0; z != match; z++, j++)
                line[j] = '|';
        line[j] = ' ';
        if (j == 0 || j == top - 1)
            line[j] = '*';
    }
    match = match + 2;
    return (line);
}

char **fill_first_board(char **board, int top, int line_nbr)
{
    for (int i = 0; i != line_nbr; i++) {
        board[i] = malloc(sizeof(char) * (top + 2));
        if (i == 0 || i == line_nbr - 1)
            for (int j = 0; j != (top + 2); j++)
                board[i][j] = '*';
        else
            board[i] = fill_playable_part(board[i], i, (top + 2));
    }
    display_board(board, line_nbr);
    return (board);
}
