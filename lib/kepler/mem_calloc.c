/*
** EPITECH PROJECT, 2023
** B-PSU-100-REN-1-1-navy-gabriel.hosquet
** File description:
** mem_calloc
*/

#include "my.h"

void *mem_calloc(size_t mem, size_t size)
{
    void *dest = malloc(mem * size);

    if (dest)
        mem_set(dest, 0, (mem * size));
    return dest;
}
