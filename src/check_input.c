/*
** EPITECH PROJECT, 2019
** check_input
** File description:
** check_input
*/

#include "my.h"
#include "get_next_line.h"

int check_line(game *s, int nb_lines, char *str)
{
    int line = my_getnbr(str);
    bool filled = check_if_filled(s, line, nb_lines, true);

    while (line <= 0 || line > nb_lines || filled == 0) {
        if (filled > 0)
            my_putstr("Error: this line is out of range\nLine: ");
        str = get_next_line(0);
        if (str == NULL)
            return (-1);
        line = my_getnbr(str);
        filled = check_if_filled(s, line, nb_lines, true);
    }
    return (line);
}

bool check_input(game *s, int nb_lines, int line, int matches)
{
    char *str = NULL;
    bool range = false;

    while ((line <= 0 || line > nb_lines) ||
    (matches <= 0 || matches > s->nb_max || range == false)) {
        line = choose_line(s, nb_lines);
        if (line < 0)
            return (false);
        my_putstr("Matches: ");
        str = get_next_line(0);
        if (str == NULL)
            return (false);
        if (check_str(str)) {
            matches = my_getnbr(str);
            range = print_errors(s, line, matches);
        }
    }
    print_changes(line, matches);
    update_board(s, line, matches);
    return (true);
}
