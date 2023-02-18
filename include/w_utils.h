/*
** EPITECH PROJECT, 2023
** Grush
** File description:
** w_utils
*/

#ifndef W_UTILS_H_
    #define W_UTILS_H_

    #define UNUSED __attribute__((unused))
    #define CONST_WRITE(std, buff) (write(std, buff, sizeof (buff)))

    #define W_SENTINEL (-1)

enum {
    STDIN = 0,
    STDOUT = 1,
    STDERR = 2
};
#endif
