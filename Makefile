# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dlerma-c <dlerma-c@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/13 20:41:34 by dlerma-c          #+#    #+#              #
#    Updated: 2022/11/22 14:02:46 by dlerma-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#··············································································#
#                                   NAMES                                      #
#··············································································#

NAME = libftprintf.a
LBFT_NAME = libft.a
#··············································································#
#                                    PATH                                      #
#··············································································#

OBJ_PATH = obj
SRC_PATH = src
INC_PATH = inc
LBFT_PATH = lbft

#··············································································#
#                                    LIBS                                      #
#··············································································#

# flags librerias
# ruta .a
LDFLAGS = -L $(LBFT_PATH)

# nombre lib
LDLIBS = -lft

#··············································································#
#                                    SRCS                                      #
#··············································································#

SRCS = do_unsint.c ft_itoa_base.c ft_printf.c num_characters.c pointer_change.c
OBJS_NAME = $(SRCS:%.c=%.o)
OBJS = $(addprefix $(OBJ_PATH)/, $(OBJS_NAME))
LIBFT = $(addprefix $(LBFT_PATH)/, $(LBFT_NAME))
#··············································································#
#                                    FLAGS                                     #
#··············································································#

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g3
#include <xx.h> // path of .h
CFLAGS += -I $(INC_PATH) -I $(LBFT_PATH)

#··············································································#
#                                    RULES                                     #
#··············································································#

.PHONY: all re clean fclean

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	cp $(LIBFT) .
	cp $(LBFT_NAME) $(NAME)
	ar -rcs $(NAME) $(OBJS)

$(LIBFT):
	make -C $(LBFT_PATH)

debug: CFLAGS += -fsanitize=address -g3
debug: $(NAME)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS): | $(OBJ_PATH)

$(OBJ_PATH): 
	mkdir -p $(OBJ_PATH) 2> /dev/null

clean:
	make fclean -C $(LBFT_PATH)
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -rf $(NAME)

re: fclean all
