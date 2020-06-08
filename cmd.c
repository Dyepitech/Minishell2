/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** cmd
*/

#include "minishell.h"

void prev_directory(t_shell *mysh)
{
    char *pwd = NULL;
    char *endpwd;
    pwd = get_oldpwd(mysh);

    if (pwd == NULL){
        return;
    }
    else if (pwd != NULL){
        chdir(pwd);
        mysh->pwd->actual = transform_to_pwd(mysh);
        refresh_pwd(mysh);
    }
}

char *my_cd(t_shell *mysh)
{
    int j = 0;
    int path = 0;
    char *str = NULL;
    DIR *repo;

    for (j = 0; mysh->env[j] != NULL; j++){
        if (mysh->env[j][0] == 'H' && mysh->env[j][1] == 'O' &&
        mysh->env[j][2] == 'M' && mysh->env[j][3] == 'E') {
            str = mysh->env[j] + 5;
        }
    }
    if (str != NULL){
        repo = opendir(str);
        chdir(str);
    }
    closedir(repo);
    return (str);
}

void cmd_cd(t_shell *mysh, int i)
{
    check_cd_access(mysh, mysh->args[i + 1]);
    if (mysh->args[i + 1] == NULL || mysh->args[i + 1] == "~"){
        my_cd(mysh);
        goto_cd(mysh);
        refresh_pwd(mysh);
    }
    if (my_strcmp2(mysh->args[i], "cd") == 1 &&
    my_strcmp2(mysh->args[i + 1], "-") == 1)
        prev_directory(mysh);
    if (mysh->args[i + 1] != NULL && my_strcmp2(mysh->args[i + 1], "-") != 1){
        if (chdir(mysh->args[i + 1]) != -1){
            goto_cd(mysh);
            chdir(mysh->args[i + 1]);
            refresh_pwd(mysh);
        }
        else if (chdir(mysh->args[i + 1]) == -1 &&
        my_strcmp2(mysh->args[i + 1], "-") != 1)
            mysh->exit = 1;
    }
}

void exit_shell(t_shell *mysh, int i)
{
    int exit_status;

    if (mysh->args[i + 1] == NULL){
        my_printf("exit\n");
        exit(0);
    }
    if (mysh->args[i + 1] != NULL && mysh->args[i + 2] == NULL){
        if (my_str_isnum(mysh->args[i + 1])){
            my_printf("exit\n");
            exit_status = my_getnbr(mysh->args[i + 1]);
        }
        if (my_strcmp2(mysh->args[i], "exit")){
                exit(exit_status);
        }
    }
    else {
        write(2, "exit: Expression Syntax.\n", 26);
        mysh->exit = 1;
    }
}

void my_cmd(t_shell *mysh)
{
    int i = 0;

    for (i = 0; mysh->args[i] != NULL; i++){
        if (my_strcmp("exit", mysh->args[i]) == 0)
            exit_shell(mysh, i);
        if (my_strcmp("cd", mysh->args[i]) == 0)
            cmd_cd(mysh, i);
        my_envcmd(mysh, i);
    }
}