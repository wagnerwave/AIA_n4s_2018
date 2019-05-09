/*
** EPITECH PROJECT, 2018
** my_putstr
** File description:
** display a string
*/

#include <unistd.h>

void my_putchar(char c);

void my_putstr(char const *str)
{
    for (size_t i = 0; str[i]; i++)
        my_putchar(str[i]);
}
