/*
** EPITECH PROJECT, 2023
** Grush
** File description:
** main
*/

#include <unistd.h>

#include "w_exit_states.h"
#include "w_types.h"

w_exit_t main(int argc UNUSED, char **argv UNUSED)
{
    CONST_WRITE(STDOUT, "Hello\n");
    return W_EXIT_OK;
}
