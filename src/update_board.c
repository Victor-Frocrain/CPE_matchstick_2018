/*
** EPITECH PROJECT, 2019
** update_board
** File description:
** update_board
*/

#include "my.h"
#include "get_next_line.h"

void update_board(game *s, int line, int matches)
{
    int i = my_strlen(s->board[line]) - 1;
    int removed = 0;

    for (; s->board[line] && s->board[line][i] &&
    removed < matches; i--) {
        if (s->board[line][i] == '|') {
            s->board[line][i] = ' ';
            removed++;
        }
    }
}

bool print_errors(game *s, int line, int matches)
{
    bool range = compare_matches_line(s, line, matches);

    if (matches <= 0) {
        my_putstr("Error: you have to remove at least one match\n");
        return (false);
    }
    if (matches > s->nb_max) {
        my_putstr("Error: you cannot remove more than ");
        my_put_nbr(s->nb_max);
        my_putstr(" matches per turn\n");
        return (false);
    }
    if (range == false) {
        my_putstr("Error: not enough matches on this line\n");
        return (false);
    }
    return (true);
}

void print_changes(int line, int matches)
{
    my_putstr("Player removed ");
    my_put_nbr(matches);
    my_putstr(" match(es) from line ");
    my_put_nbr(line);
    my_putchar('\n');
}

int choose_line(game *s, int nb_lines)
{
    bool filled = false;
    int line = 0;
    char *str = NULL;

    my_putstr("Line: ");
    str = get_next_line(0);
    if (str == NULL)
        return (-1);
    while (check_str(str) == false) {
        my_putstr("Line: ");
        str = get_next_line(0);
        if (str == NULL)
            return (-1);
    }
    line = check_line(s, nb_lines, str);
    return (line);
}

bool read_changes(game *s, int nb_lines)
{
    int line = 0;
    int matches = 0;
    bool range = false;
    char *str = NULL;

    my_putstr("\nYour turn:\n");
    if (check_input(s, nb_lines, line, matches) == false)
        return (false);
    return (true);
}
