/*
** EPITECH PROJECT, 2018
** my_sokoban
** File description:
** tools file wich contains usefull little functions
*/

#include <unistd.h>

#include "prototype.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char const *str)
{
    int n = 0;

    while (str[n] != 0)
    {
        my_putchar(str[n]);
        n = n + 1;
    }
    return (0);
}

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i = i + 1;
    }
    return (i);
}