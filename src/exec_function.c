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

    while (envp[i]) {
        if (my_strncmp(envp[i], "PATH", 4) == 0) {
            shell->path_bis = my_str_to_world_array_colon(&envp[i][5]);
            return 0;
        }
        i++;
    }
    return 84;
}

int exec_function(char **envp, shell_t *shell)
{
    struct stat buf;
    int i = 0;

    if (find_path(shell, envp) == 84)
        return 84;
    while (shell->path_bis[i] != NULL) {
        shell->path_bis[i] = my_strcat(shell->path_bis[i], shell->cmd);
        if (access(shell->path_bis[i], 0) == 0) {
            execve(shell->path_bis[i], shell->array, envp);
            exit(0);
        }
        i++;
    }
    my_putstr("command not found\n");
    return 0;
}