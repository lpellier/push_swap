/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpellier <lpellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 12:53:09 by lpellier          #+#    #+#             */
/*   Updated: 2021/03/13 11:54:53 by lpellier         ###   ########.fr       */
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

void		print_linked_list(void *data)
{
	char	*ptr;
	int		c;

	ptr = (char *)data;
	if (ptr)
	{
		c = ft_atoi(ptr);
		ft_printf("%d\n", c);
	}
}

int			init_linked_list(t_list *a, char **av)
{
	int		i;

	i = 2;
	while (av[i])
	{
		ft_list_push_back(&a, ft_strdup(av[i]));
		i++;
	}
	return (0);
}

void		free_stack(void *data)
{
	char	*ptr;

	ptr = (char *)data;
	free(ptr);
}

// int			compare_value(int a, int b)
// {
// 	return (a - b);
// }
