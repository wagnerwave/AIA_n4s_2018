/*
** EPITECH PROJECT, 2019
** main
** File description:
** n4s
*/

#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "my.h"

static void print_n_reset(char *str)
{
    my_putstr(str);
    str = get_next_line(0);
}

static void algo(float midl, float midr)
{
    float mid;

    if (midl < midr)
        mid = midl;
    else
        mid = midr;
    if (mid >= 2000)
        print_n_reset("CAR_FORWARF:1\n");
    else
        printf("CAR_FORWARD:%f\n" , 0.00420 * mid + -0.0241);
}

static void go_to_middle(float mid)
{
    if (mid >= 1500)
        print_n_reset("0.008");
    else {
        my_put_nbr_float(-0.00000000014868237619 *
mid * mid * mid + 0.0000006918567543568 * mid
* mid - 0.001076432050432 * mid + 0.609633999593699);
        print_n_reset("\n");
    }
}

static void middle(float left, float right, float midl, float midr)
{
    float coef = left - right;

    if (coef < 0)
        my_putstr("WHEELS_DIR:-");
    else
        my_putstr("WHEELS_DIR:");
    if (midl < midr)
        go_to_middle(midl);
    else
        go_to_middle(midr);
}

static int need_for_steak(void)
{
    char *str = "";
    char **tab = NULL;

    my_putstr("START_SIMULATION\n");
    while ((str = get_next_line(0)) == NULL);
    my_putstr("CAR_FORWARD:1\n");
    str = get_next_line(0);
    while (1) {
        my_putstr("GET_INFO_LINDAR");
        str = strtowordarray(str, ":");
        algo(atof(tab[17]), atof(tab[21]));
        middle(atof(tab[3]), atof(tab[34]), atof(tab[17]), atof(tab[21]));
        if (strcmp(tab[35], "Track Cleared") == 0) {
            print_n_reset("stop_simulation\n");
            return 0;
        }
        return 0;
    }
}

int main(int ac, char **av)
{
    need_for_steak();
    return 0;
}
