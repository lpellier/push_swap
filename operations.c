/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpellier <lpellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 15:26:22 by lpellier          #+#    #+#             */
/*   Updated: 2021/11/19 11:28:45 by lpellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

// Swaps the first two elements at the top of the stack
void	swap(t_stack ** stack, char s) {
	t_stack * tmp = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = tmp->prev;
	tmp->prev->next = (*stack);
	tmp->prev = (*stack);
	tmp->next = (*stack)->next;
	tmp->next->prev = tmp;
	(*stack)->next = tmp;
	if (s == 'a')
		printf("sa\n");
	else if (s == 'b')
		printf("sb\n");
}

void	sswap(t_stack ** stack_a, t_stack ** stack_b) {
	swap(stack_a, 'c');
	swap(stack_b, 'c');
	printf("ss\n");
}

void	push(t_stack ** stack_one, t_stack ** stack_two, char s) {
	if (!(*stack_two))
		return ;
	
	t_stack * tmp = *stack_two;
	if ((*stack_two)->nbr_elements == 1) {
		*stack_two = NULL;
	}
	else {
		t_stack * prev_tmp = (*stack_two)->prev;
		(*stack_two)->prev->next = (*stack_two)->next;
		*stack_two = (*stack_two)->next;
		(*stack_two)->prev = prev_tmp;
		update_size(*stack_two, -1);
	}
	
	if (!(*stack_one)) {
		tmp->next = tmp;
		tmp->prev = tmp;
		tmp->nbr_elements = 1;
		*stack_one = tmp;
	}
	else
		push_front(stack_one, tmp);
	if (s == 'a')
		printf("pa\n");
	else if (s == 'b')
		printf("pb\n");
}

void	rotate(t_stack ** stack, char s) {
	*stack = (*stack)->next;
	if (s == 'a')
		printf("ra\n");
	else if (s ==  'b')
		printf("rb\n");
}

void	rrotate(t_stack ** stack_a, t_stack ** stack_b) {
	rotate(stack_a, 'c');
	rotate(stack_b, 'c');
	printf("rr\n");
}

void	reverse_rotate(t_stack ** stack, char s) {
	*stack = (*stack)->prev;
	if (s == 'a')
		printf("rra\n");
	else if (s == 'b')
		printf("rrb\n");
}

void	rreverse_rotate(t_stack ** stack_a, t_stack ** stack_b) {
	reverse_rotate(stack_a, 'c');
	reverse_rotate(stack_b, 'c');
	printf("rrr\n");
}
