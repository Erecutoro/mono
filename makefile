SRC	=	$(shell find ./src -name *.c)

OBJ	=	$(SRC:.c=.o)

# CFLAGS	=	-Wextra -Werror -Wall

CPPFLAGS	=	-Iinclude -g3

NAME	=	monopoly

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(FLAG) $(OBJ) -lm

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)
	rm -f *~
	rm -f vgcore.*

re:	fclean all

.PHONY:	clean fclean re all