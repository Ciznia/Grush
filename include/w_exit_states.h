/*
** EPITECH PROJECT, 2023
** Grush
** File description:
** w_exit_states
*/

#ifndef W_EXIT_STATES_H
    #define W_EXIT_STATES_H

    /* Enum key might be unused */
    #define MAYBE_UNUSED(key) key __attribute__((unused))

typedef int w_exit_t;

enum {
    W_EXIT_OK = 0,
    MAYBE_UNUSED(W_EXIT_KO) = 84
};

#endif /* !W_EXIT_STATES_H */
