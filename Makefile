##
## Makefile for  in /home/karst_j/Igraph/TD/fonct
##
## Made by Julien Karst
## Login   <karst_j@epitech.net>
##
## Started on  Tue Nov 18 10:28:01 2014 Julien Karst
## Last update Sun Mar 15 16:01:54 2015 Julien Karst
##

NAME	= rtv1

CC	= gcc

RM	= rm -f

CFLAGS	+= -Iinclude/ -Iminilibx -g

SRCS	= src/rt.c \
	  src/my_key.c \
	  src/fonc.c \
	  src/my_calc.c \
	  src/my_calc2.c \
	  src/obj.c \
	  src/list.c \
	  src/my_minifonc.c \
	  src/my_expose.c

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(LDFLAGS) -L./minilibx/ -lmlx -lXext -lX11 -lm

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re cat
