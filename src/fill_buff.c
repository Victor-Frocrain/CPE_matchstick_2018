/*
** EPITECH PROJECT, 2019
** fill_buff
** File description:
** fill_buff
*/

#include "my.h"

void place_matches(game *s, int nb_lines)
{
    int j = 1;

    s->board[1][nb_lines] = '|';
    for (int i = 2; s->board[i];) {
        if (s->board[i - 1][j + 1] == '|' ||
            s->board[i - 1][j - 1] == '|' || j == nb_lines)
            s->board[i][j] = '|';
        if (j == nb_lines * 2 + 1) {
            j = 0;
            i++;
        }
        else
            j++;
    }
}

void fill_line(game *s, int line, int nb_lines)
{
    for (int j = 0; j <= nb_lines * 2; j++) {
        if (j == 0 || j == nb_lines * 2)
            s->board[line][j] = '*';
        else
            s->board[line][j] = ' ';
    }
}

game *fill_board(game *s, int nb_lines)
{
    int k = 0;

    s->board[0] = malloc(sizeof(char) * (nb_lines * 2 + 1));
    for (int i = 0; i < nb_lines * 2 + 1; i++)
        s->board[0][i] = '*';
    for (k = 1; k < nb_lines + 1; k++) {
        s->board[k] = malloc(sizeof(char) * (nb_lines * 2 + 1));
        fill_line(s, k, nb_lines);
    }
    place_matches(s, nb_lines);
    s->board[k] = malloc(sizeof(char) * (nb_lines * 2 + 1));
    for (int i = 0; i < nb_lines * 2 + 1; i++)
        s->board[k][i] = '*';
    s->board[k + 1] = NULL;
    return (s);
}
