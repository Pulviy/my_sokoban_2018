/*
** EPITECH PROJECT, 2018
** my_sokoban
** File description:
** initialize my struct
*/

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

#include "prototype.h"

char *create_buffer(char *buffer, char *fp, int nb_char)
{
    int i = 0;
    int error = 0;
    int fd = open(fp, O_RDONLY);

    buffer[nb_char] = '\0';
    if ((error = read(fd, buffer, nb_char)) == -1)
        exit(84);
    while (i != error) {
        if (buffer[i] != 'P' && buffer[i] != 'O' && buffer[i] != '#' &&
            buffer[i] != ' ' && buffer[i] != 'X' && buffer[i] != '\n')
            exit(84);
        ++i;
    }
    return (buffer);
}

void init_x_y(board_t *board)
{
    int i = 0;
    int j = 0;

    while (board->map[i] != NULL) {
        while (board->map[i][j] != '\0') {
            if (board->map[i][j] == 'P') {
                board->player_x = j;
                board->player_y = i;
            }
            ++j;
        }
        j = 0;
        ++i;
    }
}

void buffer_to_map(board_t *board, char *fp, int nb_char)
{
    int i = 0;
    int j = 0;
    int k = 0;
    char *buffer = malloc(sizeof(char) * (nb_char + 1));

    buffer = create_buffer(buffer, fp, nb_char);
    malloc_map(board, fp);
    while (buffer[i] != '\0') {
        while (buffer[i] != '\n' && buffer[i] != '\0') {
            board->map[j][k] = buffer[i++];
            ++k;
        }
        board->map[j][k] = buffer[i];
        if (buffer[i] != '\0') {
            board->map[j][++k] = '\0';
            ++i;
        }
        k = 0;
        ++j;
    }
    free(buffer);
}

void init_board(board_t *board, char *fp)
{
    int nb_char = count_number_char(fp);

    buffer_to_map(board, fp, nb_char);
    init_x_y(board);
    init_pos_box(board);
    init_pos_storage(board);
}