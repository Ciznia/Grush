/*
** EPITECH PROJECT, 2023
** Project
** File description:
** printf
*/

#ifndef PRINTF_H_
    #define PRINTF_H_

    #include <stdarg.h>

void flag_select(int *count, char *flag, va_list list);
int sc_format(float nb);
int long_display(long long nb);
int long_long_display(long long nb);
int decimal_to_octal(unsigned int nb);
int convert(long long n);
int decimal_to_bin(unsigned int nb);
int decimal_to_hex(unsigned int nb);

#endif /* !PRINTF_H_ */
