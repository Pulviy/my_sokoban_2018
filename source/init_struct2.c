/*
** EPITECH PROJECT, 2018
** my_sokoban
** File description:
** initialiaze my_struct
*/

#include <stdlib.h>

#include "prototype.h"

void init_pos_box(board_t *board)
{
    int i = 0;
    int j = 0;
    int k = 0;
    int l = 0;

    malloc_pos_box(board);
    while (board->map[i] != NULL) {
        while (board->map[i][j] != '\0') {
            if (board->map[i][j++] == 'X') {
                board->pos_box[k][l] = i;
                ++l;
                board->pos_box[k][l] = j - 1;
                l = 0;
                ++k;
            }
        }
        j = 0;
        ++i;
    }
    board->pos_box[k][l] = -1;
}

void init_pos_storage(board_t *board)
{
    int i = 0;
    int j = 0;
    int k = 0;
    int l = 0;

    malloc_pos_storage(board);
    while (board->map[i] != NULL) {
        while (board->map[i][j] != '\0') {
            if (board->map[i][j++] == 'O') {
                board->pos_storage[k][l] = i;
                ++l;
                board->pos_storage[k][l] = j - 1;
                l = 0;
                ++k;
            }
        }
        j = 0;
        ++i;
    }
    board->pos_storage[k][l] = -1;
}