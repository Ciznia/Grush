/*
** EPITECH PROJECT, 2022
** dec to bin
** File description:
** convert a decimal to binary
*/

#include "my.h"
#include "printf.h"
#include "w_utils.h"

int decimal_to_bin(unsigned int nb)
{
    char* bin_nb = NULL;
    int base_nb = (int)nb;
    int rst;
    int i;
    int count;
    char *base = "01";

    if (nb == 0)
        return (int)write(STDOUT, "0", 1);
    for (i = 0; base_nb != 0; i++)
        base_nb /= 2;
    bin_nb = mem_calloc(sizeof(char), i + 1);
    for (i = 0; nb != 0; i++) {
        rst = (int)(nb % 2);
        bin_nb[i] = base[rst];
        nb /= 2;
    }
    count = (int)write(STDOUT, str_rev(bin_nb), str_len(bin_nb));
    free(bin_nb);
    return count;
}
