#include "./minishell.h"

int     fd_change(t_exec **exec, int fd[])
{
    if((*exec)->next)
        dup2(fd[1], 1);
    if((*exec)->prev)
        dup2(fd[0], 0);

    return (0);
}

void    execve_teste(t_exec **exec)
{
    char *pt_str = "/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin";
    char **paths;
    int i;
    char *path_cmd;
    char *env[1];
    int fd[2];
    int id;

    paths = ft_split(pt_str, ':');
    pipe(fd);
    while(*exec)
    {
        i = 0;
        path_cmd = ft_strjoin("/", (*exec)->arr_arg[0]);
        id = fork();
        if(id == 0)
        {
            if((*exec)->prev)
            {
                dup2(fd[0], 0);
                close(fd[0]);
                close(fd[1]);
            }
            if((*exec)->next )
            {
                dup2(fd[1], 1);
                close(fd[1]);
                close(fd[0]);
            }
        }
        while(paths[i] != NULL)
        {
        free((*exec)->arr_arg[0]);
        (*exec)->arr_arg[0] = ft_strjoin(paths[i], path_cmd);
        env[0] = NULL;
        //printf("paths: %s\n", (*exec)->arr_arg[0]);
        if(id == 0)
            execve((*exec)->arr_arg[0], (*exec)->arr_arg, env);
        i++;
        }
        if(id != 0)
            *exec = (*exec)->next;
        free(path_cmd);
    }
    wait(NULL);
    close(fd[0]);
    close(fd[1]);
}