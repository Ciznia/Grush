/*
** EPITECH PROJECT, 2023
** B-PSU-100-REN-1-1-navy-gabriel.hosquet
** File description:
** array_free
*/

#include "my.h"
#include "w_utils.h"

int array_free(char **array)
{
    size_t size;

    if (!array) {
        CONST_WRITE(STDOUT, "Char ** not malloced\n");
        return W_SENTINEL;
    }
    size = array_len((char const **)array);
    for (size_t i = 0; i < size; i++) {
        if (!array[i]) {
            error_display("array[%i] not malloced\n", i);
            continue;
        }
        free(array[i]);
    }
    free(array);
    return 0;
}
