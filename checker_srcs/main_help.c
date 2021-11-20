/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_help.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpellier <lpellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 18:32:34 by lpellier          #+#    #+#             */
/*   Updated: 2021/11/20 12:25:52 by lpellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

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
