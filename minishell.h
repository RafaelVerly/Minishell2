#ifndef minishell_h
 #define minishell_h


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <readline/readline.h>
#include "./libft/libft.h"

typedef struct s_args
{
    char *str;
    struct s_args *prev;
    struct s_args *next;
}   t_args;

typedef struct s_exec
{
    t_args *args;
    char    **arr_arg;
    char    *str_exec;
    int     type;
    struct s_exec *prev;
    struct s_exec *next;
    int pos_exec;
    
} t_exec;

typedef struct s_size_input
{
    int size;
    int quotes_qtd;
}   t_size_input ;

typedef struct s_token
{
    char *str;
    int size;
    int quotes;
    struct s_token *next;
    
} t_token;

char    *quote_close(char *ret);
t_exec  *ft_get_last_stk(t_exec **stk);
t_exec  *ft_exec_add(t_exec **stk, int pos_exec);
void    ft_stack_clear(t_exec **stk);
void    execve_teste();
void    ft_args_add(t_args **args, char *line);
int     quotes_out(char *cmd_ln, char quote);
void    dup_array(t_exec **exec);
void    execve_teste(t_exec **exec);


#endif