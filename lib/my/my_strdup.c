/*
** EPITECH PROJECT, 2019
** my_strdup
** File description:
** copy a str
*/

#include <stdlib.h>
#include "my.h"

char *my_strdup(char const *src)
{
    int i = 0;
    char *dest = malloc((my_strlen(src) + 1) * sizeof(char));

    if (dest == NULL)
        return (NULL);
    while (src[i] != 0)
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = 0;
    return (dest);
}
