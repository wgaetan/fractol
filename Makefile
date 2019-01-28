# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: wgaetan <wgaetan@student.le-101.fr>        +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 0017/11/16 07:56:05 by berneli      #+#   ##    ##    #+#        #
#    Updated: 2018/05/11 11:59:37 by wgaetan     ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #
.PHONY: all clean fclean re

NAME = fractol

SRCS = fractol.c image_manage.c color_check.c mendelbrot.c julia.c \
burningship.c drawing_shapes.c julia_factor_rep.c mouse_buttons.c \
	mouse_cursor.c keyboard_key.c info_menu.c \

OBJS = $(SRCS:.c=.o)

FLAGS = -g -Wall -Wextra -Werror

INC = -I minilibx_macos -I libft

HEADERS = fdf.h

LIBS = minilibx_macos/libmlx.a libft/libft.a

EXT_LIBS = -framework OpenGl -framework AppKit

all: $(NAME)

$(NAME): $(LIBS) $(OBJS)
	gcc $(FLAGS) $(LIBS) $(EXT_LIBS) $(OBJS) -o $(NAME)

$(LIBS):
	make -C ./libft
	make -C ./minilibx_macos

./%.o: ./%.c
	gcc $(FLAGS) $(INC) -o $@ -c $< -I $(HEADERS)

clean:
	rm -f $(OBJS)
	make -C ./libft clean

fclean: clean
	rm -f $(NAME)
	make -C ./libft fclean

re: fclean all
	make -C ./libft re
