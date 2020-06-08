/*
** EPITECH PROJECT, 2019
** my_sort_int_array
** File description:
** brute force sort int array
*/

#include "my.h"

void my_sort_int_array(int *array, int size)
{
    int done = 1;
    int i = 0;

    while (done == 1)
    {
        done = 0;
        i = 0;
        while (i + 1 < size)
        {
            if (array[i] > array[i + 1])
            {
                done = 1;
                my_swap(&(array[i]), &(array[i + 1]));
            }
            i++;
        }
    }
}
