/*
** EPITECH PROJECT, 2022
** my_revstr.c
** File description:
** reverse the string
*/

#include "my.h"

char *str_rev(char *str)
{
    int i = 0;
    int length = str_len(str);
    char *temp = mem_calloc((length + 1), sizeof(char));

    while (length)
        temp[i++] = str[--length];
    free(str);
    return temp;
}
