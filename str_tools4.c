/*
** EPITECH PROJECT, 2020
** str_tools
** File description:
** str_tools4
*/

#include "minishell.h"

char *verif_setenv(t_shell *mysh, char *str, int i)
{
    if (mysh->args[i + 2] != NULL){
        str = strcatbis(&mysh->args[i + 1], str, 0);
        return (str);
    }
    return (NULL);
}

int new_opendir(t_shell *mysh, char *args)
{
    struct dirent *dirent;
    char *pwd = get_pwd(mysh);
    DIR *repo = opendir(pwd);
    char *buff = transform_path(pwd, args);

    if ((args) == NULL)
        return (-1);
    if (repo != NULL && args != NULL) {
        if (access(buff, X_OK) == -1 && access(buff, F_OK) != -1){
            my_printf("%s: Permission denied.\n", args);
            free(pwd);
            return (-1);
        }
    }
    free(buff);
    closedir(repo);
}

int check_cmd(char *str)
{
    int i = 0;

    if (str != NULL){
        for (i = 0; str[i] != '\0'; i++)
            if (i == 0 && str[i] == '.' && str[i + 1] == '/')
                return (1);
        return (0);
    }
}

int check_to_equal(char *str, char *str2)
{
    int i = 0;
    int j = 0;

    for (i = 0; str[i] != '='; i++);
    for (j = 0; str[j] != '='; j++);

    if (i != j)
        return (84);
    return (0);
}

char *search_env(t_env *env, char *data)
{
    char *find = NULL;

    if (env == NULL){
        return (NULL);
    }
    while (env && data != NULL){
        if (check_to_equal(env->env, data) == 0)
            find = env->env;
        if (env->next == NULL && find == NULL)
            return (NULL);

        env = env->next;
    }
    return (find);
}