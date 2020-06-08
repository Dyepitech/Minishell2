/*
** EPITECH PROJECT, 2019
** my_strcat
** File description:
** cat two strings
*/

#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    int i = my_strlen(dest);

    while (*src != 0)
    {
        dest[i++] = *src;
        src++;
    }
    dest[i] = 0;
    return (dest);
}
