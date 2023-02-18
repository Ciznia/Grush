/*
** EPITECH PROJECT, 2022
** put float
** File description:
** put float
*/

#include "my.h"
#include "w_utils.h"

int float_display(float nb, int pre)
{
    char *str = str_get_from_float(nb, pre);
    int len = str_len(str);

    write(STDOUT, str, len);
    free(str);
    return len;
}
