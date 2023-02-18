/*
** EPITECH PROJECT, 2023
** Project
** File description:
** dec_to_hex
*/

#include "my.h"
#include "w_utils.h"

int decimal_to_hex(unsigned int nb)
{
    char* hex_nb = NULL;
    int base_nb = (int)nb;
    int i;
    int rst;
    int count;
    char *base = "0123456789ABCDEF";
    if (nb == 0)
        return (int)write(STDOUT, "0", 1);
    for (i = 0; base_nb != 0; i++)
        base_nb /= 16;
    hex_nb = mem_calloc(sizeof(char), i + 1);
    for (i = 0; nb != 0; i++) {
        rst = (int)(nb % 16);
        hex_nb[i] = base[rst];
        nb /= 16;
    }
    hex_nb = str_rev(hex_nb);
    count = (int)write(1, hex_nb, str_len(hex_nb));
    free(hex_nb);
    return count;
}
