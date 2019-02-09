/*
** EPITECH PROJECT, 2018
** my_sokoban
** File description:
** free my_struct
*/

#include <stdlib.h>

#include "prototype.h"

void free_pos_box(int **map)
{
    int i = 0;
    int j = 0;

    while (map[i][j] != -1) {
        free(map[i]);
        ++i;
    }
    free(map);
}

void free_pos_storage(int **map)
{
    int i = 0;
    int j = 0;

    while (map[i][j] != -1) {
        free(map[i]);
        ++i;
    }
    free(map);
}

void free_map(char **map)
{
    int i = 0;

    while (map[i] != NULL) {
        free(map[i]);
        ++i;
    }
    free(map);
}

void free_struct(board_t *board)
{
  free_map(board->map);
  free_pos_storage(board->pos_storage);
  free_pos_box(board->pos_box);
}