/*
** EPITECH PROJECT, 2018
** my_sokoban
** File description:
** malloc file
*/

#include <stdlib.h>

#include "prototype.h"

void malloc_pos_box(board_t *board)
{
    int i = 0;
    int counter = 0;

    counter = counter_pos_boxes(board, counter);
    board->pos_box = malloc(sizeof(int *) * counter);
    if (board->pos_box == NULL)
        exit(84);
    while (i != counter) {
        board->pos_box[i] = malloc(sizeof(int) * 2);
        if (board->pos_box[i] == NULL)
            exit(84);
        ++i;
    }
}

void malloc_pos_storage(board_t *board)
{
    int i = 0;
    int counter = 0;

    counter = counter_pos_storages(board, counter);
    board->pos_storage = malloc(sizeof(int *) * counter);
    if (board->pos_storage == NULL)
        exit(84);
    while (i != counter) {
        board->pos_storage[i] = malloc(sizeof(int) * 2);
        if (board->pos_storage[i] == NULL)
            exit(84);
        ++i;
    }
}

void malloc_map(board_t *board, char *fp)
{
    int i = 0;
    int nb_rows = count_number_rows(fp);
    int nb_cols = count_number_cols(fp);

    board->map = malloc(sizeof(char *) * (nb_rows + 1));
    if (board->map == NULL)
        exit(84);
    while (i != nb_rows) {
        board->map[i] = malloc(sizeof(char) * (nb_cols + 1));
        if (board->map[i] == NULL)
            exit(84);
        ++i;
    }
    board->map[i] = NULL;
}