/*
** EPITECH PROJECT, 2019
** my_printf_flags
** File description:
** my_printf
*/

#include <unistd.h>
#include <stdarg.h>
#include "my.h"

void s_printf(va_list *my_printf)
{
    char *s_flag;

    s_flag = va_arg(*my_printf, char *);

    my_putstr(s_flag);
}

void d_printf(va_list *my_printf)
{
    int d_flag;

    d_flag = va_arg(*my_printf, int);

    my_put_nbr(d_flag);
}

void f_printf(va_list *my_printf)
{
    double f_flag;

    f_flag = va_arg(*my_printf, double);

    my_put_nbr(f_flag);
}

void c_printf(va_list *my_printf)
{
    int c_flag;

    c_flag = va_arg(*my_printf, int);

    my_putchar(c_flag);
}

void l_printf(va_list *my_printf)
{
    long int l_flag;

    l_flag = va_arg(*my_printf, long int);

    my_put_nbr(l_flag);
}