#include "./minishell.h"

int     fd_change(t_exec **exec, int fd[])
{
    if((*exec)->next)
        dup2(fd[1], 1);
    if((*exec)->prev)
        dup2(fd[0], 0);

    return (0);
}


void    ft_change_fds(t_exec **exec)
{
    if((*exec)->prev && !(*exec)->next)
    {
        dup2((*exec)->prev->fd[0], 0);
        close((*exec)->prev->fd[0]);
        close((*exec)->prev->fd[1]);
    }
    if((*exec)->next && !(*exec)->prev)
    {                               
        dup2((*exec)->fd[1], 1);
        close((*exec)->fd[0]);
        close((*exec)->fd[1]);
        printf("pos_exec: %d\n", (*exec)->pos_exec);
    }
    /*
    if((*exec)->next && (*exec)->prev)
    {
        dup2((*exec)->prev->fd[0], 0);
        dup2((*exec)->fd[1], 1);
        close((*exec)->fd[0]);
        close((*exec)->fd[1]);
    }
    */
}

void    execve_teste(t_exec **exec)
{
    char *pt_str = "/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin";
    char **paths;
    //char *path_cmd;
    char *env[1];
    int id;
    t_exec *aux;
    
    paths = ft_split(pt_str, ':');
    //pipe(fd);
    aux = *exec;
    while(*exec)
    {   
        id = fork();
        if(id == 0)
        {
            *exec = aux;
            if((*exec)->next)
                pipe((*exec)->fd);
            if((*exec)->next || (*exec)->prev)
                ft_change_fds(exec);    
        }
        if(id != 0)
            aux = (*exec)->next;
        else
            break ;
    }
    printf("id: %d\n", id);
    if(id == 0)
    {
        (*exec)->cmd = ft_strjoin("/", (*exec)->arr_arg[0]);
        (*exec)->i = 0;
        printf("cmd: %s\n\n", (*exec)->cmd);
        while(paths[(*exec)->i] != NULL)
        {
            free((*exec)->arr_arg[0]);
            (*exec)->arr_arg[0] = ft_strjoin(paths[(*exec)->i], (*exec)->cmd);
            printf("%s\n", (*exec)->arr_arg[0]);
            env[0] = NULL;
            //printf("paths: %s\n", (*exec)->arr_arg[0]);
            if(id == 0)
                execve((*exec)->arr_arg[0], (*exec)->arr_arg, env);
            (*exec)->i++;
            //free((*exec)->arr_arg[0]);
        }
    }
    //free(path_cmd);
    wait(NULL);
}