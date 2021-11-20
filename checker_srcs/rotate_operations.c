/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpellier <lpellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 16:10:31 by lpellier          #+#    #+#             */
/*   Updated: 2021/11/20 12:23:41 by lpellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

void	rotate(t_stack **stack, char s)
{
	*stack = (*stack)->next;
	if (s == 'a')
		printf("ra\n");
	else if (s == 'b')
		printf("rb\n");
}

void	rrotate(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a, 'c');
	rotate(stack_b, 'c');
	printf("rr\n");
}

void	reverse_rotate(t_stack **stack, char s)
{
	*stack = (*stack)->prev;
	if (s == 'a')
		printf("rra\n");
	else if (s == 'b')
		printf("rrb\n");
}

void	rreverse_rotate(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate(stack_a, 'c');
	reverse_rotate(stack_b, 'c');
	printf("rrr\n");
}
