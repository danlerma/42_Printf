# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dlerma-c <dlerma-c@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/13 20:41:34 by dlerma-c          #+#    #+#              #
#    Updated: 2021/09/24 19:41:23 by dlerma-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c do_unsint.c ft_putchar_fd.c ft_putnbr_fd.c \
		ft_itoa.c ft_atoi.c ft_putstr_fd.c ft_strlen.c \
		ft_itoa_base.c ft_calloc.c ft_bzero.c num_characters.c \
		ft_strjoin.c ft_memcpy.c pointer_change.c

OBJS = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror -pedantic -g3 #-fsanitize=address

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)
	@echo "MAKE PRINTF"

run: all
	gcc $(CFLAGS) $(NAME) main.c -g3 -o a.out
	./a.out $(filter-out $@,$(MAKECMDGOALS))

normi: 
	norminette $(SRC) printf.h

clean: 
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME) a.out

re: fclean all

PHONY.: clean all fclean re normi
