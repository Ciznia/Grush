/*
** EPITECH PROJECT, 2022
** dex to oct
** File description:
** tranform decimal to octal
*/

#include "my.h"
#include "w_utils.h"

int decimal_to_octal(unsigned int nb)
{
    char* octal_nb;
    int base_nb = (int)nb;
    int rst;
    int i;
    int count;
    char *base = "01234567";

    if (nb == 0)
        return (int)write(STDOUT, "0", 1);
    for (i = 0; base_nb != 0; i++)
        base_nb /= 8;
    octal_nb = mem_calloc(sizeof(char), i + 1);
    for (i = 0 ; nb != 0 ; i++) {
        rst = (int)(nb % 8);
        octal_nb[i] = base[rst];
        nb /= 8;
    }
    count = (int)write(STDOUT, str_rev(octal_nb), str_len(octal_nb));
    free(octal_nb);
    return count;
}
