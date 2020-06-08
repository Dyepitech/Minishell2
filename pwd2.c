/*
** EPITECH PROJECT, 2020
** pwd
** File description:
** pwd2
*/

#include "minishell.h"

int check_path(char *find)
{
    int i = 0;

    for (i = 0; find[i] != '='; i++);
    if (i == 4)
        return (0);
    return (1);
}

int check_oldpwd(char *find)
{
    int i = 0;

    for (i = 0; find[i] != '='; i++);
    if (i == 6)
        return (0);
    if (i == 3)
        return (-1);
    return (1);
}

char *search_pwd(t_env *env, char *data)
{
    char *find = NULL;

    if (env == NULL || data == NULL){
        return (NULL);
    }
    while (env && data != NULL){
        if (my_strstr(env->env, data) != 0 && check_oldpwd(env->env) != 0)
            find = env->env;
        if (env->next == NULL && find == NULL)
            return (NULL);

        env = env->next;
    }
    return (find);
}

char *search_path(t_env *env, char *data)
{
    char *find = NULL;

    if (env == NULL || data == NULL){
        return (NULL);
    }
    while (env && data != NULL){
        if (my_strstr(env->env, data) != 0 && check_path(env->env) == 0)
            find = env->env;
        if (env->next == NULL && find == NULL)
            return (NULL);

        env = env->next;
    }
    return (find);
}

char *search_oldpwd(t_env *env, char *data)
{
    char *find = NULL;

    if (env == NULL || data == NULL){
        return (NULL);
    }
    while (env && data != NULL){
        if (my_strstr(env->env, data) != 0 && check_oldpwd(env->env) == 0)
            find = env->env;
        if (env->next == NULL && find == NULL)
            return (NULL);

        env = env->next;
    }
    return (find);
}