/*
** EPITECH PROJECT, 2019
** showstr
** File description:
** prints nonpritable chars in hexa
*/

#include "my.h"

static int is_printable(char c)
{
    if (' ' <= c && c <= '~')
        return (1);
    return (0);
}

int my_showstr(char const *str)
{
    int i = 0;

    while (str[i] != 0)
    {
        if (is_printable(str[i]) == 1)
            my_putchar(str[i]);
        else
        {
            my_putchar('\\');
            if (str[i] < 16)
                my_putchar('0');
            my_putnbr_base((int) str[i], "0123456789abcdef");
        }
    i++;
    }
    return (0);
}
