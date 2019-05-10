/*
** EPITECH PROJECT, 2019
** n4s
** File description:
** n4s
*/

#include "my.h"

int my_put_nbr_float(double nb)
{
    float nbr = nb;

    my_put_nbr((int)nb);
    my_putchar('.');
    nbr -= (int)nb;
    nbr *= 100;
    if (nbr < 10)
        my_putchar('0');
    my_put_nbr((int)nbr);
    return (0);
}
