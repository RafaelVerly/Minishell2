#include "./minishell.h"

void    size_exec(t_exec **exec)
{
    int i;
    int size;

    i = 0;
    size = 0;
    while((*exec)->str_exec[i])
    {
        while((*exec)->str_exec[i] == ' ')
            i++;
        if(!(*exec)->str_exec[i])
            break ;
        while((*exec)->str_exec[i] != ' ' && (*exec)->str_exec[i])
        {
            if((*exec)->str_exec[i] == '\'' || (*exec)->str_exec[i] == '\"')
                i += quotes_out(&(*exec)->str_exec[i], (*exec)->str_exec[i]);
            i++;
        }
        size++;
    }
    printf("size: %d\n", size);
    (*exec)->arr_arg = malloc((size + 1) * sizeof(char *) );
    (*exec)->arr_arg[size] = NULL;
}

void    dup_array(t_exec **exec)
{
    int i;
    int start;
    int j;

    j = 0;
    start = 0;
    i = 0;
    size_exec(exec);
    while((*exec)->str_exec[i])
    {
        while((*exec)->str_exec[i] == ' ')
            i++;
        if(!(*exec)->str_exec[i]) // fim da string não fazer mais nenhuma sub
            break ;
        start = i;
        while((*exec)->str_exec[i] != ' ' && (*exec)->str_exec[i])
        {
            if((*exec)->str_exec[i] == '\'' || (*exec)->str_exec[i] == '\"')
                i += quotes_out(&(*exec)->str_exec[i], (*exec)->str_exec[i]);
            i++;
        }
        (*exec)->arr_arg[j] = ft_substr((*exec)->str_exec, start, i - start);
        j++;
    }
    
    j = 0;
    while((*exec)->arr_arg[j])
    {
        printf("exec->arr_arg[%d]: %s\n", j, (*exec)->arr_arg[j]);
        j++;
    }
    
}