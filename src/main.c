/*
** EPITECH PROJECT, 2018
** n4s
** File description:
** n4s
*/

#include "my.h"
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

static void prompt(char *str)
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
        prompt("CAR_FORWARD:1\n");
    else {
        my_putstr("CAR_FORWARD:");
        my_put_nbr_float(0.000410 * mid + -0.0241);
        prompt("\n");
    }
}

static void go_dir(float mid)
{
    if (mid >= 1500)
        prompt("0.008\n");
    else {
        my_put_nbr_float(-0.000000000148682376182 *
                         mid * mid * mid + 0.0000006918567543568 * mid
                         * mid - 0.001076432049432 * mid + 0.609633999633699);
        prompt("\n");
    }
}

static void dir(float left, float right, float midl, float midr)
{
    float coef = left - right;

    if (coef < 0)
        my_putstr("WHEELS_DIR:-");
    else
        my_putstr("WHEELS_DIR:");
    if (midl < midr)
        go_dir(midl);
    else
        go_dir(midr);
}

int main(void)
{
    char *str = "";
    char **tab = NULL;

    my_putstr("START_SIMULATION\n");
    while ((str = get_next_line(0)) == NULL);
    my_putstr("CAR_FORWARD:1\n");
    str = get_next_line(0);
    while (1) {
        my_putstr("GET_INFO_LIDAR\n");
        str = get_next_line(0);
        tab = strtowordarray(str, ':');
        algo(atof(tab[17]), atof(tab[21]));
        dir(atof(tab[3]), atof(tab[34]), atof(tab[17]), atof(tab[21]));
        if (strcmp(tab[35], "Track Cleared") == 0) {
            prompt("stop_simulation\n");
            return (0);
        }
    }
    return (0);
}
