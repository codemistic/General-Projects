/*
** EPITECH PROJECT, 2020
** matchstick
** File description:
** player's turn
*/

#include "matchstick.h"

int player_input_match(int match)
{
    long unsigned size = 10;
    char *buff = malloc(sizeof(char) * size);

    my_putstr("Matches: ");
    if (getline(&buff, &size, stdin) == EOF)
        return (-4);
    match = check_buff(buff);
    if (match == -2)
        return (-2);
    if (match == -3)
        return (-3);
    match = my_atoi(buff);
    free(buff);
    return (match);
}

int player_input_line(int line)
{
    long unsigned size = 10;
    char *buff = malloc(sizeof(char) * size);

    my_putstr("Line: ");
    if (getline(&buff, &size, stdin) == EOF)
        return (-4);
    line = check_buff(buff);
    if (line == -2)
        return (line);
    line = my_atoi(buff);
    free(buff);
    return (line);
}

char **player_turn_match(char **board, int line_nbr, int max_r, int line)
{
    int rem_m = -1;
    int error = 1;

    rem_m = player_input_match(rem_m);
    if (rem_m == -4) {
        my_putchar('\n');
        return (NULL);
    }
    error = legal_match(board, line, rem_m, max_r);
    if (error == FAIL)
        player_turn(board, line_nbr, max_r);
    if (error == SUCCESS) {
        display_turn(line, rem_m);
        board = remove_matches(board, line, rem_m);
        display_board(board, line_nbr);
    }
    return (board);
}

char **player_turn(char **board, int line_nbr, int max_r)
{
    int line = -1;
    int error = 1;

    line = player_input_line(line);
    if (line == -4) {
        my_putchar('\n');
        return (NULL);
    }
    error = legal_line(line, line_nbr);
    while (error == FAIL) {
        line = player_input_line(line);
        if (line == -4) {
            my_putchar('\n');
            return (NULL);
        }
        error = legal_line(line, line_nbr);
    }
    board = player_turn_match(board, line_nbr, max_r, line);
    return (board);
}
