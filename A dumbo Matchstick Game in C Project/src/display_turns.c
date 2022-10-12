/*
** EPITECH PROJECT, 2020
** matchstick
** File description:
** display the end of the turn messages
*/

#include "matchstick.h"

void display_ai(int line, int rem_m)
{
    my_putstr("AI removed ");
    my_put_nbr(rem_m);
    my_putstr(" match(es) from line ");
    my_put_nbr(line);
    my_putchar('\n');
}

void display_turn(int line, int rem_m)
{
    my_putstr("Player removed ");
    my_put_nbr(rem_m);
    my_putstr(" match(es) from line ");
    my_put_nbr(line);
    my_putchar('\n');
}
