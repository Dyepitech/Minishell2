/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** my_strtok
*/

#include "minishell.h"

int	char_in_str(char c, char *str)
{
    int	i = 0;

    if (c == 0)
        return (0);
    while (str[i]){
        if (str[i] == c)
            return (0);
        i++;
    }
    return (-1);
}

int	my_count_word(char *str, char *c)
{
    int	i = 0;
    int	cnt = 0;

    while (str[i]){
        if (char_in_str(str[i], c) == -1
        && char_in_str(str[i + 1], c) == 0)
            cnt++;
        i++;
    }
    return (cnt);
}

char **my_strtok(char *str, char *c)
{
    int	i = 0;
    int	j = 0;
    int	k = 0;
    char **tab;

    tab = malloc((my_count_word(str, c) + 1) * sizeof(*tab));
    while (str[i] && tab != NULL){
        if (char_in_str(str[i], c) == -1)
            k++;
        if (char_in_str(str[i], c) == -1 && char_in_str(str[i + 1], c) == 0){
            tab[j] = malloc((k + 1) * sizeof(**tab));
            tab[j][0] = 0;
            tab[j] = my_strncat(tab[j], &str[i - (k - 1)], k);
            k = 0;
            j++;
        }
        i++;
    }
    tab[j] = NULL;
    return (tab);
}