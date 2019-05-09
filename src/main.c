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
    size_t i = strlen(str);

    write(1, str, i);
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
        my_put_nbr_float(-0.000000000148682376182 *
mid * mid * mid + 0.0000006918567543568 * mid
* mid - 0.001076432049432 * mid + 0.609633999633699);
        print_n_reset("\n");
    }
}

static void middle(float left, float right, float midl, float midr)
{
    float coef = left - right;

    if (coef < 0)
        write(1, "WHEELS_DIR:-", 11);
    else
        write(1, "WHEELS_DIR:", 10);
    if (midl < midr)
        go_to_middle(midl);
    else
        go_to_middle(midr);
}

static int need_for_steak(void)
{
    char *str = "";
    char **tab = NULL;

    puts("START_SIMULATION");
    while ((str = get_next_line(0)) == NULL);
    puts("CAR_FORWARD:1");
    str = get_next_line(0);
    while (1) {
        puts("GET_INFO_LINDAR");
        str = strtok(str, ":");
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
