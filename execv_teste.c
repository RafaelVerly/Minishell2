#include "./minishell.h"

void    execve_teste(t_exec **exec)
{
    char *pt_str = "/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin";
    char **paths;
    int i;
    char *path_cmd;
    char *env[1];

    i = 0;
    paths = ft_split(pt_str, ':');
    path_cmd = ft_strjoin("/", (*exec)->arr_arg[0]);
    while(paths[i] != NULL)
    {
        free((*exec)->arr_arg[0]);
        (*exec)->arr_arg[0] = ft_strjoin(paths[i], path_cmd);
        env[0] = NULL;
        //printf("paths: %s\n", (*exec)->arr_arg[0]);
        execve((*exec)->arr_arg[0], (*exec)->arr_arg, env);
        i++;
    }

}