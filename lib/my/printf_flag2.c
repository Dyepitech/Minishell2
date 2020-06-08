/*
** EPITECH PROJECT, 2019
** my_printf2.h
** File description:
** my_printf2
*/

#include <unistd.h>
#include <stdarg.h>
#include "my.h"

void n_printf(va_list *my_printf)
{
    int *n;
    n = va_arg (*my_printf, int *);

    my_putchar(*n);
}

void x_printf(va_list *my_printf)
{
    char *str;
    int i;
    str = "0123456789abcdef";
    i = va_arg (*my_printf, int);

    my_putnbr_base(i, str);
}

void o_printf(va_list *my_printf)
{
    char *str;
    int i;
    str = "01234567";
    i = va_arg (*my_printf, int);

    my_putnbr_base(i, str);
}

void b_printf(va_list *my_printf)
{
    char *str;
    int i;
    str = "01";
    i = va_arg (*my_printf, int);

    my_putnbr_base(i, str);
}

void pr_printf(va_list *my_printf)
{
    (void) my_printf;
    my_putchar('%');
}
