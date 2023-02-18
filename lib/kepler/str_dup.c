/*
** EPITECH PROJECT, 2022
** Lib
** File description:
** str_dup
*/

#include "my.h"

char *str_dup(char const *src)
{
    int len = 0;
    char *ptr = NULL;

    if (src == NULL) {
        error_display("src not malloced\n");
        return NULL;
    }
    len = str_len(src);
    ptr = mem_calloc((len + 1), sizeof(char));
    for (int i = 0 ; src[i] != '\0' ; i++)
        ptr[i] = src [i];
    return ptr;
}
