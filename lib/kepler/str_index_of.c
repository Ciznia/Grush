/*
** EPITECH PROJECT, 2022
** Lib
** File description:
** str_index_of
*/

#include "my.h"
#include "w_utils.h"

int str_index_of(char const *str, char to_find)
{
    if (!str)
        return W_SENTINEL;
    for (int i = 0; str[i]; i++) {
        if (str[i] == to_find)
            return i;
    }
    return W_SENTINEL;
}
