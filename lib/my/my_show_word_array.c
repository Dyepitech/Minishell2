/*
** EPITECH PROJECT, 2019
** my_show_word_array
** File description:
** display each words of an array
*/

#include "my.h"
#include <unistd.h>

int my_show_word_array(char * const *tab)
{
    int i = 0;

    while (tab[i] != NULL)
    {
        my_putstr(tab[i]);
        my_putchar('\n');
        i++;
    }
    return (0);
}
