/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpellier <lpellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 16:08:51 by lpellier          #+#    #+#             */
/*   Updated: 2021/11/20 12:23:44 by lpellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

int	check_max_bits(t_stack *stack_a)
{
	int	ret;
	int	nbr;

	nbr = stack_a->nbr_elements - 1;
	ret = 0;
	while (nbr)
	{
		nbr /= 2;
		ret++;
	}
	return (ret);
}

int	smallest(t_stack *stack)
{
	int		min;
	int		i;
	t_stack	*stack_current;

	min = INT_MAX;
	stack_current = stack;
	i = 0;
	while (i < stack->nbr_elements)
	{
		if (stack_current->index_value < min)
			min = stack_current->index_value;
		stack_current = stack_current->next;
		i++;
	}
	return (min);
}

int	biggest(t_stack *stack)
{
	int		max;
	int		i;
	t_stack	*stack_current;

	max = INT_MIN;
	stack_current = stack;
	i = 0;
	while (i < stack->nbr_elements)
	{
		if (stack_current->index_value > max)
			max = stack_current->index_value;
		stack_current = stack_current->next;
		i++;
	}
	return (max);
}

int	closest_minus(t_stack *stack, int value)
{
	int	i;
	int	closest;

	if (value == 0)
		return (-1);
	closest = value - 1;
	i = 0;
	while (i < stack->nbr_elements)
	{
		if (stack->index_value == closest)
			return (closest);
		stack = stack->next;
		i++;
	}
	return (closest_minus(stack, value - 1));
}

int	closest_plus(t_stack *stack, int value, int max_elem)
{
	int	closest;
	int	i;

	if (value == max_elem)
		return (-1);
	closest = value + 1;
	i = 0;
	while (i < stack->nbr_elements)
	{
		if (stack->index_value == closest)
			return (closest);
		stack = stack->next;
		i++;
	}
	return (closest_plus(stack, value + 1, max_elem));
}
