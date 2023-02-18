/*
** EPITECH PROJECT, 2022
** scientific format
** File description:
** put an int in the normalized scientific format
*/

#include "my.h"
#include "printf.h"
#include "w_utils.h"

static void display_sign (int i, int *count)
{
    if (i < 0)
        *count += (int)write(1,"-",1);
    if (i >= 0)
        *count += (int)write(1,"+",1);
    if (i < 10 && i > -10)
        *count += nb_display(0);
    *count += nb_display(i);
}

int sc_format(float nb)
{
    int i = 0;
    int count = 0;

    if (nb < 0) {
        nb *= -1;
        count += (int)write(STDOUT, "-", 1);
    }
    if (nb > 10)
        for (; nb > 10; ++i)
            nb /= 10;
    if (nb < 1)
        for (; nb < 1 ; --i)
            nb *= 10;
    count += float_display(nb, 6);
    count += (int)write(STDOUT, "E", 1);
    display_sign(i, &count);
    return count;
}
