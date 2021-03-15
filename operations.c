/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpellier <lpellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 11:43:13 by lpellier          #+#    #+#             */
/*   Updated: 2021/03/13 15:26:15 by lpellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		swap(t_list *stack, int operation)
{
	char	*tmp;
	int		len;

	len = ft_list_size(stack);
	if (len == 0 || len == 1)
		return ;
	tmp = stack->data;
	stack->data = stack->next->data;
	stack->next->data = tmp;
	if (operation == 1)
		ft_printf("|		   sa			  |\n");
	else if (operation == 2)
		ft_printf("|		   sb			  |\n");
	else
		return ;
}

void		swap_both(t_list *stack_a, t_list *stack_b)
{
	swap(stack_a, 0);
	swap(stack_b, 0);
	ft_printf("|		   ss			  |\n");
}

/*
** don't know whether to free or not in this function
** it seems i don't need to since i'm doing it at the end of the program
*/

void		push(t_list **stack_receiver, t_list **stack_donor, int operation)
{
	int		len_donor;

	len_donor = ft_list_size(*stack_donor);
	if (!len_donor || !((*stack_donor)->data))
		return ;
	ft_list_push_front(stack_receiver, (*stack_donor)->data);
	*stack_donor = (*stack_donor)->next;
	if (operation == 1)
		ft_printf("|		   pa	  	    	  |\n");
	else if (operation == 2)
		ft_printf("|		   pb		     	  |\n");
}

void		rotate(t_list *stack, int operation)
{
	int		len;

	len = ft_list_size(stack);
	if (len <= 1)
		return ;
	while (stack)
	{
		swap(stack, 0);
		stack = stack->next;
	}
	if (operation == 1)
		ft_printf("|		   ra			  |\n");
	else if (operation == 2)
		ft_printf("|		   rb			  |\n");
	else
		return ;
}

void		rotate_both(t_list *stack_a, t_list *stack_b)
{
	rotate(stack_a, 0);
	rotate(stack_b, 0);
	ft_printf("|		   rr			  |\n");
}

void		reverse_rotate(t_list *stack, int operation)
{
	int		len;
	int		i;

	len = ft_list_size(stack);
	i = 0;
	if (len <= 1)
		return ;
	while (i < len - 1)
	{
		rotate(stack, 0);
		i++;
	}
	if (operation == 1)
		ft_printf("|		   rra			  |\n");
	else if (operation == 2)
		ft_printf("|		   rrb			  |\n");
	else
		return ;
}

void		reverse_rotate_both(t_list *stack_a, t_list *stack_b)
{
	reverse_rotate(stack_a, 0);
	reverse_rotate(stack_b, 0);
	ft_printf("|		   rrr			  |\n");
}
