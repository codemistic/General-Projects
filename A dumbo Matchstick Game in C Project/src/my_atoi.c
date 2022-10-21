/*
** EPITECH PROJECT, 2020
** matchstick
** File description:
** my_atoi
*/

#include "matchstick.h"

int my_atoi(char *str)
{
    int nbr = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            nbr = nbr * 10;
            nbr = nbr + (str[i] - '0');
        }
    }
    return (nbr);
}
