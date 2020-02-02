##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## compiles libmy
##

SRC = 	my_function_test.c \
		tests_my_putstr.c \
		tests_my_putchar.c \
		../lib/my_putchar.c \
		../lib/my_putstr.c \

CFLAGS	=	-I ../include --coverage

OBJ	=	$(SRC:.c=.o)

LDFLAGS	=	-lcriterion

NAME	=	unit_tests

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(LDFLAGS) --coverage

all:	$(NAME)

re:	fclean all

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm *.gcno *.gcda
