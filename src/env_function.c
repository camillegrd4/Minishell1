/*
** EPITECH PROJECT, 2020
** env
** File description:
** env
*/

#include "my.h"

int find_line(shell_t *shell, int i, int j, int y)
{
    while (shell->name[j] != '\0') {
        if (shell->save_env[y][i] != shell->name[j]) {
            return 1;
        }
        j++;
        i++;
    }
    return 0;
}

char *change_line(shell_t *shell, int i, int y)
{
    int j = 0;
    int x = 0;
    char *new = NULL;

    shell->remove = my_strdup(shell->array[2]);
    new = malloc(sizeof(char ) * (my_strlen(shell->remove)
        + my_strlen(shell->array[1])) + 2);
    while (shell->save_env[y][i] != '=') {
        new[x] = shell->save_env[y][i];
        i++;
        x++;
    }
    new[x] = '=';
    x++;
    while (shell->remove[j] != '\0') {
        new[x] = shell->remove[j];
        x++;
        j++;
    }
    return new;
}

int change_env(char **envp, shell_t *shell)
{
    int i = 0;
    int j = 0;
    int y = 0;

    shell->name = my_strdup(shell->array[1]);
    while (shell->save_env[y] != NULL) {
        if (shell->save_env[y][i] == shell->name[j]) {
            if (find_line(shell, i, j, y) == 1)
                y++;
            else {
                shell->save_env[y] = change_line(shell, i, y);
                break;
            }
        } else
            y++;
    }
    return 0;
}

int count_line(char **envp)
{
    int i = 0;
    int counter = 0;

    while (envp[i] != NULL) {
        i++;
    }
    return i;
}

char **create_list_env(char **envp, shell_t *shell)
{
    int i = 0;
    int j = 0;
    char **str = malloc(sizeof(char *) * (count_line(envp)) + 1);

    while (envp[j] != NULL) {
        str[i] = malloc(sizeof(char) * (my_strlen(envp[j])) + 1);
        str[i] = my_strdup(envp[j]);
        j++;
        i++;
    }
    str[i] = NULL;
    return str;
}

int print_env(char **str, shell_t *shell)
{
    int i = 0;

    while (str[i] != NULL) {
        my_putstr(str[i]);
        my_putchar('\n');
        i++;
    }
    return 0;
}