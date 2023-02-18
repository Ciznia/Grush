/*
** EPITECH PROJECT, 2022
** lib
** File description:
** my_get_nbr
*/

int nb_get(char const *str)
{
    int res = 0;
    int neg_count = 0;

    for (int i = 0; str[i]; i++) {
        if (str[i] >= '0' && str[i] <= '9')
            res = res * 10 + str[i] - '0';
        if (res != 0 && (!(str[i] >= '0' && str[i] <= '9')))
            break;
        if (str[i] == '-')
            neg_count++;
    }
    if ((neg_count % 2) == 1)
        res *= -1;
    return res;
}
