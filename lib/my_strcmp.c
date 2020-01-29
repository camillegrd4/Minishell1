/*
** EPITECH PROJECT, 2019
** my_strcmp.c
** File description:
** my_strcmp.c
*/

#include "my.h"

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;
    int j = 0;
    int lenght_s1 = my_strlen(s1);
    int lenght_s2 = my_strlen(s2);

    if (lenght_s1 < lenght_s2)
        return ((-1) * s2[lenght_s1]);
    if (lenght_s1 > lenght_s2)
        return (s1[lenght_s2]);
    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] - s2[j] < 0)
            return (s1[i] - s2[j]);
        if (s1[i] - s2[j] > 0)
            return (s1[i] - s2[j]);
        i = i + 1;
        j = j + 1;
    }
    return 0;
}
