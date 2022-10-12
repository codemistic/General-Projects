/*
** EPITECH PROJECT, 2020
** matchstick
** File description:
** check the buffer to check if there is numbers
*/

#include "matchstick.h"

int check_buff(char *buffer)
{
    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == '\n')
            continue;
        if (buffer[i] < '0' || buffer[i] > '9') {
            my_putstr("Error: invalid input (positive number expected)\n");
            return (-2);
        }
    }
    if (my_atoi(buffer) == 0)
        return (-3);
    return (SUCCESS);
}
