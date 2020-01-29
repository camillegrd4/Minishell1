/*
** EPITECH PROJECT, 2020
** mini
** File description:
** mini
*/

#include "my.h"

int exec_function(char **envp, shell_t *shell)
{
    shell->path = my_strcat("/bin/", shell->cmd);
    execve(shell->path, shell->array, envp);
    exit(0);
}

int my_function(shell_t *shell, char **envp)
{
    if (!envp || !shell)
        return 84;
    shell->array = my_str_to_world_array(shell->cmd);
    if (!shell->array)
        return 84;
    if (my_strncmp(shell->array[0], "cd", 2) == 0) {
        if (cd_function(shell) == 0)
            return 0;
    }
    if (exec_function(envp, shell) == 84)
        return 84;
    return 0;
}

char minishel(char **argv, char **envp)
{
    pid_t pid;
    shell_t *shell = malloc(sizeof(shell));
    init_struct_minishell(shell);

    if (!argv || !envp)
        return 84;
    while (1) {
        my_putstr("$ > ");
        shell->cmd = get_next_line(0);
        if (!shell->cmd)
            return 84;
        pid = fork();
        if (pid == -1)
            exit(0);
        else if (pid == 0) {
            if (my_function(shell, envp) == 84)
                return 84;
        } else
            pid = waitpid(-1, NULL, 0);
    }
    return 0;
}