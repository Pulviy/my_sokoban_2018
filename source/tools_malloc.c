/*
** EPITECH PROJECT, 2018
** my_sokoban
** File description:
** usefull function for my malloc
*/

#include <stdlib.h>

#include "prototype.h"

int counter_pos_boxes(board_t *board, int counter)
{
    int i = 0;
    int j = 0;

    while (board->map[i] != NULL) {
        while (board->map[i][j] != '\0') {
            if (board->map[i][j++] == 'X') {
                ++counter;
            }
        }
        j = 0;
        ++i;
    }
    ++counter;
    return (counter);
}

int counter_pos_storages(board_t *board, int counter)
{
    int i = 0;
    int j = 0;

    while (board->map[i] != NULL) {
        while (board->map[i][j] != '\0') {
            if (board->map[i][j++] == 'O') {
                ++counter;
            }
        }
        j = 0;
        ++i;
    }
    ++counter;
    return (counter);
}