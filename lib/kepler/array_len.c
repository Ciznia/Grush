/*
** EPITECH PROJECT, 2023
** B-PSU-100-REN-1-1-navy-gabriel.hosquet
** File description:
** array_len
*/
#include "my.h"
#include "w_utils.h"

int array_len(char const **array)
{
    int i = 0;

    if (!array) {
        CONST_WRITE(STDOUT, "Char ** not malloced\n");
        return W_SENTINEL;
    }
    for (; array[i]; i++);
    return i;
}
