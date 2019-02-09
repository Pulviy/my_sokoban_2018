/*
** EPITECH PROJECT, 2018
** my_sokoban
** File description:
** game management
*/

#include <curses.h>

#include "prototype.h"

void display_map(board_t *board, char *fp)
{
    int i = 0;
    int taille = my_strlen(board->map[i]);
    int nb_rows = count_number_rows(fp);

    while (board->map[i] != NULL) {
        mvprintw(LINES / 2 - nb_rows / 2 + i, (COLS / 2) - (taille / 2),
board->map[i]);
        ++i;
    }
    move(LINES / 2 - nb_rows / 2 + board->player_y, (COLS / 2) - (taille / 2) +
board->player_x);
    refresh();
}

void storage_parsing(board_t *board)
{
    int i = 0;
    int j = 0;

    while (board->pos_storage[i][j] != -1) {
        if (board->map[board->pos_storage[i][j]][board->pos_storage[i][j + 1]]
== ' ') {
            board->map[board->pos_storage[i][j]][board->pos_storage[i][j + 1]]
= 'O';
        }
        ++i;
    }
}

void play(board_t *board, char *fp)
{
    int finish = 0;
    int ch = 0;
    int counter_boxes = 0;

    counter_boxes = counter_of_boxes(board);
    while (finish != 1) {
        clear();
        storage_parsing(board);
        display_map(board, fp);
        win_condition(board, counter_boxes);
        loose_condition(board, counter_boxes);
        ch = getch();
        key_check(board, ch);
        if (ch == 27)
            finish = 1;
        else if (ch == ' ')
            init_board(board, fp);
    }
    endwin();
}