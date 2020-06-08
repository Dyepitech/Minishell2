/*
** EPITECH PROJECT, 2020
** pwd
** File description:
** pwd
*/

#include "minishell.h"

char *get_pwd(t_shell *mysh)
{
    char *path = NULL;
    char *finalpath = NULL;
    int i = 0;
    int j = 0;

    path = search_pwd(mysh->envi, "PWD");
    if (path == NULL){
        return (NULL);
    }
    finalpath = malloc(sizeof(char) * my_strlen(path));
    if (finalpath == NULL)
        return (NULL);
    for (i = 0; path[i] != '='; i++);
    for (i = i + 1, j = 0; path[i] != '\0'; i++, j++)
        finalpath[j] = path[i];
    finalpath[j] = '\0';

    return (finalpath);
}

char *get_currpwd(void)
{
    char *pwd = NULL;
    char buffer[255];

    if (getcwd(buffer, 255) == NULL)
        return (NULL);
    pwd = malloc(sizeof(char) * my_strlen(buffer) + 1);
    if (pwd != NULL){
        my_strcpy(pwd, buffer);
        return (pwd);
    }
    free (pwd);
    return (NULL);
}

char *get_oldpwd(t_shell *mysh)
{
    char *path;
    char *finalpath;
    int i = 0;
    int j = 0;

    path = search_oldpwd(mysh->envi, "OLDPWD");

    if (path == NULL){
        return (NULL);
    }
    finalpath = malloc(sizeof(char) * my_strlen(path));
    if (finalpath == NULL)
        return (NULL);
    for (i = 0; path[i] != '='; i++);
    for (i = i + 1, j = 0; path[i] != '\0'; i++, j++)
        finalpath[j] = path[i];
    finalpath[j] = '\0';

    return (finalpath);
}

void change_oldpwd(t_shell *mysh)
{
    t_env *list = mysh->envi;
    char *curpwd = mysh->pwd->actual;
    char *tmp = "OLDPWD=";
    int pos = 0;

    if (check_exist(list, mysh->pwd->pfx_olpwd) == 0 && curpwd != NULL){
        while (list != NULL){
            if (my_strstr2(list->env, mysh->pwd->pfx_olpwd) != 0 &&
            curpwd != NULL){
                list->env = mysh->pwd->actual;
                return;
            }
        pos++;
        list = list->next;
        }
    }
}

void change_pwd(t_shell *mysh)
{
    t_env *list = mysh->envi;
    char *curpwd = get_currpwd();
    char *tmp = "PWD=";
    int pos = 0;
    char *finalpath = strcatbis(&tmp, curpwd, 0);

    if (check_exist(list, tmp) == 0 && finalpath != NULL){
        while (list != NULL){
            if (my_strstr2(list->env, tmp) != 0 && finalpath != NULL){
                list->env = finalpath;
                return;
            }
        pos++;
        list = list->next;
        }
    }
}