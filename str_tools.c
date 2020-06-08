/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** str_funct
*/

#include "minishell.h"

char *my_strstr2(char *str, char const *to_find)
{
    int i = 0;

    if (str == NULL || to_find == NULL)
        return (NULL);
    while (to_find[i] != 0)
        i++;
    while (*str != 0)
    {
        if (my_strncmp2(str, to_find, i) == 0)
            return (str);
        str++;
    }

    return NULL;
}

int my_strncmp2(char const *s1, char const *s2, int n)
{
    int i = 0;

    if (n <= 0)
        return (0);
    if ((s1[i] >= 'A' && s1[i] <= 'Z' && s2[i] >= 'A' && s2[i] <= 'Z') ||
    (s1[i] >= 'a' && s1[i] <= 'z' && s2[i] >= 'a' && s2[i] <= 'z')){
        while (s1[i] != 0 && s2[i] != 0 && s1[i] == s2[i] && i < n - 1)
            i++;
        return (s1[i] - s2[i]);
    }
    return (84);
}

char *clean_str(char *str, char c)
{
    int i = 0;
    int j = 0;
    char *tmp = malloc(sizeof(char) * my_strlen(str) + 1);

    if (str == NULL || tmp == NULL)
        return (NULL);
    while (str[i] != 0){
        if (str[i] == c && str[i + 1] == ' ')
            str[i + 1] = str[i];
        tmp[i] = str[i];
        i++;
    }
    tmp[i] = 0;
    return (tmp);
}

char *remove_jumpline(char *str)
{
    int i = 0;
    int len = my_strlen(str);

    for (i = 0; str[i] != '\0'; i++){
        if (str[i] == '\n'){
            str[i] = '\0';
            break;
        }
    }
    return (str);
}