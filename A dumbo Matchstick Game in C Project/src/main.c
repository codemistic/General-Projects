

#include "matchstick.h"

int main(int ac, char **av)
{
    int win = 0;
    int top;
    int line_nbr;
    int max_m;

    if (error_handling(ac, av) == FAIL)
        return (FAIL);
    top = (my_atoi(av[1]) * 2 - 1);
    line_nbr = my_atoi(av[1]) + 2;
    max_m = my_atoi(av[2]);
    win = matchstick(top, line_nbr, max_m);
    return (win);
}
