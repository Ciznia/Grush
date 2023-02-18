/*
** EPITECH PROJECT, 2022
** dex to oct
** File description:
** tranform decimal to octal
*/

#include "my.h"

static char *neg_string(int nb)
{
    char *str;
    int base_nb = nb;
    int i;
    int rst;
    char base[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    for (i = 0; base_nb != 0; i++)
        base_nb /= 10;
    str = mem_calloc((i + 2), sizeof(char));
    for (i = 0 ; nb != 0 ; i++) {
        rst = nb % 10;
        str[i] = (char)(base[rst] + '0');
        nb /= 10;
    }
    str[i] = '-';
    return str_rev(str);
}

static char *pos_string(int nb)
{
    char *str;
    int base_nb = nb;
    int i;
    int rst;
    char base[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    for (i = 0; base_nb != 0; i++)
        base_nb /= 10;
    str = mem_calloc((i + 1), sizeof(char));
    for (i = 0 ; nb != 0 ; i++) {
        rst = nb % 10;
        str[i] = (char)(base[rst] + '0');
        nb /= 10;
    }
    return str_rev(str);
}

char *str_get_from_int(int nb)
{
    char* str;

    if (nb > 0)
        str = pos_string(nb);
    else if (nb < 0) {
        nb *= -1;
        str = neg_string(nb);
    } else
        str = "0";
    return str;
}
