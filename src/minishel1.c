/*
** EPITECH PROJECT, 2020
** mini
** File description:
** mini
*/

#include "my.h"

int exec_function(char *cmd, char **envp, char **array)
{
    char *path = NULL;

    if (!envp || !cmd)
        return 84;
    array = my_str_to_world_array(cmd);
    if (!array)
        return 84;
    path = my_strcat("/bin/", cmd);
    execve(path, array, envp);
    exit(0);
    return 0;
}

char minishel(char **argv, char **envp)
{
    char *cmd = NULL;
    char **array = NULL;
    char *path = NULL;
    pid_t pid;

    if (!argv || !envp)
        return 84;
    while (1) {
        my_putstr("$ > ");
        cmd = get_next_line(0);
        if (!cmd)
            return 84;
        pid = fork();
        if (pid == -1)
            exit(0);
        else if (pid == 0) {
            exec_function(cmd, envp, array);
        } else
            pid = waitpid(-1, NULL, 0);
    }
    return 0;
}