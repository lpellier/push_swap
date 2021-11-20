/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_push_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpellier <lpellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 16:10:07 by lpellier          #+#    #+#             */
/*   Updated: 2021/11/20 12:23:43 by lpellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

// Swaps the first two elements at the top of the stack
void	swap(t_stack **stack, char s)
{
	t_stack	*tmp;

	if (!*stack)
		return ;
	tmp = *stack;
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

void	sswap(t_stack **stack_a, t_stack **stack_b)
{
	if (!*stack_b || !*stack_b)
		return ;
	swap(stack_a, 'c');
	swap(stack_b, 'c');
	printf("ss\n");
}

void	push_swaperoo(t_stack **stack_two, t_stack **prev_tmp)
{
	if ((*stack_two)->nbr_elements == 1)
		*stack_two = NULL;
	else
	{
		*prev_tmp = (*stack_two)->prev;
		(*stack_two)->prev->next = (*stack_two)->next;
		*stack_two = (*stack_two)->next;
		(*stack_two)->prev = *prev_tmp;
		update_size(*stack_two, -1);
	}
}

void	push(t_stack **stack_one, t_stack **stack_two, char s)
{
	t_stack	*tmp;
	t_stack	*prev_tmp;

	if (!(*stack_two))
		return ;
	tmp = *stack_two;
	push_swaperoo(stack_two, &prev_tmp);
	if (!(*stack_one))
	{
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
