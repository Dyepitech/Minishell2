/*
** EPITECH PROJECT, 2019
** my_strcmp
** File description:
** compares str
*/

#include <stddef.h>

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    for (i = 0; s1[i] != 0 && s2[i] != 0 && s1[i] == s2[i]; i++);
    if (s1[i] > s2[i])
        return (1);
    else if (s1[i] < s2[i])
        return (-1);
    return (0);
}

int my_strcmp2(char const *str1, char const *str2)
{
    int i = 0;

    if (str1 == NULL || str2 == NULL)
        return 0;
    for (i = 0; str1[i] != '\0'; i++)
        if (str1[i] != str2[i])
            return 0;
    if (str1[i] != str2[i])
        return 0;
    return 1;
}