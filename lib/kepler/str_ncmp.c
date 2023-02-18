/*
** EPITECH PROJECT, 2022
** lib
** File description:
** compare n number of characters between 2 strings
*/

#include <unistd.h>
#include "w_utils.h"

int str_ncmp(char const *s1, char const *s2, int n)
{
    if (!s1 || !s2) {
        CONST_WRITE(STDOUT, "s1 or s2 is NULL\n");
        return W_SENTINEL;
    }
    if (n < 1) {
        CONST_WRITE(STDOUT, "n have incorrect value\n");
        return W_SENTINEL;
    }
    for (int i = 0; (s1[i] || s2[i]) && i < n; i++)
        if (s1[i] != s2[i])
            return s1[i] - s2[i];
    return 0;
}
