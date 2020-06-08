/*
** EPITECH PROJECT, 2020
** redirection
** File description:
** redirect
*/

#include "minishell.h"

void clear(t_env **mysh)
{
    t_env *tmp;

    while (*mysh){
        tmp = (*mysh)->next;
        free(*mysh);
        *mysh = tmp;
    }
}

t_redi *init_redi(t_shell *mysh)
{
    mysh->redi = malloc(sizeof(t_redi) * 1);
    if (mysh->redi == NULL)
        return (NULL);

    mysh->redi->af_redi = NULL;
    mysh->redi->bf_redi = NULL;
    mysh->redi->nb_redi = 0;
    mysh->redi->redi_right = '>';
    mysh->redi->redi_left = '<';

    return (mysh->redi);
}

void redirection(t_shell *mysh, int i)
{
    static int count = 0;

    if (my_strcmp(">", mysh->args[i]) == 0 && mysh->args[i - 1] != NULL &&
    mysh->args[i + 1] != NULL)
        count++;
    mysh->redi->nb_redi = count;
    if (mysh->args[i + 1] == NULL){
        count = 0;
    }
}