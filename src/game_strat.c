/*
** EPITECH PROJECT, 2019
** gamse_strat
** File description:
** game_strat
*/

#include "my.h"

bool gain_turn(game *s, bool pair, int nb_lines)
{
    int matches = 0;

    for (int i = 0; s->board[i]; i++) {
        matches = check_if_filled(s, i, nb_lines, false);
        if (pair && matches > s->nb_max + 1) {
            update_board(s, i, 1);
            print_ai_turn(s, 1, i);
            return (true);
        }
        else if (pair == false && matches > 1 && matches <= s->nb_max) {
            update_board(s, i, matches - 1);
            print_ai_turn(s, matches - 1, i);
            return (true);
        }
    }
    return (false);
}

bool can_dissolve(game *s, int nb_lines)
{
    int matches = 0;

    for (int i = 1; s->board[i]; i++) {
        matches = check_if_filled(s, i, nb_lines, false);
        if (matches > 0 && matches <= s->nb_max) {
            update_board(s, i, matches);
            print_ai_turn(s, matches, i);
            return (true);
        }
    }
    return (false);
}

bool detect_if_pair(game *s, int nb_lines)
{
    int lines = 0;

    for (int i = 1; s->board[i] && s->board[i + 1]; i++) {
        if (check_if_filled(s, i, nb_lines, false) > 0)
            lines++;
    }
    if (lines / 2 * 2 == lines)
        return (true);
    return (false);
}

void update_random(game *s, int matches, int line)
{
    int nb = 0;

    srand(time(NULL));
    if (matches <= s->nb_max)
        nb = rand() % matches + 1;
    else
        nb = rand() % s->nb_max + 1;
    update_board(s, line, nb);
    print_ai_turn(s, nb, line);
}

void game_strat(game *s, int nb_lines)
{
    bool pair = detect_if_pair(s, nb_lines);
    int matches = 0;

    my_putstr("\nAI's turn...\n");
    if (pair && can_dissolve(s, nb_lines))
        return;
    else if (gain_turn(s, pair, nb_lines))
        return;
    for (int line = 1; s->board[line] && matches <= 0; line++) {
        matches = check_if_filled(s, line, nb_lines, false);
        if (matches > 0) {
            update_random(s, matches, line);
            break;
        }
    }
}
