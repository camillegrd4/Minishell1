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
#include <sys/stat.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdlib.h>
#include <stdarg.h>
#include <fcntl.h>
#include "stdbool.h"
#include "stdlib.h"
#include "struct.h"

/*src*/
char minishel(char **argv, char **envp);
int my_function(shell_t *shell, char **envp);
int cd_function(shell_t *shell);
int exec_function(char **envp, shell_t *shell);
int find_path(shell_t *shell, char **envp);
shell_t *init_struct_minishell(void);
int exit_function(shell_t *shell);
int unsetenv_function(shell_t *shell);
int execve_function(char **envp, shell_t *shell);
void redirect_all_stdout(void);
int call_function_recode(char **envp, shell_t *shell);
int setenv_function(char **envp, shell_t *shell);
char **create_list_env(char **envp, shell_t *shell);
int print_env(char **str, shell_t *shell);

/*lib*/
int my_putchar(char c);
int my_putstr(char const *str);
char **my_str_to_world_array(char *str);
int my_strlen(char const *str);
char *my_strcat(char *dest, char const *src);
int my_strncmp(char const *s1, char const *s2, int n);
int my_strcmp(char const *s1, char const *s2);
char **my_str_to_world_array_colon(char *str);
char *my_strdup(char const *src);
int number_char(char *str);
int lines(char *str);
int number_char_colon(char *str);
int lines_colon(char *str);
int cd_function(shell_t *shell);
int my_strncmp_next(char const *s1, char const *s2, int n);

#endif /* !MY_H */
