/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpellier <lpellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 14:08:48 by lpellier          #+#    #+#             */
/*   Updated: 2021/11/15 18:12:16 by lpellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct	s_stack {
	int *				nbr_elements;
	int	*				value;
	struct s_stack *	prev;
	struct s_stack *	next;
}				t_stack;

t_stack *	init_stack(int size, char ** content);
void		free_stack(t_stack ** stack);

void	push_front(t_stack ** stack_head, int * string);
void	push_back(t_stack * stack_head, int * string);
void	remove_front(t_stack ** stack_head, int destroy);

void	swap(t_stack * stack);
void	sswap(t_stack * stack_a, t_stack * stack_b);
void	push(t_stack ** stack_one, t_stack ** stack_two);
void	rotate(t_stack ** stack);
void	rrotate(t_stack ** stack_a, t_stack ** stack_b);
void	reverse_rotate(t_stack ** stack);
void	rreverse_rotate(t_stack ** stack_a, t_stack ** stack_b);

int	*	str_to_int(char * string);
