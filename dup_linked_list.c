#include "./minishell.h"

void    ft_stack_clear(t_exec **stk)
{
    t_exec    *temp;

    while (*stk)
    {
        temp = (*stk)->next;
        free(*stk);
        free((*stk)->arr_arg);
        *stk = NULL;
        (*stk) = temp;
    }
}

t_exec    *ft_get_last_stk(t_exec **stk)
{
    t_exec    *temp;
    t_exec    *last;

    if (!*stk)
        return (NULL);
    if (!(*stk)->next)
        return (*stk);
    temp = *stk;
    while ((*stk)->next)
        *stk = (*stk)->next;
    last = *stk;
    *stk = temp;
    return (last);
}

t_args    *ft_get_last_args(t_args **stk)
{
    t_args    *temp;
    t_args    *last;

    if (!*stk)
        return (NULL);
    if (!(*stk)->next)
        return (*stk);
    temp = *stk;
    while ((*stk)->next)
        *stk = (*stk)->next;
    last = *stk;
    *stk = temp;
    return (last);
}
/*
t_exec  *ft_exec_add(t_exec **stk, int pos_exec)
{
    t_exec    *new;
    t_exec    *last;

    new = malloc(sizeof(t_exec));
    if (!new)
        return (NULL);
    last = ft_get_last_stk(&*stk);
    new->prev = last;
    new->pos_exec = pos_exec;
    new->next = NULL;
    if (!*stk)
    {
        *stk = new;
        return (*stk);
    }
    last->next = new;
    return (new);
}
*/
int    add_str(t_args **args, char *new_str)
{
    t_args *new;
    t_args *last;

    new = malloc(sizeof(t_exec));
    if (!new)
        return (1);
    last = ft_get_last_args(&*args);
    new->prev = last;
    new->str = new_str;
    new->next = NULL;
    printf("args: %s\n\n", new->str);
    if (!*args)
    {
        *args = new;
        return (0);
    }
    last->next = new;
    return (0);

}

/*
int ft_parse_args(t_exec **exec, char *line)
{
    int i;
    int end;

    i = 0;
    end = 0;
    if((*exec)->next)
        end = (*exec)->next->pos_exec;
    while()
    {
        
    }
    
}
*/

void  ft_args_add(t_args **args, char *line)
{
    char    *str;
    int     i;
    int     start;

    i = 0;
    start = 0;
    while(line[i])
    {
        while(line[i++] == ' ')
            start = i;
        while(line[i] != ' ' && line[i] != '\0')
        {    
            if(line[i] == '|')
                break ;
            if(line[i] == '\'' || line[i] == '\"')
                i = i + quotes_out(&line[i], line[i]);
            printf("i: %d\n", i);
            i++;
        }
        printf("start: %d\ni: %d\n", start, i);
        str = ft_substr(line, start, i - start);
        add_str(args, str);
        free(str);
    }
}


/*
void	ft_add_args(t_args **element, char *str)
{
	t_args	*no;
	t_args	*temp;

	no = malloc(sizeof(t_args));
	no->next = NULL;
	no->str = str;
	if (!(*element))
		*element = no;
	else
	{
		temp = *element;
		while (temp->next)
		    temp = temp->next;
		temp->next = no;
	}
}

void    add_exec(t_exec **list)
{
    t_exec *aux;
    t_exec *no;

    no = malloc(sizeof(t_exec));
    no->next = NULL;
    if(!(*list))
        *list = no;
    else
    {
        aux = *list;
        while(aux->next)
            aux = aux->next;
        aux->next = no;
    }
}


void    args_exec(t_exec **exec, char *cmd_ln)
{
    // até esse ponto tenho a quantidade de nós de execução considerando apenas
    // os delimitadores com nós próprios
    // ex: todas as palavras até um delimitador é apenas um nó  
    // o delimitador é um nó que contém apenas ele mesmo
    int i;
    int start;
    //char *arg;

    i = 0;
    while(cmd_ln[i])
    {
        start = i;
        while(cmd_ln[i] == '\'' || cmd_ln[i] == '\"')
            i += quotes_out(&cmd_ln[i], cmd_ln[i]);
        while(cmd_ln[i] != ' ' && cmd_ln[i])
        {
            i++;
            
        }
        if(cmd_ln[i] == ' ')
            ft_add_args(&(*exec)->args, ft_substr(&cmd_ln[start], 0, i - start));
    }
    printf("exec->args: %s\n", (*exec)->args->str);
}
*/