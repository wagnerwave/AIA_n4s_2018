/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** n4s my.h
*/

#pragma once

#define READ_SIZE 4096

int need_for_steak(char *str, char **tab);
void my_putchar(char c);
void my_putstr(char const *str);
char **strtowordarray(char *str, char delim);
int my_put_nbr(long nb);
int my_put_nbr_float(double nb);
char *get_next_line(int fd);
