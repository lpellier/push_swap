/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpellier <lpellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 14:08:48 by lpellier          #+#    #+#             */
/*   Updated: 2021/11/19 11:11:20 by lpellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct	s_stack {
	int					nbr_elements;
	int					value;
	// index_value is by default -1, and changed to whatever place this number should be sorted
	int					index_value;
	struct s_stack *	prev;
	struct s_stack *	next;
}				t_stack;

t_stack *	init_stack(int size, char ** content);
void		print_stack(t_stack * stack);
void		free_stack(t_stack ** stack);

void	push_front(t_stack ** stack_head, t_stack * new_stack);
void	push_back_new_stack(t_stack * stack_head, int new_value, int i);
void		update_size(t_stack * stack, int amount);

void	swap(t_stack ** stack, char s);
void	sswap(t_stack ** stack_a, t_stack ** stack_b);
void	push(t_stack ** stack_one, t_stack ** stack_two, char s);
void	rotate(t_stack ** stack, char s);
void	rrotate(t_stack ** stack_a, t_stack ** stack_b);
void	reverse_rotate(t_stack ** stack, char s);
void	rreverse_rotate(t_stack ** stack_a, t_stack ** stack_b);

char		**ft_split(char const *s, char c);
int	ft_strcmp(char *s1, char *s2);
int		str_to_int(char * string);
