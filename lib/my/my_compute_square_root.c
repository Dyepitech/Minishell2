/*
** EPITECH PROJECT, 2019
** my_compute_square_root
** File description:
** recursive square root
*/

int my_compute_square_root(int nb)
{
    int ret = 1;

    while (ret < 46340 && ret * ret < nb)
        ret++;
    if (ret * ret == nb)
        return (ret);
    return (0);
}
