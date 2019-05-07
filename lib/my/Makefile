##
## EPITECH PROJECT, 2018
## Makefile rush2
## File description:
## rush2 make library
##

D_LIB	=	./
D_INC	=	../../include/

NAME	=	libmy.a

FML	=	$(wildcard *.c)

OBJ	=	$(FML:.c=.o)

CFLAGS	+=	-Wall -Wextra -Werror -I$(D_INC) -g

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		ar rc $(NAME) $(OBJ)

clean	:
		rm -f $(OBJ)

fclean	:	clean
		rm -f $(NAME)

re	:	fclean all
