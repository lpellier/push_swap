/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_help.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpellier <lpellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 18:32:34 by lpellier          #+#    #+#             */
/*   Updated: 2021/11/19 18:32:45 by lpellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	index_values(t_stack *stack)
{
	t_stack	*stack_current;
	int		index;
	int		j;
	int		i;
	int		min;

	index = 0;
	j = 0;
	while (j++ < stack->nbr_elements)
	{
		min = INT_MAX;
		stack_current = stack;
		i = 0;
		while (i++ < stack->nbr_elements)
		{
			if (stack_current->index_value == -1 && stack_current->value < min)
				min = stack_current->value;
			stack_current = stack_current->next;
		}
		if (stack_at(stack, min))
			stack_at(stack, min)->index_value = index;
		index++;
	}
}

void	update_size(t_stack *stack, int amount)
{
	int	size;
	int	i;

	size = stack->nbr_elements + amount;
	i = 0;
	while (i++ < size)
	{
		stack->nbr_elements = size;
		stack = stack->next;
	}
}

int	main_errors(int ac, char **av, char ***numbers)
{
	if (ac < 2 || !av[1])
		return (EXIT_FAILURE);
	*numbers = get_av(ac, av);
	if (!(*numbers) || !(**numbers))
		return (EXIT_FAILURE);
	else if (check_errors(*numbers))
	{
		fprintf(stderr, "Error\n");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

void	sorting(t_stack **stack_a, t_stack **stack_b, int size)
{
	if (!is_sorted(*stack_a))
	{
		index_values(*stack_a);
		if (size == 2)
			rotate(stack_a, 'a');
		else if (size == 3)
			sort_smaller(stack_a, 'a');
		else if (size <= 5)
			sort_small(stack_a, stack_b);
		else
			sort_stacks(stack_a, stack_b);
	}
}
