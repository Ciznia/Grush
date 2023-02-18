/*
** EPITECH PROJECT, 2022
** Lib
** File description:
** char_display
*/

#include "my.h"
#include "w_utils.h"

int char_display(char c)
{
    return (int)write(STDOUT, &c, 1);
}
