# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpellier <lpellier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/25 19:17:20 by lucaspellie       #+#    #+#              #
#    Updated: 2021/03/12 12:54:27 by lpellier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LIBFT = libft/libft.a

CFLAGS = -Wall -Werror -Wextra -pedantic -g3

CC = clang

SRCS_PS = push_swap.c \
			operations.c \
			utils.c 
OBJS_PS = $(SRCS_PS:.c=.o)

# SRCS_C = checker.c \
# 			operations.c
# OBJS_C = $(SRCS_C:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS_PS)
	make -C libft
	cp libft/libft.a ./$(NAME)
	$(CC) $(CFLAGS) $(SRCS_PS) -o push_swap $(LIBFT)
	# $(CC) $(CFLAGS) $(SRCS_C) -o checker $(LIBFT)

clean :
	rm -rf $(OBJS_C) $(OBJS_PS)
	make clean -C libft

fclean : clean
	rm -rf $(NAME)
	make fclean -C libft

re : fclean all
