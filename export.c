#include "../include/myshell.h"


void    ft_dup_envp (char **envp, t_envp *my_envp)
{
    int len;
    len = 0;

    while(envp[len] != NULL)
        len++;
    my_envp->envp = malloc((len + 1) * sizeof(char *));
    my_envp->envp[len] = NULL;
    len = 0;
    while(envp[len] != NULL)
    {
        my_envp->envp[len] = ft_strdup(envp[len]);
        len++;
    }    
    //printf("%s\n dentro da função env normal\n", envp[0]);
    //printf("%s\n dentro da função\n", my_envp->envp[0] );
}
void    remove_var(t_envp *my_envp, int pos)
{
    t_envp **aux;
    int len;
    int i;

    len = 0;
    i = 0;
    while(my_envp->envp[len] != NULL)
        len++;
    aux = malloc(len * sizeof(char *));
    aux[len] = NULL;
    len = 0;
    while(my_envp->envp[i] != NULL)
    {
        if(i != pos)
        {
            aux[len] = my_envp->envp[i];
            len++;
            i++;
        }
        else
            i++;
    }
    free(my_envp->envp);
    my_envp->envp = aux;
}

int     ft_unset(char *var_env, t_envp *my_envp)
{
    int pos;
    int i;
    
    i = 0;
    pos = 0;
    while(my_envp->envp[pos] == '=')
    {
        while(my_envp->envp[pos][i] == '=')
            i++;
        if(ft_strncmp(var_env, my_envp->envp[pos], i) == 0)
        {
            remove_var(my_envp, pos);
            return (0);
        }
        i = 0;
        pos++;
    }
    return (1);
}

int    ft_match(char **my_envp, char *var, t_match *match)
{
    int pos;
    int i;

    pos = 0;
    while (my_envp->envp[pos])
    {
        i = 0;
        while (my_envp->envp[pos][i] != '=')
            i++;
        if (ft_strncmp(var_env, my_envp->envp[pos], i) == 0)
        {   
            match->pos = pos;
            match->match = 1;
        }
        pos++;
    }
    match->match = 0;
}

void    copy_envp(char **new, char **prev, t_match match)
{
    int i;

    i = 0;

    while(prev[i] != NULL)
    {
        new[i] = ft_strdup(prev[i]);
        i++;
    }

}

int ft_add_var(char *var_env, t_envp *my_envp, t_match match)
{
    char **aux;
    int len;
    int i;

    len = 0;
    i = 0;
    if(!match.match)
    {
        len++;
        while(my_envp->envp[len] != NULL)
            len++;
        aux = malloc((len + 1) * sizeof(char *));
        aux[len + 1] = NULL;
        aux[len] = ft_strdup(var_env);
        copy_envp(aux, my_envp->envp, match); // aqui tenho que saber se aux vai perder a sua memória quando acabar a função 
    }
    

    // match precisa retornar a posição pra só atualizar o valor da variável quando ela existir 
    free(my_envp->envp);
    my_envp->envp = aux;
    len = 0;
}

int     ft_export(char *var_env, t_envp *my_envp)
{
    t_match match;

    match = malloc(sizeof(t_match));
    ft_match(my_envp->envp, var_env, &match);
    ft_add_var(var_env, my_envp->envp, match);
    return (0);
}

int main(int argc, char **argv, char **envp)
{
    int i;
    (void)argv;
    t_envp my_envp;

    i = 0;
    if(argc != 1)
        return (1);
    ft_dup_envp(envp, &my_envp);
    //printf("%s\n fora da função",my_envp.envp[i] );
    //aqui eu suponho que a string já foi tratada
    ft_export("VASCO=GAMA", &my_envp);
    while(my_envp.envp[i] != NULL)
    {
        printf("%s\n", my_envp.envp[i]);
        i++;
    }
    ft_unset("VASCO", &my_envp);
    return (0);
}