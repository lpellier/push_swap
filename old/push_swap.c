/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpellier <lpellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 11:57:54 by lpellier          #+#    #+#             */
/*   Updated: 2021/05/07 13:18:08 by lpellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** push_swap takes an array of ints as argument and sorts it using operations
** defined in operations.c
** the cleaner way to do achieve this is to transform that array
** into a linked list, which i'll be able to modify at will.
*/

int		int_lint(int *lint)
{
	int		i;

	i = 0;
	while (lint[i] != -1)
		i++;
	return (i);
}

void    set_lint(int *lint)
{
	int             i;

	i = 0;
	while (i < LINE_MAX)
	{
		lint[i] = -1;
		i++;
	}
}

void    intcat(int *dest, int start, int *src)
{
	int             i;

	i = 0;
	while (src[i] != - 1)
	{
		dest[start] = src[i];
		i++;
		start++;
	}
}

int             *sublint(int *src, int index)
{
	int             i;
	int     *cpy;

	if (ft_calloc((void **)&cpy, LINE_MAX, sizeof(int)))
			return (NULL);
	set_lint(cpy);
	i = 0;
	while (src[index] != - 1)
	{
		cpy[i] = src[index];
		index++;
		i++;
	}
	return (cpy);
}

void    add_int(int *dest, int key, int index)
{
	int             *tmp;

	tmp = sublint(dest, index);
	dest[index] = key;
	index++;
	intcat(dest, index, tmp);
	secure_free(tmp);
}

void    remove_int(int  *lint, int index)
{
	while (lint[index] != -1)
	{
		lint[index] = lint[index + 1];
		index++;
	}
}


void		print_tab(int *stack_a, int *stack_b)
{
	int		i;
	
	ft_printf(CYAN"------------------------\n"RESET);
	ft_printf(CYAN"|     "RESET);
	ft_printf(RED"A");
	ft_printf(CYAN"     |"RESET);
	ft_printf(CYAN"     B     |\n"RESET);
	ft_printf(CYAN"|-----------------------|\n"RESET);
	i = 0;
	while (stack_a[i] != - 1)
	{
		ft_printf(CYAN"|     "RESET);
		ft_printf(RED"%d     "RESET, stack_a[i]);
		ft_printf(CYAN"|"RESET);
		if (stack_b[i] != -1)
			ft_printf(CYAN"     %d     |"RESET, stack_b[i]);
		else
			ft_printf(CYAN"           |"RESET);
		ft_printf("\n");
		i++;
	}
	while (stack_b[i] != - 1)
	{
		ft_printf(CYAN"      %d      /n"RESET, stack_b[i]);
		i++;
	}
	ft_printf(CYAN"------------------------\n"RESET);
}

int			smallest(int *stack)
{
	int		i;
	int		ret_nbr;
	int		ret_pos;

	i = 0;
	ret_nbr = __INT_MAX__;
	ret_pos = 0;
	while (stack[i] != -1)
	{
		if (stack[i] < ret_nbr)
		{
			ret_nbr = stack[i];
			ret_pos = i;
		}
		i++;
	}
	return (ret_pos);
}

void		three_case(int *stack_a)
{
	int		small;
	
	small = smallest(stack_a);
	
}

void		sort_stacks(int *stack_a, int *stack_b)
{
	int		len;

	len = int_lint(stack_a);
	if (len == 3)
		three_case(stack_a);
	// else if (len == 5)
}

int			main(int ac, char **av)
{
	int		*stack_a;
	int		*stack_b;

	if (ac <= 1 || error_in_args(av) || ft_calloc((void **)&stack_a, \
		LINE_MAX, sizeof(int)) || ft_calloc((void **)&stack_b, LINE_MAX, sizeof(int)))
	{
		ft_printf("Error\n");
		exit (EXIT_FAILURE);
	}
	set_lint(stack_a);
	set_lint(stack_b);
	if (ac >= 2)
		init_tab(stack_a, av);
	print_tab(stack_a, stack_b);
	sort_stacks(stack_a, stack_b);
	print_tab(stack_a, stack_b);
	exit(0);
}
