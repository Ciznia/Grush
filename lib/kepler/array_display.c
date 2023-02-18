/*
** EPITECH PROJECT, 2022
** Lib
** File description:
** array_display
*/

#include "my.h"
#include "w_utils.h"

int array_display(char * const * array, bool line_jump)
{
    if (!array) {
        CONST_WRITE(STDERR, "Char ** not malloced\n");
        return W_SENTINEL;
    }
    for (int i = 0; array[i]; i++) {
        write(STDOUT, array[i], str_len(array[i]));
        if (line_jump)
            CONST_WRITE(STDOUT, "\n");
    }
    if (!line_jump)
        CONST_WRITE(STDOUT, "\n");
    return 0;
}
