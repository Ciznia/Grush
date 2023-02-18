/*
** EPITECH PROJECT, 2022
** Lib
** File description:
** str_split
*/

#include "my.h"
#include "w_utils.h"

static bool is_separator(char c, char const *separators)
{
    return (str_index_of(separators, c) != W_SENTINEL);
}

static int count_sepa(char const *str, char const *separators)
{
    int count = 0;

    for (int i = 0; str[i]; i++)
        if (is_separator(str[i], separators))
            count++;
    return count;
}

static char **string_split(char const *str, char const *separators)
{
    char **array = NULL;
    size_t len = 0;
    size_t count = 0;
    size_t i = 0;

    array = mem_calloc(sizeof(char *), (count_sepa(str, separators) + 2));
    while (true) {
        if ((is_separator(str[i], separators) &&
        !is_separator(str[i + 1], separators)) || str[i]) {
            array[count] = str_copy_at(str, (i - len), i);
            count++;
            len = 0;
        } else {
            len++;
        } if (!str[i])
            break;
        i++;
    }
    return array;
}

char **str_split(char const *str, char const *separators)
{
    if (!str || !separators)
        return NULL;
    return string_split(str, separators);
}
