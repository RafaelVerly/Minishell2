#include "./minishell.h"


int quotes_out(char *cmd_ln, char quote)
{
    int i;
    
    i = 1;
    while(cmd_ln[i] != quote)
    {
        i++;
        if(cmd_ln[i] == '\0')
            return (0);
    }
    //printf("quotes_out_i: %d\n", i);
    return (i);
}

t_exec  *ft_exec_add(t_exec **stk, int pos_exec)
{
    t_exec    *new;
    t_exec    *last;

    new = malloc(sizeof(t_exec));
    if (!new)
        return (NULL);
    last = ft_get_last_stk(&*stk);
    new->prev = last; // isso quer dizer que consigo acessar o que estiver em last através de new
    new->pos_exec = pos_exec + 1;
    new->next = NULL;
    if (!*stk)
    {
        *stk = new;
        return (*stk);
    }
    last->next = new;
    return (new);
}


void    parse_qtt_exec(t_exec **exec, char *cmd_ln)
{
    int i;
    int quotes_in;

    i = 0;
    ft_exec_add(exec, -1);
    while(cmd_ln[i])
    {
        if(cmd_ln[i] == '\'' || cmd_ln[i] == '\"')
        {
            quotes_in = quotes_out(&cmd_ln[i], cmd_ln[i]);
            if(quotes_in == 0)
            {
                ft_putstr_fd("Error: quotes missing\n", 2);
                ft_stack_clear(exec);
                break ;
            }
            i += quotes_in;
        }
        if(cmd_ln[i] == '|')
            ft_exec_add(exec, i);
        i++;
    }
}

int     command_line_parse(char *cmd_ln)
{
    t_exec *exec;
    int exec_qtd;
    t_exec *aux;

    exec_qtd = 0;
    exec = NULL;
    
    parse_qtt_exec(&exec, cmd_ln);
    if(exec == NULL)
        return (1); 
    aux = exec;
    while(exec)
    {
        if(exec->next)
            exec->str_exec = ft_substr(cmd_ln, exec->pos_exec, exec->next->pos_exec - exec->pos_exec -1);
        else
            exec->str_exec = ft_substr(cmd_ln, exec->pos_exec, ft_strlen(cmd_ln) - exec->pos_exec);
        //printf("exec->str_exec: %s \n", exec->str_exec);
        //ft_args_add(&exec->args, &cmd_ln[exec->pos_exec]);
        dup_array(&exec);
        exec_qtd++; // só ver a quantidade de execuções criadas
        exec = exec->next;
    }
    exec = aux;
    execve_teste(&exec);
    
    ft_stack_clear(&aux);
    //printf("exec_qtd: %d\n", exec_qtd);
    return (0);
}




int main()
{
    char *ret;
    while(42)
    {
        ret = readline(">");
        command_line_parse(ret);
        free(ret);
        ret = NULL;
       // execve_teste();
    }
}