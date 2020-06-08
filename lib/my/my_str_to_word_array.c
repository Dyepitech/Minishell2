/*
** EPITECH PROJECT, 2019
** my_str_to_word_array
** File description:
** puts word in an array
*/

#include <stdlib.h>
#include "my.h"

static int is_alpha(char c)
{
    if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z') ||
    ('/' == c || '.' == c || '-' == c ||
    '[' == c || ']' == c || '=' == c ||
    '>' == c || '<' == c || '+' == c || ':' == c)) {
        return (1);
    }
    else if ('0' <= c && c <= '9')
        return (1);
    return (0);
}

static int my_len(char const *str, int cnt)
{
    int i = 0;

    while (str[cnt + i] != 0 && is_alpha(str[cnt + 1]) == 1)
        i++;
    return (i);
}

static int get_word_count(char const *str)
{
    int i = 0;
    int counter = 0;

    while (str[i] != 0)
    {
        if (is_alpha(str[i]) == 1
            && is_alpha(str[i + 1]) == 0)
            counter++;
        i++;
    }
    return (counter);
}

static char *my_str_to_array_dup(char const *str, int *i)
{
    char *res = malloc((my_len(str, *i) + 2) * sizeof(char));
    int j = 0;

    while (str[*i] != 0 && is_alpha(str[*i]) == 1)
    {
        res[j++] = str[*i];
        *i = *i + 1;
    }
    res[j] = 0;
    return (res);
}

char **my_str_to_word_array(char const *str)
{
    int i = 0;
    int count = 0;
    char **res = malloc((get_word_count(str) + 1) * sizeof(char *));

    while (str[i] != 0)
    {
        if (is_alpha(str[i]) == 1)
            res[count++] = my_str_to_array_dup(str, &i);
        if (str[i] != 0)
            i++;
    }
    res[count] = NULL;
    return (res);
}
