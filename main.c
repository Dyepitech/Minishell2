/*
** EPITECH PROJECT, 2020
** main
** File description:
** main
*/

#include "minishell.h"

void setup_shell(t_shell *mysh, t_env *envi, char **env)
{
    remove_jumpline(mysh->buffer);
    mysh->clean = clean_str(mysh->buffer, ';');
    mysh->opt = my_strtok(mysh->clean, ";");
    mysh->args = my_str_to_word_array(mysh->clean);
    mysh->env = env;
    mysh->envi = envi;
    mysh->pwd = init_pwdstruct(mysh);
    mysh->redi = init_redi(mysh);
}

void loop_args(char **env, t_shell *mysh)
{
    my_getpath(env, mysh);
}

t_shell *init_struct(void)
{
    t_shell *mysh = malloc(sizeof(t_shell) * 1);

    mysh->args = NULL;
    mysh->path = NULL;
    mysh->buffer = NULL;
    mysh->cmd = NULL;
    mysh->opt = NULL;
    mysh->env = NULL;
    mysh->clean = NULL;
    mysh->len = 0;
    mysh->exit = 0;
    mysh->envi = NULL;
    mysh->pwd = NULL;
    mysh->redi = NULL;

    return (mysh);
}

void shell_loop(char **argv, char **env)
{
    t_shell *mysh;
    mysh = init_struct();
    t_env *envi = env_tolist(env);

    while (1){
        my_putstr("$> ");
        if (getline(&mysh->buffer, &mysh->len, stdin) == -1){
            my_printf("exit\n");
            exit(mysh->exit);
        }
        setup_shell(mysh, envi, env);
        loop_args(mysh->env, mysh);
        my_cmd(mysh);
        free(mysh->args);
        free(mysh->clean);
    }
}

int main(int argc, char **argv, char **env)
{
    shell_loop(argv, env);
}