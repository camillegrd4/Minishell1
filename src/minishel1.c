/*
** EPITECH PROJECT, 2020
** mini
** File description:
** mini
*/

#include "my.h"

int call_function_recode(shell_t *shell)
{
    if (!shell)
        return 84;
    if (my_strncmp(shell->array[0], "cd", 2) == 0) {
        if (cd_function(shell) == 0)
            return 0;
    }
    if (my_strncmp(shell->array[0], "setenv", 2) == 0) {
        if (setenv_function(shell) == 0)
            return 0;
    }
    if (my_strncmp(shell->array[0], "unsetenv", 2) == 0) {
        if (unsetenv_function(shell) == 0)
            return 0;
    }
    return 0;
}

int my_function(shell_t *shell, char **envp)
{
    pid_t pid;

    if (!envp || !shell)
        return 84;
    pid = fork();
    if (pid == -1)
        exit(0);
    else if (pid == 0) {
        if (call_function_recode(shell) == 84)
            return 84;
        else if (exec_function(envp, shell) == 84)
            return 84;
    } else
        pid = waitpid(-1, NULL, 0);
    return 0;
}

char minishel(char **argv, char **envp)
{
    shell_t *shell = init_struct_minishell();

    if (!argv || !envp)
        return 84;
    while (1) {
        my_putstr("$ > ");
        shell->cmd = get_next_line(0);
        if (!shell->cmd) {
            my_putstr("exit\n");
            exit(0);
        }
        shell->array = my_str_to_world_array_colon(shell->cmd);
        if (my_strncmp(shell->array[0], "exit", 4) == 0) {
            if (my_putstr("exit\n") == 84)
                return 84;
            exit(0);
        }
        if (my_function(shell, envp) == 84)
            return 84;
    }
    return 0;
}