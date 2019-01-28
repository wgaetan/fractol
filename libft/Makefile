# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: wgaetan <wgaetan@student.le-101.fr>        +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 0018/01/12 16:19:37 by gaetan       #+#   ##    ##    #+#        #
#    Updated: 2018/05/09 11:33:42 by wgaetan     ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

.PHONY: all, clean, fclean, re

NAME = libft.a

SRCS= ft_atoi.c\
	  ft_bzero.c\
	  ft_gnl.c\
	  ft_memalloc.c\
	  ft_memcpy.c\
	  ft_putchar.c\
	  ft_strcat.c\
	  ft_strchr.c\
	  ft_strcmp.c\
	  ft_strcpy.c\
	  ft_strdup.c\
	  ft_strjoin.c\
	  ft_strlen.c\
	  ft_strnew.c\
	  ft_strsplit.c\
	  ft_strsub.c\
	  ft_putstr.c\
	  ft_itoa.c\
	  ft_strrev.c\

OBJ= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

./%.o: ./%.c
	gcc -Wall -Wextra -Werror -o $@ -c $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
