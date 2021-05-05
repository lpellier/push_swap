/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpellier <lpellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 11:57:54 by lpellier          #+#    #+#             */
/*   Updated: 2021/05/05 12:56:54 by lpellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** push_swap takes an array of ints as argument and sorts it using operations
** defined in operations.c
** the cleaner way to do achieve this is to transform that array
** into a linked list, which i'll be able to modify at will.
*/

// void		test(t_list **stack_a, t_list **stack_b)
// {
// 	ft_printf(RESET CYAN"---------------\n");
// 	ft_printf(RESET RED"A : Before swap \n");
// 	ft_list_foreach(*stack_a, print_linked_list);
// 	ft_printf(RESET CYAN"---------------\n");
// 	ft_printf(RESET BLUE"B : Before swap \n");
// 	ft_list_foreach(*stack_b, print_linked_list);
// 	sort(stack_a, stack_b);
// 	ft_printf(RESET CYAN"---------------\n");
// 	ft_printf(RESET RED"A : After swap \n");
// 	ft_list_foreach(*stack_a, print_linked_list);
// 	ft_printf(RESET CYAN"---------------\n");
// 	ft_printf(RESET BLUE"B : After swap \n");
// 	ft_list_foreach(*stack_b, print_linked_list);
// 	ft_printf(RESET CYAN"---------------\n");
// }

void    print_both(t_list *stack_a, t_list *stack_b)
{
	int		test;
	int		nbr_one;
	int		nbr_two;
	t_list	*list_a;
	t_list	*list_b;

	if (!stack_a || !stack_b)
		return ;
	list_a = stack_a;
	list_b = stack_b;
	test = 0;
	while (list_a && list_a->data && list_a->next != stack_a)
	{
		nbr_one = ft_atoi((char *)list_a->data);
		if (list_b && list_b->data && list_b->next != stack_b)
		{
			nbr_two = ft_atoi((char *)list_b->data);
			list_b = list_b->next;
			test = 1;
		}
		list_a = list_a->next;
		ft_printf(RESET CYAN"|");
		ft_printf(RESET RED"	%d", nbr_one);
		ft_printf(RESET CYAN"	    |");
		if (test)
		{
			ft_printf(RESET BLUE"		%d", nbr_two);
			ft_printf(RESET CYAN"	  |\n");
		}
		else
			ft_printf(RESET CYAN"		 	  |\n");
		test = 0;
	}
	nbr_one = ft_atoi((char *)list_a->data);
	if (list_b && list_b->data)
	{
		nbr_two = ft_atoi((char *)list_b->data);
		test = 1;
	}
	ft_printf(RESET CYAN"|");
	ft_printf(RESET RED"	%d", nbr_one);
	ft_printf(RESET CYAN"	    |");
	if (test)
	{
		ft_printf(RESET BLUE"		%d", nbr_two);
		ft_printf(RESET CYAN"	  |\n");
	}
	else
		ft_printf(RESET CYAN"		 	  |\n");
	test = 0;
}

void		test(t_list **stack_a, t_list **stack_b)
{
	ft_printf(RESET CYAN"|---------------Before swap---------------|\n");
	ft_printf(RESET CYAN"|");
	ft_printf(RESET RED"	A");
	ft_printf(RESET CYAN"	    |");
	ft_printf(RESET BLUE"		B");
	ft_printf(RESET CYAN"	  |\n");
	print_both(*stack_a, *stack_b);
	ft_printf(RESET CYAN"|---------------Operations----------------|\n");
	sort(stack_a, stack_b);
	ft_printf(RESET CYAN"|---------------After swap----------------|\n");
	print_both(*stack_a, *stack_b);
	ft_printf(RESET CYAN"|-----------------------------------------|\n");
}

int			sorted(t_list *stack)
{
	t_list	*list;
	int		nbr_one;
	int		nbr_two;

	list = stack;
	while (list && list->data && list->next && list->next->data)
	{
		nbr_one = ft_atoi((char *)list->data);
		nbr_two = ft_atoi((char *)list->next->data);
		if (nbr_one - nbr_two > 0)
			return (1);
		list = list->next;
	}
	ft_printf("Sorted!\n");
	return (0);
}

/*
** here's the sorting algorithm
** i'm thinking some sort of quicksort algo even though
** we only have two piles.
** so maybe divide the list into the two piles, then sort both
** i should add something to make sure i don't do ra then rb but instead rr
** but it's not that important
*/

int			sort(t_list **stack_a, t_list **stack_b)
{
	int		len;
	// int		i;

	(void)*stack_b;
	if (!sorted(*stack_a))
		return (0);
	len = ft_list_size(*stack_a);
	// i = 0;
	// while (i < len / 2)
	// {
	// 	push(stack_b, stack_a, 2);
	// 	i++;
	// }
	// sa
	// sb
	// ss
	// pa
	pb
	// ra
	// rb
	// rr
	// rra
	// rrb
	// rrr
	return (1);
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
	stack_a = NULL;
	stack_b = ft_create_elem(NULL);
	stack_b->next = stack_b;
	stack_b->prev = stack_b;
	if (ac >= 2)
		init_linked_list(&stack_a, av);
	test(&stack_a, &stack_b);
	ft_list_clear(stack_a, free_stack);
	ft_list_clear(stack_b, free_stack);
	exit(0);
}
