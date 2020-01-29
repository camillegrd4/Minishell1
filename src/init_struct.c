/*
** EPITECH PROJECT, 2020
** init
** File description:
** init
*/

#include "my.h"

int init_struct_minishell(shell_t *shell)
{
    shell->array = NULL;
    shell->cmd = NULL;
    shell->path = NULL;
}