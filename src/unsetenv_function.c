/*
** EPITECH PROJECT, 2020
** unset
** File description:
** unset
*/

#include "my.h"

char **remove_line(shell_t *shell, int i, int y)
{
    y = 0;
    int j = 0;
    int x = 0;
    char **new = malloc(sizeof(char *) * (count_line(shell->save_env)));

    printf("-->%i\n", shell->pos);
    while (shell->save_env[y] != NULL) {
        new[x] = malloc(sizeof(char) * (my_strlen_env(shell->save_env[i])));
        printf("y-->%i\n", y);
        if (y == (shell->pos - 1)) {
            printf("coucou\n");
            new[x] = my_strdup(shell->save_env[y]);
            y++;
        } else {
            new[x] = my_strdup(shell->save_env[y]);
        }
        y++;
        x++;
    }
    return new;
}

int my_unsetenv(shell_t *shell)
{
    int y = 0;
    int i = 0;
    int j = 0;

    shell->unset = my_strdup(shell->array[1]);
    while (shell->save_env[y] != NULL) {
        if (shell->save_env[y][i] == shell->unset[j]) {
            printf("salut\n");
            if (i = find_line(shell, i, j, y) != 1) {
                shell->save_env = remove_line(shell, i, y);
                break;
            } else
                y++;
        } else
            y++;
    }
    return 0;
}