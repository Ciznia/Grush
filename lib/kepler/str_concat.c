/*
** EPITECH PROJECT, 2022
** Lib
** File description:
** str_concat
*/

#include "my.h"

char *str_concat(char *dest , char const *src)
{
    int i = 0;
    int l = 0;

    if (!src)
        return dest;
    l = str_len(dest);
    while (src[i] != '\0') {
        dest[l + i] = src [i];
        i++;
    }
    dest[(l + i)] = '\0';
    return dest;
}