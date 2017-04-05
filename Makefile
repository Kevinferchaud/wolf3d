##
## Makefile for emacs in /home/kevin.ferchaud/wolf3d
## 
## Made by ferchaud kevin
## Login   <kevin.ferchaud@epitech.net>
## 
## Started on  Tue Jan 10 15:15:22 2017 ferchaud kevin
## Last update Fri Jan 20 14:54:02 2017 ferchaud kevin
##

NAME	=	wolf3d

SRC	=	wolf3d.c		\
		wolf3d2.c		\
		drawmap.c		\
		drawsaber.c		\
		option.c		\
		src/my_put_pixel.c	\
		option2.c		\
		src/my_draw_line.c	\
		src/move_forward.c	\
		src/raycast.c

OBJ	=	$(SRC:.c=.o)

RM	=	rm -f

CFLAGS	=	-I include -O3

CC	=	gcc

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) -lc_graph_prog -lm

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all
