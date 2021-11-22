# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpellier <lpellier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/25 19:17:20 by lucaspellie       #+#    #+#              #
#    Updated: 2021/11/22 12:57:27 by lpellier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CHECKER = checker

CFLAGS = -Wall -Werror -Wextra -pedantic

CC = clang

SRCS = srcs/main.c \
		srcs/error_handling.c \
		srcs/stack_operations.c \
		srcs/utils_sort.c \
		srcs/utils_libft.c \
		srcs/utils_split.c \
		srcs/sorting.c \
		srcs/rotate_operations.c \
		srcs/swap_push_operations.c \
		srcs/main_help.c

SRCS_CHECKER = checker_srcs/checker.c \
				checker_srcs/gnl/get_next_line.c \
				checker_srcs/gnl/get_next_line_utils.c \
				checker_srcs/error_handling.c \
				checker_srcs/stack_operations.c \
				checker_srcs/utils_sort.c \
				checker_srcs/utils_libft.c \
				checker_srcs/utils_split.c \
				checker_srcs/rotate_operations.c \
				checker_srcs/swap_push_operations.c \
				checker_srcs/main_help.c

OBJS = $(SRCS:.c=.o)

OBJS_CHECKER = $(SRCS_CHECKER:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS) $(OBJS_CHECKER)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)
	$(CC) $(CFLAGS) $(SRCS_CHECKER) -o $(CHECKER)

clean :
	rm -rf $(OBJS) $(OBJS_CHECKER)

fclean : clean
	rm -rf $(NAME) $(CHECKER)

re : fclean all
