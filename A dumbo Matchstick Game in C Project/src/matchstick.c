/*
** EPITECH PROJECT, 2020
** matchstick
** File description:
** handles the game
*/

#include "matchstick.h"

void free_all(char **board, int line_nbr)
{
    for (int i = 0; i != line_nbr; i++)
        free(board[i]);
    free(board);
}

void win_display(char *mess, char **board, int line_nbr)
{
    my_putstr(mess);
    free_all(board, line_nbr);
}

int matchstick(int top, int line_nbr, int max_m)
{
    char **board = malloc(sizeof(char *) * line_nbr);

    board = fill_first_board(board, top, line_nbr);
    while (2064) {
        my_putstr("\nYour turn:\n");
        board = player_turn(board, line_nbr, max_m);
        if (board == NULL)
            return (SUCCESS);
        if (win_check(board, line_nbr) == SUCCESS) {
            win_display(PLAYER_LM, board, line_nbr);
            return (AI_W);
        }
        board = ai_turn(board, line_nbr, max_m);
        if (board == NULL)
            return (SUCCESS);
        if (win_check(board, line_nbr) == SUCCESS) {
            win_display(AI_LM, board, line_nbr);
            return (PLAYER_W);
        }
    }
    return (SUCCESS);
}
