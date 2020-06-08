/*
** EPITECH PROJECT, 2019
** grep
** File description:
** get the next line for grep
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"

static char *my_strcat_dup(char *s, char *b)
{
    static int init = 0;
    char *new_save;

    if (init == 0 && s == NULL){
        s = malloc(1 * sizeof(char));
        s[init++] = 0;
    }
    new_save = malloc((my_strlen(s) + my_strlen(b) + 1) * sizeof(char));
    new_save[0] = 0;
    my_strcat(new_save, s);
    my_strcat(new_save, b);
    free(s);
    return (new_save);
}

static int my_find(char *str, char c)
{
    int i = 0;

    while (str[i] != 0)
    {
        if (str[i] == c)
            return (1);
        i++;
    }
    return (0);
}

static void my_remove_line(char *save)
{
    int i = 0;
    int j = 0;

    while (save[i] != 0 && save[i] != '\n')
        i++;
    if (save[i] == '\n')
        i++;
    while (j <= i)
    {
        if (save[i] != 0)
            save[j++] = save[i++];
        else
            save[j++] = 0;
    }
}

static char *my_strsplit(char *save)
{
    char *out;
    int len = 0;

    while (save[len] != 0 && save[len] != '\n')
        len++;
    out = malloc((len + 1) * sizeof(char));
    len = 0;
    while (save[len] != 0 && save[len] != '\n')
    {
        out[len] = save[len];
        len++;
    }
    out[len] = 0;
    my_remove_line(save);
    return (out);
}

char *get_next_line(const int fd)
{
    static char *save = NULL;
    char buffer[4097];
    int i;

    do {
        i = read(fd, buffer, 4096);
        if (i < 0)
            return (NULL);
        if (i == 0)
            break;
        buffer[i] = 0;
        save = my_strcat_dup(save, buffer);
        if (my_find(save, '\n') == 1)
            return (my_strsplit(save));
    }
    while (i > 0);
    if (save != NULL && save[0] != 0)
        return (my_strsplit(save));
    return (NULL);
}
