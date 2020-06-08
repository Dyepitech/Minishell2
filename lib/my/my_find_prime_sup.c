/*
** EPITECH PROJECT, 2019
** my_find_prime_sup
** File description:
** find closest greater prime
*/

#include "my.h"

int my_find_prime_sup(int nb)
{
    if (nb < 2)
        nb = 2;
    while (nb < 2147483647)
    {
        if (my_is_prime(nb) == 1)
            return (nb);
        nb++;
    }
    return (0);
}
