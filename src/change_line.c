/*
** EPITECH PROJECT, 2020
** line
** File description:
** line
*/

#include "my.h"

int change_env_next(shell_t *shell, int line)
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
                shell->line = 1;
                shell->save_env[y] = change_line(shell, i, y);
                break;
            }
        } else
            y++;
    }
    return 0;
}

int change_env(char **envp, shell_t *shell)
{
    int line = 0;
    char **str = NULL;

    shell->line = 0;
    change_env_next(shell, line);
    if (shell->line == 0) {
        change_save_env(envp, shell);
        shell->save_env = add_line(envp, shell);
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
    shell->pos = y;
    new[x] = '=';
    x++;
    while (shell->remove[j] != '\0') {
        new[x] = shell->remove[j];
        x++;
        j++;
    }
    return new;
}