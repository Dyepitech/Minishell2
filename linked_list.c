/*
** EPITECH PROJECT, 2020
** linked
** File description:
** linked_list
*/

#include "minishell.h"

t_env *remove_elem2(t_env *tmp, t_env *list, char *str, t_env *save)
{
    while (tmp != NULL){
        if (tmp->env == str){
            save->next = tmp->next;
            free(tmp);
            return (list);
        }
        save = tmp;
        tmp = tmp->next;
    }
}

t_env *remove_elem(t_env *list, char *str)
{
    t_env *tmp;
    t_env *save;

    if (list->next == NULL || list == NULL)
        return (list);
    save = list;
    if (save->env == str){
        list = save->next;
        free(save);
        return (list);
    }
    tmp = save->next;
    remove_elem2(tmp, list, str, save);
    return (list);
}

t_env *env_tolist(char **env)
{
    t_env *list = NULL;
    t_env *new = NULL;
    int i = 0;

    while (env != NULL && env[i] != NULL){
        new = malloc(sizeof(*new));
        if (new == NULL)
            return (NULL);
        new->env = env[i];
        new->next = list;
        list = new;
        i++;
    }
    return (list);
}

void show_list(t_env *env)
{
    int i = 0;

    while (env != NULL){
        my_printf("%s\n", env->env);
        env = env->next;
    }
}

t_env *elem_toend(t_env *list, char *newenv)
{
    t_shell *mysh;
    t_env *new;
    t_env *tmp;

    new = malloc(sizeof(*new));
    if (list == NULL || new == NULL)
        exit(84);
    new->next = NULL;
    if (list->next != NULL){
        tmp = list->next;
        new->env = newenv;
        while (tmp->next != NULL)
            tmp = tmp->next;
        tmp->next = new;
    }
    else {
        new->env = newenv;
        list->next = new;
    }
    return (list);
}