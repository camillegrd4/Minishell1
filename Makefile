##
## EPITECH PROJECT, 2019
## make
## File description:
## make
##

SRC	=		src/main.c \
			lib/my_putchar.c \
			lib/my_putstr.c \
			lib/my_strlen.c \
			lib/my_str_to_world_array.c \
			src/minishel1.c \
			lib/my_strcat.c \

CFLAGS	=	-I ./include -g

LDFLAGS =	-L./lib -lgnl

OBJ	=	$(SRC:.c=.o)

NAME	=	mysh

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(LDFLAGS) -lncurses
	@rm -rf $(OBJ)

debug:	$(OBJ)
	gcc -o debug $(OBJ) $(CFLAGS) -g

re:	fclean all

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)