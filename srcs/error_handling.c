/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpellier <lpellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 15:12:36 by lpellier          #+#    #+#             */
/*   Updated: 2021/11/19 16:16:11 by lpellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_sorted(t_stack *stack)
{
	int	size;
	int	i;

	size = stack->nbr_elements;
	i = 0;
	while (i < size -1)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
		i++;
	}
	return (1);
}

int	bigger_than_int(char *nbr)
{
	long long	cmp;

	cmp = str_to_long(nbr);
	if (cmp < INT_MIN || cmp > INT_MAX)
		return (1);
	return (0);
}

int	not_numerical(char *nbr)
{
	int	i;

	i = 0;
	if (nbr[i] && nbr[i] == '-')
		i++;
	if (i > 0 && !nbr[i])
		return (1);
	while (nbr[i])
	{
		if (nbr[i] < '0' || nbr[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

int	duplicates(char **numbers)
{
	int	size;
	int	i;
	int	j;

	size = 0;
	while (numbers[size])
		size++;
	if (size < 2)
		return (0);
	i = 0;
	while (numbers[i])
	{
		j = i + 1;
		while (numbers[j])
		{
			if (!ft_strcmp(numbers[i], numbers[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_errors(char **numbers)
{
	int	i;

	i = 0;
	if (duplicates(numbers))
		return (1);
	while (numbers[i])
	{
		if (bigger_than_int(numbers[i]) || not_numerical(numbers[i]))
			return (1);
		i++;
	}
	return (0);
}
