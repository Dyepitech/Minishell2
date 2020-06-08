/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** environment
*/

#include "minishell.h"

int alpha_numerr(char *str)
{
    int i = 0;
    int j = 0;

    for (i = 0; str[i] != '\0'; i++){
        if (str[i] == '=')
            j++;
        if (i == 0 && (str[i] >= '0' && str[i] <= '9')){
            write(2, "setenv: Variable name must", 27);
            write(2, " begin with a letter.\n", 23);
            return (1);
        }
        else if ((str[i] >= 33 && str[i] <= 47 ||
        (str[i] >= 58 && str[i] <= 60) || (str[i] >= 62 && str[i] <= 63))
        && i > 0 || j > 1){
            write(2, "setenv: Variable name must", 26);
            write(2, " contain alphanumeric characters.\n", 35);
            return (1);
        }
    }
    return (0);
}

void setenv_twoarg(t_shell *mysh, int i)
{
    char *temp = "=";
    char *tmp = NULL;

    temp = verif_setenv(mysh, temp, i);
    while (mysh->envi != NULL && mysh->args[i + 2] != NULL &&
    alpha_numerr(mysh->args[i + 1]) == 0){
        tmp = search_inenv(mysh->envi, temp);
        if (search_inenv(mysh->envi, temp) == NULL){
            mysh->envi = elem_toend(mysh->envi,
                                    strcatbis(&temp, mysh->args[i + 2], 0));
            return;
        }
        else if (search_inenv(mysh->envi, temp) != NULL){
            if (my_strstr2(mysh->envi->env, temp) != NULL &&
            check_to_equal(tmp, temp) == 0){
                mysh->envi->env = my_strcat(temp, mysh->args[i + 2]);
                return;
            }
        }
        mysh->envi = mysh->envi->next;
    }
}

void cmd_setenv(t_shell *mysh, int i)
{
    char *temp = "=";
    char *tmp = NULL;

    if (mysh->args[i + 2] == NULL)
        temp = my_strcat(mysh->args[i + 1], temp);
    while (mysh->envi != NULL && mysh->args[i + 2] == NULL &&
    alpha_numerr(mysh->args[i + 1]) == 0){
        tmp = search_inenv(mysh->envi, temp);
        if (search_inenv(mysh->envi, temp) == NULL){
            mysh->envi = elem_toend(mysh->envi, temp);
            return;
        }
        else if (search_inenv(mysh->envi, temp) != NULL){
            if (my_strstr2(mysh->envi->env, temp) != NULL &&
            check_to_equal(tmp, temp) == 0){
                mysh->envi->env = temp;
                return;
            }
        }
        mysh->envi = mysh->envi->next;
    }
}

void cmd_unsetenv(t_shell *mysh, int i)
{
    char *temp = "=";
    int pos = 0;
    t_env *list = mysh->envi;
    t_env *tmp = mysh->envi->next;
    temp = my_strcat(mysh->args[i + 1], temp);

    if (mysh->envi != NULL){
        while (tmp != NULL){
            if (my_strstr(tmp->env, temp) != NULL){
                list->next = tmp->next;
                free(tmp);
                return;
            }
        pos++;
        list = tmp;
        tmp = tmp->next;
        }
    }
}

void my_envcmd(t_shell *mysh, int i)
{
    if ((my_strcmp("env", mysh->args[i]) == 0 && mysh->envi != NULL) ||
    (my_strcmp("setenv", mysh->args[i]) == 0 && mysh->args[i + 1] == NULL))
        show_list(mysh->envi);
    if (my_strcmp("setenv", mysh->args[i]) == 0 && mysh->args[i + 2] != NULL &&
    mysh->args[i + 3] != NULL)
        write(2, "setenv: Too many arguments.\n", 30);
    if (my_strcmp("setenv", mysh->args[i]) == 0 && mysh->args[i + 1] != NULL){
        if (mysh->args[i + 2] == NULL);
            cmd_setenv(mysh, i);
        if (mysh->args[i + 2] != NULL)
            setenv_twoarg(mysh, i);
    }
    if (my_strcmp("unsetenv", mysh->args[i]) == 0){
        cmd_unsetenv(mysh, i);
    }
}