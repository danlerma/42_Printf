# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dlerma-c <dlerma-c@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/13 20:41:34 by dlerma-c          #+#    #+#              #
#    Updated: 2021/09/13 20:42:48 by dlerma-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c

OBJS = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror -pedantic

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)
	@echo "MAKE PRINTF"

run: all
	gcc $(CFLAGS) $(NAME) main.c -g3 -o a.out
	./a.out

normi: 
	norminette $(SRC) ft_printf.h

clean: 
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME) main.c

re: fclean all

PHONY.: clean all fclean re normi
