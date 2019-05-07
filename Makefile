##
## EPITECH PROJECT, 2018
## epitech makefile
## File description:
## makefile for rush2
##

D_SRC	=	./src/
D_LIB	=	./lib/my/
D_INC	=	./include/

NAME	=	./ai

SRC	=	$(D_SRC)main.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	+=	-W -Wall -Wextra -I$(D_INC) -g
LDFLAGS	+=	-L$(D_LIB) -lmy

all	:	$(NAME)

libmy	:
		make -C $(D_LIB)

$(NAME)	:	$(OBJ) libmy
		gcc -o $(NAME) $(OBJ) $(LDFLAGS)

clean	:
		rm -f $(OBJ)

fclean	:	clean
		rm -f $(NAME)

re	:	clean all

.PHONY	:	all clean fclean re
