# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpellier <lpellier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/25 19:17:20 by lucaspellie       #+#    #+#              #
#    Updated: 2021/11/19 16:22:52 by lpellier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CFLAGS = -Wall -Werror -Wextra -pedantic -g3

CC = clang

SRCS = srcs/main.c \
		srcs/error_handling.c \
		srcs/stack_operations.c \
		srcs/utils_sort.c \
		srcs/utils_libft.c \
		srcs/utils_split.c \
		srcs/sorting.c \
		srcs/rotate_operations.c \
		srcs/swap_push_operations.c


OBJS = $(SRCS:.c=.o)

# SRCS_C = checker.c \
# 			operations.c
# OBJS_C = $(SRCS_C:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)
	# $(CC) $(CFLAGS) $(SRCS_C) -o checker $(LIBFT)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all
