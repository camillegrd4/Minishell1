/*
** EPITECH PROJECT, 2020
** exec
** File description:
** exec
*/

#include "my.h"

int find_path(shell_t *shell, char **envp)
{
    int i = 0;

    if (!shell || !envp)
        return 84;
    while (envp[i]) {
        if (my_strncmp(envp[i], "PATH", 4) == 0) {
            shell->path_bis = my_str_to_world_array_colon(&envp[i][5]);
            return 0;
        }
        i++;
    }
    return 84;
}

int execve_function(char **envp, shell_t *shell)
{
    int i = 0;

    if (!envp || !shell)
        return 84;
    if (find_path(shell, envp) == 84)
        return 84;
    while (shell->path_bis[i] != NULL) {
        shell->path_bis[i] = my_strcat(shell->path_bis[i], shell->array[0]);
        if (access(shell->path_bis[i], 0) == 0) {
            execve(shell->path_bis[i], shell->array, envp);
            exit(0);
        }
        i++;
    }
    if (my_putstr(shell->cmd) == 84
    || my_putstr(": Command not found.\n") == 84)
        return 84;
    return 0;
}

int exec_function(char **envp, shell_t *shell)
{
    struct stat buf;

    if (!envp || !shell)
        return 84;
    if (my_strncmp(shell->array[0], "cd", 2) != 0
    && my_strncmp(shell->array[0], "exit", 4) != 0
    && my_strncmp(shell->array[0], "setenv", 2) != 0
    && my_strncmp(shell->array[0], "unsetenv", 2) != 0) {
        if (execve_function(envp, shell) == 84)
            return 84;
    }
    return 0;
}