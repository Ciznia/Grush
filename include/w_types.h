/*
** EPITECH PROJECT, 2023
** Grush
** File description:
** w_types
*/

#ifndef W_TYPES_H_
    #define W_TYPES_H_

    #define UNUSED __attribute__((unused))
    #define CONST_WRITE(std, buff) (write(std, buff, sizeof (buff)))

enum {
    STDIN = 0,
    STDOUT = 1,
    STDERR = 2
};

typedef unsigned long size_t;
typedef unsigned char byte_t;
#endif
