/*
** EPITECH PROJECT, 2019
** my_compute_power_rec
** File description:
** recursive power
*/

static int check_overflow(long ret, long nb)
{
    long max = 2147483647;
    long min = -2147483648;
    long res = ret * nb;

    if (res < min || max < res)
        return (1);
    return (0);
}

int my_compute_power_rec(int nb, int p)
{
    int ret;

    if (p == 0)
        return (1);
    if (p < 0)
        return (0);
    ret = my_compute_power_rec(nb, p - 1);
    if (check_overflow(ret, nb) == 1)
        return (0);
    return (nb * ret);
}
