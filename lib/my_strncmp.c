/*
** EPITECH PROJECT, 2019
** my_strncmp.c
** File description:
** my_strncmp.c
*/

#include "my.h"

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;
    int j = 0;
    int lenght_s1 = my_strlen(s1);
    int lenght_s2 = my_strlen(s2);

    if (!s1 || !s2)
        return 84;
    if (lenght_s1 < lenght_s2)
        return ((-1) * s2[lenght_s1]);
    if (lenght_s1 > lenght_s2)
        return (s1[lenght_s2]);
    while (s1[i] != '\0' && i < n) {
        if (s1[i] - s2[j] < 0)
            return (s1[i] - s2[j]);
        if (s1[i] - s2[j] > 0)
            return (s1[i] - s2[j]);
        i = i + 1;
        j = j + 1;
    }
    return (0);
}
