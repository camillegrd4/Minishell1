/*
** EPITECH PROJECT, 2020
** mini
** File description:
** mini
*/

#include "my.h"

int call_function_recode(char **envp, shell_t *shell)
{
    if (!shell || !envp)
        return 84;
    if (my_strncmp(shell->array[0], "cd", 2) == 0) {
        if (cd_function(shell) == 0)
            return 0;
    }
    if (my_strncmp(shell->array[0], "exit", 4) == 0) {
        if (exit_function(shell) == 0)
            return 0;
    }
    if (my_strncmp(shell->array[0], "setenv", 6) == 0) {
        if (setenv_function(envp, shell) == 0)
            return 0;
    }
    if (my_strncmp(shell->array[0], "unsetenv", 8) == 0) {
        if (unsetenv_function(shell) == 0)
            return 0;
    }
    return 0;
}

int my_function(shell_t *shell, char **envp)
{
    if (!envp || !shell)
        return 84;
    if (call_function_recode(envp, shell) == 84)
        return 84;
    else if (exec_function(envp, shell) == 84)
        return 84;
    return 0;
}

int principal_function(char **envp, shell_t *shell)
{
    size_t n = 0;
    char *line;
    int x = 0;

    while (1) {
        my_putstr("$ > ");
        if (x = getline(&line, &n, stdin) == -1) {
            free(shell);
            exit(0);
        }
        if (x != -1)
            shell->cmd = line;
        shell->array = my_str_to_world_array_colon(shell->cmd);
        if (!shell->cmd) {
            my_putstr("exit\n");
            exit(0);
        }
        else
            my_function(shell, envp);
    }
    return 0;
}

char minishel(char **argv, char **envp)
{
    shell_t *shell = init_struct_minishell();

    if (!argv || !envp || !shell) {
        free(shell);
        return 84;
    }
    if (principal_function(envp, shell) == 84) {
        free(envp);
        free(shell);
        return 84;
    }
    return 0;
}