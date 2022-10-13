/*
** EPITECH PROJECT, 2019
** CPool_Day04_2019
** File description:
** task03 my_strlen
*/

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i = i + 1;
    }
    return (i);
}
