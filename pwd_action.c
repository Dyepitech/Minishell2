/*
** EPITECH PROJECT, 2020
** pwd_action
** File description:
** pwd_action
*/

#include "minishell.h"

t_pwd *init_pwdstruct(t_shell *mysh)
{
    mysh->pwd = malloc(sizeof(t_pwd) * 1);
    if (mysh->pwd == NULL)
        return (NULL);
    mysh->pwd->actual = NULL;
    mysh->pwd->newpwd = NULL;
    mysh->pwd->oldpwd = NULL;
    mysh->pwd->pfx_olpwd = "OLDPWD=";
    mysh->pwd->pfx_pwd = "PWD=";
}

char *transform_to_pwd(t_shell *mysh)
{
    mysh->pwd->actual = get_pwd(mysh);

    if (mysh->pwd->actual != NULL){
        mysh->pwd->actual = strcatbis(&mysh->pwd->pfx_olpwd,
                                            mysh->pwd->actual, 0);
        return (mysh->pwd->actual);
    }
}

void goto_cd(t_shell *mysh)
{
    mysh->pwd->actual = transform_to_pwd(mysh);
    mysh->pwd->oldpwd = get_oldpwd(mysh);

    if (search_inenv(mysh->envi, mysh->pwd->pfx_olpwd) != NULL)
        remove_elem(mysh->envi, strcatbis(&mysh->pwd->pfx_olpwd,
                                                mysh->pwd->oldpwd, 0));
    else
        elem_toend(mysh->envi, mysh->pwd->actual);
}

int check_cd_access(t_shell *mysh, char *dir)
{
}
