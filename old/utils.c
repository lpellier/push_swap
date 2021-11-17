/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpellier <lpellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 12:53:09 by lpellier          #+#    #+#             */
/*   Updated: 2021/05/05 16:29:40 by lpellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			is_numeric(int c)
{
	if (c >= 48 && c <= 57)
		return (0);
	return (1);
}

int			error_in_args(char **av)
{
	int		i;
	int		j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (is_numeric(av[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int			init_tab(int *a, char **av)
{
	int		i;

	i = 1;
	while (av[i])
	{
		a[i - 1] = ft_atoi(av[i]);
		i++;
	}
	return (0);
}

