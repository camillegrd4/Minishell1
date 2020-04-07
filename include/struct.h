/*
** EPITECH PROJECT, 2020
** struct
** File description:
** struct
*/

#ifndef STRUCT_H
#define STRUCT_H

typedef struct shell {
    char *cmd;
    char **array;
    char *path;
    char **path_bis;
}shell_t;

typedef struct env {
    char *name;
    char *params;
    char *str;
    struct tetris *next;
}env_t;

#endif /* !STRUCT_H */
