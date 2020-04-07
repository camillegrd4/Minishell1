/*
** EPITECH PROJECT, 2020
** env
** File description:
** env
*/

#include "my.h"

char **create_list_env(char **envp, shell_t *shell)
{
    int i = 0;
    int j = 0;
    char **str = malloc(sizeof(envp) + 1);

    while (envp[j] != NULL) {
        str[i] = malloc(sizeof(10)); 
        str[i] = envp[j];
        j++;
        i++;
    }
    str[j] = NULL;
    return str;
}

int print_env(char **str, shell_t *shell)
{
    int i = 0;
    int j = 0;

    while (str[i] != NULL) {
        my_putstr(str[i]);
        my_putchar('\n');
        i++;
    }
    return 0;
}