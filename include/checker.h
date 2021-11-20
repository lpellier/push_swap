/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpellier <lpellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 14:08:48 by lpellier          #+#    #+#             */
/*   Updated: 2021/11/20 12:25:37 by lpellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack {
	int					nbr_elements;
	int					value;
	int					index_value;
	struct s_stack		*prev;
	struct s_stack		*next;
}				t_stack;

// main
int			main_errors(int ac, char **av, char ***numbers);
void		update_size(t_stack *stack, int amount);

// stack operations
t_stack		*init_stack(int size, char **content);
t_stack		*stack_at(t_stack *stack, int value);
void		free_stack(t_stack **stack);
void		push_front(t_stack **stack_head, t_stack *new_stack);
void		push_back_new_stack(t_stack *stack_head, int new_value, int i);

// swap push operations
void		swap(t_stack **stack, char s);
void		sswap(t_stack **stack_a, t_stack **stack_b);
void		push(t_stack **stack_one, t_stack **stack_two, char s);

// rotate operations
void		rotate(t_stack **stack, char s);
void		rrotate(t_stack **stack_a, t_stack **stack_b);
void		reverse_rotate(t_stack **stack, char s);
void		rreverse_rotate(t_stack **stack_a, t_stack **stack_b);

// utils libft
int			ft_strcmp(char *s1, char *s2);
int			str_to_int(char *string);
long long	str_to_long(char *string);
char		**get_av(int ac, char **av);

// utils split
size_t		ft_strlen(const char *str);
int			count_words(const char *str, char c);
char		*word_dup(const char *str, int start, int finish);
char		**ft_split(char const *s, char c);

// error handling
int			is_sorted(t_stack *stack);
int			bigger_than_int(char *nbr);
int			not_numerical(char *nbr);
int			duplicates(char **numbers);
int			check_errors(char **numbers);

#endif
