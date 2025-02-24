#include "pipex.h"



//funcion de free kids


int ft_kid_2(int *fd, int *int_array, char  **command_2, char **env)
{
    char *path_command;
    char *path_mid;

    close(int_array[1]);
    dup2(int int_array[0], 0);
    close(int_array[0]);
    dup2(fd[1], 1);
    close(fd[0]);
    close(fd[1]);
    path_mid = NULL;
    path_command = get_path_command(command_2, env, path_mid);
    if (path_command)
        execve(path_command, command_2, env);
    ft_free_kids(command_2);
    exit(127);
}

int ft_kid_1(int *fd, int *int_array, char  **command_1, char **env)
{
    char *path_command;
    char *path_mid;

    close(int_array[0]);
    dup2(fd[0], 0);
    close(fd[0]);
    close(fd[1])
    dup2(int_array[1], 1);
    close(int_array[1]);
    path_mid = NULL;
    path_command = get_path_command(command_1, env, path_mid);
    if (path_command)
        execve(path_command, command_1, env);
    ft_free_kids(command_1);
    exit(127);
}


int ft_fork(int *fd, char **kid_1, char **command_2, char **env)
{
    int int_array[2];
    pid_t fork_1;
    pid_t fork_2;
    int status;

    pipe(int_array);
    fork_1 = fork();
    if (fork_1 == 0)
    {
        ft_free_kids(command_2);
        ft_kid_1(fd, int_array, kid_1, env);
    }
    fork_2 = fork();
    if (fork_2 == 0)
    {
        ft_free_kids(command_1);
        status = command_2(fd, int_array, command_2, env);
    }
    close(int_array[0]);
    close(int_array[1]);
    waitpid(fork_1, &status, 0);
    waitpid(fork_2, &status, 0);
    return(0);
}
