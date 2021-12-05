# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dlerma-c <dlerma-c@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/07 13:40:36 by dlerma-c          #+#    #+#              #
#    Updated: 2021/11/24 16:45:28 by dlerma-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_putchar_fd.c ft_itoa.c ft_putstr_fd.c \
		ft_strlen.c ft_atoi.c ft_calloc.c ft_bzero.c \
		ft_strjoin.c ft_memcpy.c 

OBJS = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror -g3 #-fsanitize=address

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)
	@echo "MAKE LIBFT"

clean: 
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean all fclean re 
