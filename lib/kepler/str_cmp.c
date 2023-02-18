/*
** EPITECH PROJECT, 2022
** lib
** File description:
** compare n number of characters between 2 strings
*/

#include <unistd.h>

int str_cmp(char const *s1, char const *s2)
{
    if (!s1 || !s2) {
        write(2, "s1 or s2 is NULL\n", 18);
        return 84;
    }
    for (int i = 0;(s1[i] != '\0' || s2[i] != '\0'); i++)
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
    return 0;
}
