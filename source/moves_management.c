/*
** EPITECH PROJECT, 2018
** my_sokoban
** File description:
** manage movements in my the game
*/

#include <curses.h>

#include "prototype.h"

void move_objects(board_t *board, int y, int x)
{
    if ((board->map[board->player_y + y][board->player_x + x]) == ' ' ||
(board->map[board->player_y + y][board->player_x + x]) == 'O') {
        board->map[board->player_y][board->player_x] = ' ';
        board->map[board->player_y + y][board->player_x + x] = 'P';
        board->player_x = board->player_x + x;
        board->player_y = board->player_y + y;
    } else if ((board->map[board->player_y + y][board->player_x + x]) == 'X'
&& ((board->map[board->player_y + y * 2][board->player_x + x * 2]) == ' '
|| (board->map[board->player_y + y * 2][board->player_x + x * 2]) == 'O')) {
        board->map[board->player_y + y * 2][board->player_x + x * 2] = 'X';
        board->map[board->player_y][board->player_x] = ' ';
        board->map[board->player_y + y][board->player_x + x] = 'P';
        board->player_x = board->player_x + x;
        board->player_y = board->player_y + y;
    }
}

void key_check(board_t *board, int ch)
{
    if (ch == KEY_UP)
        move_objects(board, -1, 0);
    if (ch == KEY_DOWN)
        move_objects(board, 1, 0);
    if (ch == KEY_LEFT)
        move_objects(board, 0, -1);
    if (ch == KEY_RIGHT)
        move_objects(board, 0, 1);
}
