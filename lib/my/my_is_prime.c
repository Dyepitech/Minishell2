/*
** EPITECH PROJECT, 2019
** my_is_prime
** File description:
** check is n is prime
*/

int my_is_prime(int nb)
{
    int i = 2;

    while (i < nb)
    {
        if (nb % i == 0)
            return (0);
        i++;
    }
    if (i == nb)
        return (1);
    return (0);
}
