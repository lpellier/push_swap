/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpellier <lpellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 11:57:54 by lpellier          #+#    #+#             */
/*   Updated: 2021/03/12 17:13:33 by lpellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** push_swap takes an array of ints as argument and sorts it using operations
** defined in operations.c
** the cleaner way to do achieve this is to transform that array
** into a linked list, which i'll be able to modify at will.
*/

void		test(t_list **stack_a, t_list **stack_b)
{
	ft_printf(RESET RED"A : Before swap \n");
	ft_list_foreach(*stack_a, print_linked_list);
	ft_printf(RESET CYAN"---------\n");
	ft_printf(RESET BLUE"B : Before swap \n");
	ft_list_foreach(*stack_b, print_linked_list);
	sort(stack_a, stack_b);
	ft_printf(RESET CYAN"---------\n");
	ft_printf(RESET RED"A : After swap \n");
	ft_list_foreach(*stack_a, print_linked_list);
	ft_printf(RESET CYAN"---------\n");
	ft_printf(RESET BLUE"B : After swap \n");
	ft_list_foreach(*stack_b, print_linked_list);
}

/*
** here's the sorting algorithm
** i'm thinking some sort of quicksort algo even though
** we only have two piles.
** so maybe divide the list into the two piles, then sort both
** i should add something to make sure i don't do ra then rb but instead rr
** but it's not that important
*/

void		sort(t_list **stack_a, t_list **stack_b)
{
	int		len;
	int		i;

	len = ft_list_size(*stack_a);
	len = len / 2;
	i = 0;
	while (i < len)
	{
		push(stack_b, stack_a, 2);
		i++;
	}
	ft_printf("size : %d\n", ft_list_size(*stack_a));
}

/*
** issue with bstack's len
*/

int			main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (ac <= 1 || error_in_args(av))
	{
		ft_printf("Error\n");
		exit (1);
	}
	stack_a = ft_create_elem(ft_strdup(av[1]));
	stack_b = ft_create_elem(NULL);
	if (ac >= 3)
		init_linked_list(stack_a, av);
	test(&stack_a, &stack_b);
	ft_list_clear(stack_a, free_stack);
	ft_list_clear(stack_b, free_stack);
	exit(0);
}
