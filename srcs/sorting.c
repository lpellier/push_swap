/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpellier <lpellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 16:06:56 by lpellier          #+#    #+#             */
/*   Updated: 2021/11/20 12:17:52 by lpellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_smaller(t_stack **stack, char c)
{
	int	small;

	small = smallest(*stack);
	if ((*stack)->index_value == small)
	{
		swap(stack, c);
		rotate(stack, c);
	}
	else if ((*stack)->index_value == closest_plus(*stack, small, 3))
	{
		if ((*stack)->next->index_value == small)
			swap(stack, c);
		else if ((*stack)->next->index_value == biggest(*stack))
			reverse_rotate(stack, c);
	}
	else if ((*stack)->index_value == biggest(*stack))
	{
		if ((*stack)->next->index_value == closest_plus(*stack, small, 3))
		{
			swap(stack, c);
			reverse_rotate(stack, c);
		}
		else if ((*stack)->next->index_value == small)
			rotate(stack, c);
	}
}

int	big_condition(t_stack **stack_a, t_stack **stack_b, int max_elem)
{
	if (((*stack_b)->index_value > biggest(*stack_a) && \
		(*stack_a)->prev->index_value == biggest(*stack_a)) || \
		((*stack_b)->index_value < smallest(*stack_a) && \
		(*stack_a)->index_value == smallest(*stack_a)) || \
		((*stack_a)->prev->index_value == closest_minus(*stack_a, \
		(*stack_b)->index_value) && (*stack_a)->index_value == \
		closest_plus(*stack_a, (*stack_b)->index_value, max_elem)))
		return (1);
	return (0);
}

void	conditions_sort(t_stack **stack_a, t_stack **stack_b, int max_elem)
{
	while (*stack_b)
	{
		if (big_condition(stack_a, stack_b, max_elem))
			push(stack_a, stack_b, 'a');
		else
		{
			reverse_rotate(stack_a, 'z');
			if (big_condition(stack_a, stack_b, max_elem))
			{
				rotate(stack_a, 'z');
				reverse_rotate(stack_a, 'a');
			}
			else
			{
				rotate(stack_a, 'z');
				rotate(stack_a, 'a');
			}
		}
	}
}

void	sort_small(t_stack **stack_a, t_stack **stack_b)
{
	int	max_elem;

	max_elem = (*stack_a)->nbr_elements;
	while ((*stack_a)->nbr_elements > 3)
		push(stack_b, stack_a, 'b');
	if (!is_sorted(*stack_a))
		sort_smaller(stack_a, 'a');
	conditions_sort(stack_a, stack_b, max_elem);
	while (!is_sorted(*stack_a))
	{
		reverse_rotate(stack_a, 'z');
		if (is_sorted(*stack_a))
		{
			rotate(stack_a, 'z');
			reverse_rotate(stack_a, 'a');
		}
		else
		{
			rotate(stack_a, 'z');
			rotate(stack_a, 'a');
		}
	}
}

// putting 1 in A and 0 in B
void	sort_stacks(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	int	i;
	int	j;
	int	size_b;
	int	num;

	size = (*stack_a)->nbr_elements;
	i = 0;
	while (i < check_max_bits(*stack_a))
	{
		j = 0;
		while (j < size)
		{
			num = (*stack_a)->index_value;
			if (((num >> i) & 1) == 1)
				rotate(stack_a, 'a');
			else
				push(stack_b, stack_a, 'b');
			j++;
		}
		size_b = (*stack_b)->nbr_elements;
		j = 0;
		while (j < size_b) {
			push(stack_a, stack_b, 'a');
			j++;
		}
		i++;
	}
}
