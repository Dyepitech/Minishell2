/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** path_actions
*/

#include "minishell.h"

int fork_path(char *path, char **args, char **env)
{
    pid_t pid;
    int stat = 0;

    pid = fork();

    if (pid == 0)
        execve(path, args, env);
    else
        wait(&pid);
    return 0;
}

int browse_args(t_shell *mysh, int i, int j, char *finalpath)
{
    int k = 0;
    char **arguments = NULL;
    int ret = 0;
    int count = 0;

    for (k = 0; mysh->args[k] != NULL; k++){
        arguments = my_str_to_word_array(mysh->opt[i]);
        finalpath = transform_path(mysh->path[j], arguments[0]);
        if (ret == 0 && finalpath != NULL &&
        access(finalpath, X_OK) != -1 &&
        (my_strcmp2("env", arguments[k]) != 1) &&
        (my_strcmp2("cd", arguments[k]) != 1)){
            fork_path(finalpath, &arguments[k], mysh->env);
            ret = 1;
        }
    }
    return (ret);
}

void browse_path(t_shell *mysh, char **env)
{
    int i = 0;
    int j = 0;
    char *finalpath = NULL;
    int breaker = 0;

    for (i = 0; mysh->opt[i] != NULL; i++){
        for (j = 0; breaker == 0 && mysh->path[j] != NULL; j++){
            breaker = browse_args(mysh, i, j, finalpath);
            finalpath = NULL;
        }
        breaker = 0;
    }
}

t_shell *my_getpath(char **env, t_shell *mysh)
{
    if (mysh->envi != NULL)
        mysh->path = my_strtok(search_path(mysh->envi, "PATH"), ": =");
    browse_path(mysh, env);
    return (mysh);
}
