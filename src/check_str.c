/*
** EPITECH PROJECT, 2019
** check_str
** File description:
** check_str
*/

#include "my.h"

int game_loop(game *s, int nb_lines)
{
    while (1) {
        print_game_board(s);
        if (check_matches(s) == false) {
            my_putstr("I lost... snif... but I'll get you next time!!\n");
            return (MY_EXIT_WIN);
        }
        if (read_changes(s, nb_lines) == false)
            return (MY_EXIT_SUCCESS);
        print_game_board(s);
        if (check_matches(s) == false) {
            my_putstr("You lost, too bad...\n");
            return (MY_EXIT_LOSE);
        }
        game_strat(s, nb_lines);
    }
}

bool check_str(char *str)
{
    for (int i = 0; str && str[i]; i++) {
        if ((str[i] < '0' || str[i] > '9') && str[i] != '-' && str[i] != '+') {
            my_putstr("Error: invalid input (positive number expected)\n");
            return (false);
        }
    }
    return (true);
}
