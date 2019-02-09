/*
** EPITECH PROJECT, 2018
** my_sokoban
** File description:
** functions which return number of rows and cols in the map
*/

#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#include "prototype.h"

int count_number_char(char *fp)
{
    struct stat sb;
    int fd = open(fp, O_RDONLY);

    if (fd == -1)
        exit(84);
    if (stat(fp, &sb) == -1)
        exit(84);
    if (sb.st_size == 0)
        exit(84);
    close(fd);
    return (sb.st_size);
}

int count_number_rows(char *fp)
{
    int i = 0;
    int nb_rows = 0;
    int error = 0;
    int nb_char = count_number_char(fp);
    int fd = open(fp, O_RDONLY);
    char *buffer = malloc(sizeof(char) * nb_char + 1);

    buffer[nb_char] = '\0';
    error = read(fd, buffer, nb_char);
    if (error == -1)
        exit(84);
    while (buffer[i] != '\0') {
        if (buffer[i] == '\n')
            ++nb_rows;
        ++i;
    }
    ++nb_rows;
    close(fd);
    free(buffer);
    return (nb_rows);
}

int count_number_cols(char *fp)
{
    int i = 0;
    int nb_cols = 0;
    int tmp = 0;
    int nb_char = count_number_char(fp);
    char *buffer = malloc(sizeof(char) * nb_char + 1);

    buffer = create_buffer(buffer, fp, nb_char);
    while (buffer[i] != '\0') {
        while (buffer[i] != '\n' && buffer[i] != '\0') {
            ++tmp;
            ++i;
        }
        if (buffer[i] != '\0')
            ++i;
        if (++tmp > nb_cols)
            nb_cols = tmp;
        tmp = 0;
    }
    free(buffer);
    return (nb_cols);
}