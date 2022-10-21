/*
** EPITECH PROJECT, 2020
** matchstick
** File description:
** error_handling
*/

#include "matchstick.h"

int error_handling(int ac, char **av)
{
    int nb_lines = 0;

    if (ac != 3) {
        write(2, ERROR_ARG, my_strlen(ERROR_ARG));
        return (FAIL);
    }
    for (int i = 1; i != ac; i++)
        for (int j = 0; av[i][j] != '\0'; j++)
            if (av[i][j] < '0' || av[i][j] > '9') {
                write(2, ERROR_ARG, my_strlen(ERROR_ARG));
                return (FAIL);
            }
    nb_lines = my_atoi(av[1]);
    if (nb_lines < 1 || nb_lines > 100) {
        write(2, ERROR_LINENBR, my_strlen(ERROR_LINENBR));
        return (FAIL);
    }
    return (SUCCESS);
}
