/*
** EPITECH PROJECT, 2020
** cd
** File description:
** cd
*/

#include "my.h"

int exit_function(shell_t *shell)
{
    if (my_putstr("exit") == 84)
        return 84;
    exit(0);
}

int cd_function(shell_t *shell)
{
    if (!shell->array[0])
        return 84;
    if (chdir(shell->array[1]) == -1)
        return 84;
    return 0;
}