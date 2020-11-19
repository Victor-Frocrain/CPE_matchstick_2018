/*
** EPITECH PROJECT, 2019
** ai_tour
** File description:
** ai_tour
*/

#include "my.h"

bool compare_matches_line(game *s, int line, int matches)
{
    int nb_matches = 0;

    for (int i = 0; s->board[line][i]; i++) {
        if (s->board[line][i] == '|')
            nb_matches++;
    }
    if (matches > nb_matches)
        return (false);
    return (true);
}

int check_if_filled(game *s, int line, int nb_lines, bool player)
{
    int nb_matches = 0;

    if (line <= 0 || line > nb_lines || !s->board[line]) {
        if (player)
            my_putstr("Error: this line is out of range\nLine: ");
        return (0);
    }
    for (int i = 0; s->board[line][i]; i++) {
        if (s->board[line][i] == '|')
            nb_matches++;
    }
    if (nb_matches == 0) {
        if (player)
            my_putstr("Error: not enough matches on this line\nLine: ");
        return (0);
    }
    return (nb_matches);
}

void print_ai_turn(game *s, int matches, int line)
{
    my_putstr("AI removed ");
    my_put_nbr(matches);
    my_putstr(" match(es) from line ");
    my_put_nbr(line);
    my_putchar('\n');
}
