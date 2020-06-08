/*
** EPITECH PROJECT, 2019
** showmem
** File description:
** dumps the mem
*/

#include "my.h"

static void print_adress(int i, int depth)
{
    if (i / 10 != 0)
        print_adress(i / 10, depth + 1);
    else
    {
        while (depth++ < 7)
            my_putchar('0');
    }
    my_putchar((i % 10) + '0');
}

static void print_hexa(char const *str, int start, int size)
{
    int i = 0;

    while (start + i < size && i < 16)
    {
        if (str[start + i] < 16)
            my_putchar('0');
        my_putnbr_base((int)str[start + i], "0123456789abcdef");
        i++;
        if (i % 2 == 0 && i != 16)
            my_putchar(' ');
    }
    while (i < 16)
    {
        my_putstr("  ");
        if (i % 2 && i + 1 < 16)
            my_putchar(' ');
        i++;
    }
    my_putchar(' ');
}

static void print_body(char const *str, int start, int size)
{
    int i = 0;

    while (start + i < size && i < 16)
    {
        if (' ' <= str[start + i] && str[start + i] <= '~')
            my_putchar(str[start + i]);
        else
            my_putchar('.');
        i++;
    }
    my_putchar('\n');
}

int my_showmem(char const *str, int size)
{
    int i = 0;

    while (i < size)
    {
        if (i % 16 == 0)
        {
            print_adress((i / 16) * 10, 0);
            my_putstr(": ");
            print_hexa(str, i, size);
            print_body(str, i, size);
        }
        i++;
    }
    return (0);
}
