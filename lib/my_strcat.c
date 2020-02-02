/*
** EPITECH PROJECT, 2020
** cat
** File description:
** cat
*/

#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int count = 0;
    char *res = malloc(sizeof(*res) * (my_strlen(dest) + my_strlen(src) + 4));

    if (!res || !dest || !src) {
        free(res);
        return NULL;
    }
    while (dest[i]) {
        res[i] = dest[i];
        i++;
    }
    res[i] = '/';
    i++;
    while (src[count]) {
        res[i + count] = src[count];
        count++;
    }
    res[i + count] = '\0';
    return res;
}
