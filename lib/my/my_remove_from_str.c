/*
** EPITECH PROJECT, 2019
** my_remove_from_str
** File description:
** remove str from str
*/

#include "my.h"

static void remove_firstn_str(char *str, int pos)
{
    int i = 0;

    while (str[pos] != 0)
        str[i++] = str[pos++];
    str[i] = 0;
}

void my_remove_from_str(char const *rm, char *str)
{
    int len = my_strlen(rm);

    while (*str != 0)
    {
        if (my_strncmp(str, rm, len) == 0)
            remove_firstn_str(str, len);
        str++;
    }
}
