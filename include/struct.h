/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** header file for my gameboard struct
*/

#ifndef PSU_MY_SOKOBAN_2018_STRUCT_H
#define PSU_MY_SOKOBAN_2018_STRUCT_H

typedef struct board {
    int **pos_storage;
    int **pos_box;
    int player_x;
    int player_y;
    char **map;
} board_t;

#endif //PSU_MY_SOKOBAN_2018_STRUCT_H
