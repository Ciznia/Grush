/*
** EPITECH PROJECT, 2022
** Lib
** File description:
** str_split_optimized for on split
*/

#include "my.h"

static int count_sepa(char const *str)
{
    int count = 0;

    for (int i = 0; str[i]; i++)
        if (str[i] == '\n')
            count++;
    return count;
}

static char **string_split(char const *str)
{
    char **array = NULL;
    size_t len = 0;
    size_t count = 0;
    size_t i = 0;

    array = mem_calloc(sizeof(char *), (count_sepa(str) + 2));
    while (true) {
        if ((str[i] == '\n' && str[i + 1] != '\n') || str[i]) {
            array[count] = str_copy_at(str, (i - len), i);
            count++;
            len = 0;
        } else
            len++;
        if (!str[i])
            break;
        i++;
    }
    return array;
}

char **str_split_optimized(char const *str)
{
    return (!str) ? NULL : string_split(str);
}
