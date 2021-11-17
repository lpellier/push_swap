/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpellier <lpellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 15:26:22 by lpellier          #+#    #+#             */
/*   Updated: 2021/11/15 18:13:59 by lpellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

// Swaps the first two elements at the top of the stack
void	swap(t_stack * stack) {
	int	* value_tmp;

	if (!stack || !stack->value || !stack->next || !stack->next->value)
		return ;
	value_tmp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = value_tmp;
}

void	sswap(t_stack * stack_a, t_stack * stack_b) {
	swap(stack_a);
	swap(stack_b);
}

void	push(t_stack ** stack_one, t_stack ** stack_two) {
	if (!(*stack_two) || !(*stack_two)->value)
		return ;

	push_front(stack_one, (*stack_two)->value);
	remove_front(stack_two, 0);
}

void	rotate(t_stack ** stack) {
	for (int i = 1; i < (*(*stack)->nbr_elements); i++)
		*stack = (*stack)->prev;
}

void	rrotate(t_stack ** stack_a, t_stack ** stack_b) {
	rotate(stack_a);
	rotate(stack_b);
}

void	reverse_rotate(t_stack ** stack) {
	for (int i = 1; i < (*(*stack)->nbr_elements); i++)
		*stack = (*stack)->next;
}

void	rreverse_rotate(t_stack ** stack_a, t_stack ** stack_b) {
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
}
