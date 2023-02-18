/*
** EPITECH PROJECT, 2022
** Lib
** File description:
** str_display
*/

#include "my.h"
#include "w_utils.h"

int str_display(char const *str)
{
    if (!str) {
        CONST_WRITE(STDERR, "STR empty\n");
        return W_SENTINEL;
    }
    return (int)write(STDOUT, str, str_len(str));
}
