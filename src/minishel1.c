/*
** EPITECH PROJECT, 2020
** mini
** File description:
** mini
*/

#include "my.h"
#include "gnl.h"

char minishel(char **argv, char **envp)
{
    char *cmd = NULL;

    my_putstr("$ >");
    cmd = get_next_line(0);
    while (cmd) {
        my_putstr("$ >");
        cmd = get_next_line(0);
    }
    return 0;
}