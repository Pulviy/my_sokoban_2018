/*
** EPITECH PROJECT, 2018
** my_sokoban
** File description:
** win and loose management
*/

#include <stdlib.h>
#include <curses.h>

#include "prototype.h"

int counter_of_boxes(board_t *board)
{
    int i = 0;
    int j = 0;
    int counter = 0;

    while (board->map[i] != NULL) {
        while (board->map[i][j] != '\0') {
            if (board->map[i][j++] == 'X') {
                ++counter;
            }
        }
        j = 0;
        ++i;
    }
    return (counter);
}

int check_boxes_moves(board_t *board, int i, int j, int loose)
{
    if (board->map[i][j - 1] == '#' || board->map[i][j + 1] == '#') {
        if (board->map[i - 1][j] == '#' || board->map[i + 1][j] == '#')
            ++loose;
    }
    return (loose);
}

void win_condition(board_t *board, int counter_boxes)
{
    int i = 0;
    int j = 0;
    int win = 0;

    while (board->pos_storage[i][j] != -1) {
        if (board->map[board->pos_storage[i][j]][board->pos_storage[i][j + 1]]
== 'X') {
            ++win;
        }
        if (win == counter_boxes) {
            endwin();
            my_putstr("You are the Winner !\nCongratulations !\n");
            exit(0);
        }
    ++i;
    }
}

void loose_condition(board_t *board, int counter_boxes)
{
    int i = 0;
    int j = 0;
    int loose = 0;

    while (board->map[i] != NULL) {
        while (board->map[i][j] != '\0') {
            if (board->map[i][j] == 'X') {
                loose = check_boxes_moves(board, i, j, loose);
            }
            ++j;
        }
        j = 0;
        ++i;
    }
    if (counter_boxes == loose) {
        endwin();
        my_putstr("You loose, but you can try again.\n");
        exit(1);
    }
}