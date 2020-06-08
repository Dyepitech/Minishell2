/*
** EPITECH PROJECT, 2020
** str_tools
** File description:
** str_tools2
*/

#include "minishell.h"

char *cat_path(char *path, char *args)
{
    char *buff = NULL;

    if (path != NULL || args != NULL){
        buff = strcatbis(&path, "/", 0);
        buff = strcatbis(&buff, args, 1);
        return (buff);
    }
    return (NULL);
}

char *transform_path(char *path, char *args)
{
    DIR *repo;
    char *finalpath = NULL;
    repo = opendir(path);

    if (args == NULL || path == NULL){
        return (NULL);
    }
    if (repo != NULL)
        finalpath = cat_path(path, args);
    closedir(repo);
    return (finalpath);
}

char *search_inenv(t_env *env, char *data)
{
    char *find = NULL;

    if (env == NULL){
        return (NULL);
    }
    while (env && data != NULL){
        if (my_strstr(env->env, data) != 0)
            find = env->env;
        if (env->next == NULL && find == NULL)
            return (NULL);

        env = env->next;
    }
    return (find);
}

int check_exist(t_env *list, char *str)
{

    if (list == NULL || str == NULL)
        exit(84);

    while (list != NULL){
        if (my_strstr2(list->env, str) != NULL){
            return 0;
        }
        list = list->next;
    }
    return (1);
}

void refresh_pwd(t_shell *mysh)
{
    char *tmp = NULL;

    if (search_inenv(mysh->envi, "PWD") != NULL){
        mysh->pwd->newpwd = search_pwd(mysh->envi, "PWD=");
        if (my_strcmp2(mysh->pwd->actual, mysh->pwd->newpwd) != 1)
            change_pwd(mysh);
    }
    if (search_inenv(mysh->envi, "OLDPWD") != NULL){
        mysh->pwd->newpwd = search_inenv(mysh->envi, "OLDPWD=");
        if (my_strcmp2(mysh->pwd->actual, mysh->pwd->newpwd) != 1)
            change_oldpwd(mysh);
    }
}
