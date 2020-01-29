/*
** EPITECH PROJECT, 2020
** my
** File description:
** my
*/

#ifndef MY_H
#define MY_H

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdarg.h>
#include "gnl.h"

/*src*/
char minishel(char **argv, char **envp);
int exec_function(char *cmd, char **envp, char **array);

/*lib*/
int my_putchar(char c);
int my_putstr(char const *str);
char **my_str_to_world_array(char *str);
int my_strlen(char const *str);
char *my_strcat(char *dest, char const *src);

#endif /* !MY_H */
