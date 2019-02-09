/*
** EPITECH PROJECT, 2018
** my_sokoban
** File description:
** main file
*/

#include <stdlib.h>
#include <curses.h>

#include "prototype.h"

int my_sokoban(char *fp)
{
    board_t *board = malloc(sizeof(board_t));

    init_board(board, fp);
    initscr();
    keypad(stdscr, TRUE);
    noecho();
    play(board, fp);
    free_struct(board);
    free(board);
    return (0);
}

int man(void)
{
    my_putstr("USAGE\n"
"      ./my_sokoban map\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("     map file representing the warehouse map, "
"containing '#' for walls,\n");
    my_putstr("         'P' for the player, 'X' for boxes and 'O' for "
"storage locations.\n");
    return (0);
}

int main(int ac, char **av)
{
    if (ac != 2)
        return (84);
    else if ((av[1][0] == '-') && (av[1][1] == 'h') && (av[1][2] == '\0'))
        man();
    else {
        my_sokoban(av[1]);
    }
    return (0);
}