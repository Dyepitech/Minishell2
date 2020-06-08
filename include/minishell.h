/*
** EPITECH PROJECT, 2020
** minishell1
** File description:
** minishell1
*/


#ifndef MINISHELL1_H
#define MINISHELL1_H
#include <stdlib.h>
#include <unistd.h>
#include "minishell.h"
#include "my.h"
#include <stdbool.h>
#include <fcntl.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/wait.h>

typedef struct s_redi
{
    char *bf_redi;
    char *af_redi;
    int   nb_redi;
    char  redi_left;
    char  redi_right;

} t_redi;

typedef struct s_pwd
{
    char *actual;
    char *oldpwd;
    char *newpwd;
    char *pfx_pwd;
    char *pfx_olpwd;
} t_pwd;

typedef struct s_env
{
    char *env;
    struct s_env *next;
} t_env;

typedef struct shell {
    char **cmd;
    char **path;
    char **args;
    char **env;
    size_t len;
    char *buffer;
    char **opt;
    char *clean;
    int   exit;
    t_env *envi;
    t_pwd *pwd;
    t_redi *redi;
} t_shell;

void loop_args(char **env, t_shell *mysh); // a mettre dans le main
void shell_loop(char **argv, char **env);
int main(int argc, char **argv, char **env);

// STR TOOLS
char *cat_path(char *path, char *args);
char *transform_path(char *path, char *args);
char *clean_str(char *str, char c);
char *remove_jumpline(char *str);
int my_strncmp2(char const *s1, char const *s2, int n);
char *my_strstr2(char *str, char const *to_find);

//  Init Struct
t_shell *init_struct(void);
t_pwd *init_pwdstruct(t_shell *mysh);
t_redi *init_redi(t_shell *mysh);

// PATH ACTION
int browse_args(t_shell *mysh, int i, int j, char *finalpath);
void browse_path(t_shell *mysh, char **env);
t_shell *my_getpath(char **env, t_shell *mysh);
int fork_path(char *path, char **args, char **env);
int check_cmd(char *str);
int new_opendir(t_shell *mysh, char *args);

// STRTOK
char **my_strtok(char *str, char *delim);
int	my_count_word(char *str, char *delim);
int	my_is_instr(char c, char *str);

// STRCATBIS
char *strcatbis(char **str1, char *str2, int freed);


// COMMAND
void my_cmd(t_shell *mysh);
void exit_shell(t_shell *mysh, int i);
void cmd_cd(t_shell *mysh, int i);
void goto_cd(t_shell *mysh);
void prev_directory(t_shell *mysh);
int check_to_equal(char *str, char *str2);

// PWD
char *get_oldpwd(t_shell *mysh);
char *get_pwd(t_shell *mysh);
char *get_currpwd(void);
void change_pwd(t_shell *mysh);
char *search_path(t_env *env, char *data);

//PWD ACTION

// Linked List
int check_exist(t_env *list, char *str);
t_env *remove_element(t_env *list, char *str);
t_env *env_tolist(char **env);
void show_list(t_env *env);
t_env *elem_toend(t_env *list, char *newenv);
t_env *remove_elem(t_env *list, char *str);
char *search_env(t_env *env, char *data);

// ENVIRONNEMENT
void my_envcmd(t_shell *mysh, int i);
char *search_inenv(t_env *env, char *data);
void cmd_setenv(t_shell *mysh, int i);
void setenv_twoarg(t_shell *mysh, int i);
void cmd_unsetenv(t_shell *mysh, int i);
int alpha_numerr(char *str);
char *search_pwd(t_env *env, char *data);

// A VOIR
char *transform_to_pwd(t_shell *mysh);
void change_oldpwd(t_shell *mysh);
char *search_oldpwd(t_env *env, char *data);
void refresh_pwd(t_shell *mysh);
char *verif_setenv(t_shell *mysh, char *str, int i);

// REDIRECTIONS
void redirection(t_shell *mysh, int i);
void clear(t_env **mysh);
#endif