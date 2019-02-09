/*
** EPITECH PROJECT, 2018
** my_sokoban
** File description:
** header file for my_sokoban
*/

#ifndef PSU_MY_SOKOBAN_2018_MY_H
#define PSU_MY_SOKOBAN_2018_MY_H

#include "struct.h"

//tools.c
int my_putstr(char const *str);
void my_putchar(char c);
int my_strlen(char const *str);

//init_struct.c
char *create_buffer(char *buffer, char *fp, int nb_char);
void init_x_y(board_t *board);
void buffer_to_map(board_t *board, char *fp, int nb_char);
void init_board(board_t *board, char *fp);

//init_struct2.c
void init_pos_box(board_t *board);
void init_pos_storage(board_t *board);

// map_size.c
int count_number_char(char *fp);
int count_number_rows(char *fp);
int count_number_cols(char *fp);
int buffer_for_nb_cols(char *fp);

//all_malloc.c
void malloc_map(board_t *board, char *fp);
void malloc_pos_box(board_t *board);
void malloc_pos_storage(board_t *board);

//tools_malloc.c
int counter_pos_boxes(board_t *board, int counter);
int counter_pos_storages(board_t *board, int counter);

//game.c
void display_map(board_t *board, char *fp);
void storage_parsing(board_t *board);
void play(board_t *board, char *fp);

//moves_management.c
void move_objects(board_t *board, int y, int x);
void key_check(board_t *board, int ch);

//win_loose_condition.c
int counter_of_boxes(board_t *board);
int check_boxes_moves(board_t *board, int i, int j, int loose);
void win_condition(board_t *board, int counter_boxes);
void loose_condition(board_t *board, int counter_boxes);

//freee_struct.c
void free_pos_box(int **map);
void free_pos_storage(int **map);
void free_map(char **map);
void free_struct(board_t *board);

#endif //PSU_MY_SOKOBAN_2018_MY_H
