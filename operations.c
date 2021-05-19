/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpellier <lpellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 11:43:13 by lpellier          #+#    #+#             */
/*   Updated: 2021/05/05 17:39:22 by lpellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		swap(int *stack, int operation)
{
	int		tmp;

	if (stack[0] == -1 || stack[1] == -1)
		return ;
	tmp = stack[0];
	stack[0] = stack[1];
	stack[1] = tmp;
	if (operation == 1)
		ft_printf("sa\n");
	else if (operation == 2)
		ft_printf("sb\n");
	else
		return ;
}

void		swap_both(int *stack_a, int *stack_b)
{
	swap(stack_a, 0);
	swap(stack_b, 0);
	ft_printf("ss\n");
}

/*
** don't know whether to free or not in this function
** it seems i don't need to since i'm doing it at the end of the program
*/

void		push(int *stack_receiver, int *stack_donor, int operation)
{
	int		tmp;

	tmp = stack_donor[0];
	remove_int(stack_donor, 0);
	add_int(stack_receiver, tmp, 0);
	if (operation == 1)
		ft_printf("pa\n");
	else if (operation == 2)
		ft_printf("pb\n");
}

void		rotate(int *stack, int operation)
{
	int		tmp;
	int		len;

	tmp = stack[0];
	remove_int(stack, 0);
	len = int_lint(stack) - 1;
	add_int(stack, tmp, len);
	if (operation == 1)
		ft_printf("ra\n");
	else if (operation == 2)
		ft_printf("rb\n");
	else
		return ;
}

void		rotate_both(int *stack_a, int *stack_b)
{
	rotate(stack_a, 0);
	rotate(stack_b, 0);
	ft_printf("rr\n");
}

void		reverse_rotate(int *stack, int operation)
{
	int		tmp;
	int		len;

	len = int_lint(stack) - 1;
	tmp = stack[len];
	remove_int(stack, len);
	add_int(stack, tmp, 0);
	if (operation == 1)
		ft_printf("rra\n");
	else if (operation == 2)
		ft_printf("rrb\n");
	else
		return ;
}

void		reverse_rotate_both(int *stack_a, int *stack_b)
{
	reverse_rotate(stack_a, 0);
	reverse_rotate(stack_b, 0);
	ft_printf("rrr\n");
}
