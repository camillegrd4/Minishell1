/*
** EPITECH PROJECT, 2020
** cd
** File description:
** cd
*/

#include "my.h"

int cd_function(shell_t *shell)
{
    if (!shell || !shell->array[0])
        return 84;
    if (chdir(shell->array[1]) == -1)
        return 84;
    return 0;
}

int setenv_function(shell_t *shell)
{
    if (!shell)
        return 84;
    return 0;
}

int unsetenv_function(shell_t *shell)
{
    if (!shell)
        return 84;
    return 0;
}