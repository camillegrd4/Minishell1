##
## EPITECH PROJECT, 2019
## make
## File description:
## make
##

SRC	=		src/main.c \
			src/recode_function.c \
			src/minishell.c \
			src/init_struct.c \
			src/exec_function.c \
			lib/my_putchar.c \
			lib/my_putstr.c \
			lib/my_strlen.c \
			lib/my_str_to_world_array.c \
			lib/my_strcat.c \
			lib/my_strncmp.c \
			lib/my_str_to_world_array_colon.c \
			src/env_function.c \
			lib/my_strncmp_next.c \

CFLAGS	=	-I ./include -g

LDFLAGS =	-L./lib

OBJ	=	$(SRC:.c=.o)

NAME	=	mysh

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(LDFLAGS)

debug:	$(OBJ)
	gcc -o debug $(OBJ) $(CFLAGS)

re:	fclean all

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

tests_run:
	make -C tests/
	./tests/unit_tests

.PHONY:	fclean clean all re tests_run