/*
** EPITECH PROJECT, 2019
** print_game_board
** File description:
** print_game_board
*/

#include "my.h"

void print_game_board(game *s)
{
    for (int i = 0; s->board[i]; i++) {
        my_putstr(s->board[i]);
        my_putchar('\n');
    }
}
