/*
** EPITECH PROJECT, 2020
** cd
** File description:
** cd
*/

#include "my.h"

int exit_function(shell_t *shell)
{
    if (!shell)
        return 84;
    exit(0);
    return 0;
}

int cd_function(shell_t *shell)
{
    if (!shell || !shell->array[0])
        return 84;
    if (chdir(shell->array[1]) == -1)
        return 84;
    return 0;
}

int setenv_function(char **envp, shell_t *shell)
{
    int i = 0;
    char **str = NULL;

    if (!shell)
        return 84;
    str = create_list_env(envp, shell);
    print_env(str, shell);
    return 0;
}

int unsetenv_function(shell_t *shell)
{
    if (!shell)
        return 84;
    return 0;
}