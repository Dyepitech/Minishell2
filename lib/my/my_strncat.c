/*
** EPITECH PROJECT, 2019
** my_strncat
** File description:
** cat n char of two strings
*/

#include "my.h"

char *my_strncat(char *dest, char const *src, int n)
{
    int i = my_strlen(dest);

    while (*src != 0 && n > 0)
    {
        dest[i++] = *src;
        src++;
        n--;
    }
    dest[i] = 0;
    return (dest);
}
