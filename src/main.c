/*
** EPITECH PROJECT, 2019
** main
** File description:
** main
*/

#include "my.h"

game *init_game(game *s, int nb_lines, char *str)
{
    s = malloc(sizeof(game));
    if (s == NULL)
        return (NULL);
    s->board = malloc(sizeof(char *) * (nb_lines + 2));
    s->nb_max = my_getnbr(str);
    if (s->nb_max <= 0)
        return (NULL);
    return (s);
}

bool check_matches(game *s)
{
    int line = 1;

    for (int i = 0; s->board[line] && s->board[line][i];) {
        if (s->board[line][i] == '|')
            return (true);
        i++;
        if (!s->board[line][i]) {
            i = 0;
            line++;
        }
    }
    return (false);
}

int main(int ac, char **av)
{
    int nb_lines = 0;
    game *s;

    if (ac != 3)
        return (MY_EXIT_ERROR);
    nb_lines = my_getnbr(av[1]);
    if (nb_lines < 1 || nb_lines > 100)
        return (MY_EXIT_ERROR);
    s = init_game(s, nb_lines, av[2]);
    if (s == NULL)
        return (MY_EXIT_ERROR);
    s = fill_board(s, nb_lines);
    return (game_loop(s, nb_lines));
}
