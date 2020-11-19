##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC	=	src/main.c		\
		src/print_game_board.c	\
		src/fill_buff.c		\
		src/update_board.c	\
		src/ai_tour.c		\
		src/check_str.c		\
		src/game_strat.c	\
		src/check_input.c	\

OBJ	=	$(SRC:%.c=%.o)

CFLAGS	=	-Wshadow -I ./include

LIB	=	lib/my -lmy

NAME	=	matchstick

CC	=	gcc

all:	$(NAME)

$(NAME):	$(OBJ)
		make -C lib/my/
		$(CC) -o $(NAME) $(OBJ) -L $(LIB)

clean:
	make -C lib/my clean
	rm -f $(OBJ)
	rm -f *.gcno *.gcda

fclean:	clean
	make -C lib/my fclean
	rm -f $(NAME)

re:	fclean all
