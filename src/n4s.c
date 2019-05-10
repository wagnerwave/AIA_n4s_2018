/*
** EPITECH PROJECT, 2018
** n4s.c
** File description:
** algo etc
*/

#include <string.h>
#include <stdlib.h>
#include "my.h"

static void print_n_reset(char *str)
{
    my_putstr(str);
    str = get_next_line(0);
}

static void algo(float weel_rotate_left, float weel_rotate_right)
{
    float weel_rotate;

    if (weel_rotate_left < weel_rotate_right)
        weel_rotate = weel_rotate_left;
    else
        weel_rotate = weel_rotate_right;
    if (weel_rotate >= 2000)
        print_n_reset("CAR_FORWARD:1\n");
    else {
        my_putstr("CAR_FORWARD:");
        my_put_nbr_float(0.000410 * weel_rotate + -0.0241);
        print_n_reset("\n");
    }
}

static void weel_dir(float weel_rotate)
{
    if (weel_rotate >= 1500)
        print_n_reset("0.008\n");
    else {
        my_put_nbr_float(-0.00000000015 *
        weel_rotate * weel_rotate * weel_rotate + 0.0000007
        * weel_rotate * weel_rotate - 0.001 * weel_rotate + 0.6);
        print_n_reset("\n");
    }
}

static void rotate(float left, float right, float weel_rotate_left,
float weel_rotate_right)
{
    float coef = left - right;
    if (coef < 0)
        my_putstr("WHEELS_DIR:-");
    else
        my_putstr("WHEELS_DIR:");
    if (weel_rotate_left < weel_rotate_right)
        weel_dir(weel_rotate_left);
    else
        weel_dir(weel_rotate_right);
}

int need_for_steak(char *str, char **tab)
{
    my_putstr("START_SIMULATION\n");
    while ((str = get_next_line(0)) == NULL);
    my_putstr("CAR_FORWARD:1.1585123\n");
    str = get_next_line(0);
    (str == NULL) ? exit(84) : 0;
    while (1) {
        my_putstr("GET_INFO_LIDAR\n");
        str = get_next_line(0);
        (str == NULL) ? exit(84) : 0;
        tab = strtowordarray(str, ':');
        algo(atof(tab[17]), atof(tab[21]));
        rotate(atof(tab[3]), atof(tab[34]), atof(tab[17]), atof(tab[21]));
        if (strcmp(tab[35], "Track Cleared") == 0) {
            print_n_reset("stop_simulation\n");
            return 0;
        }
    }
    return 0;
}
