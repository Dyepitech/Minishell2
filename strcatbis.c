/*
** EPITECH PROJECT, 2020
** strcatbis
** File description:
** strcatbis
*/

#include <stdlib.h>
#include <stddef.h>

char *strcatbis(char **str1, char *str2, int freed)
{
    char *result;
    int length1 = 0;
    int length2 = 0;
    int act_char = 0;

    if (*str1 != NULL)
        for (; (*str1)[length1]; length1++);
    if (str2 != NULL)
        for (; str2[length2]; length2++);
    if ((result = malloc(sizeof(char) * (length1 + length2 + 1))) == NULL)
        return (NULL);
    for (int index = 0; index < length1; index++, act_char++)
        result[act_char] = (*str1)[index];
    for (int index = 0; index < length2 + 1; index++, act_char++)
        result[act_char] = str2[index];
    if (freed == 1)
        free((*str1));
    return (result);
}
