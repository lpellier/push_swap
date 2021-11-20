/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpellier <lpellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 16:17:05 by lpellier          #+#    #+#             */
/*   Updated: 2021/11/20 12:23:42 by lpellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

t_stack	*stack_at(t_stack *stack, int value)
{
	int		i;
	t_stack	*stack_current;

	stack_current = stack;
	i = 0;
	while (i < stack->nbr_elements)
	{
		if (stack_current->value == value)
			return (stack_current);
		stack_current = stack_current->next;
		i++;
	}
	return (NULL);
}

void	push_front(t_stack **stack_head, t_stack *new_stack)
{
	update_size(*stack_head, 1);
	new_stack->nbr_elements = (*stack_head)->nbr_elements;
	new_stack->prev = (*stack_head)->prev;
	(*stack_head)->prev->next = new_stack;
	(*stack_head)->prev = new_stack;
	new_stack->next = *stack_head;
	*stack_head = new_stack;
}

// push_back for initialization of t_stack
void	push_back_new_stack(t_stack *stack_head, int new_value, int i)
{
	t_stack	*stack_back;
	t_stack	*stack_current;
	int		j;

	stack_back = malloc(sizeof(t_stack));
	if (!stack_back)
		return ;
	stack_back->index_value = -1;
	stack_current = stack_head;
	j = 1;
	while (j < i)
	{
		stack_current = stack_current->next;
		j++;
	}
	stack_head->prev = stack_back;
	stack_current->next = stack_back;
	stack_back->prev = stack_current;
	stack_back->value = new_value;
	stack_back->next = stack_head;
	stack_back->nbr_elements = stack_head->nbr_elements;
}

// when removing front, only destroy stack but not value
// value is reutilized in other stacks
// need to free all values at the end

void	free_stack(t_stack **stack)
{
	t_stack	*stack_tmp;
	int		nbr_elements;
	int		i;

	if (!(*stack))
		return ;
	nbr_elements = (*stack)->nbr_elements;
	i = 0;
	while (i < nbr_elements)
	{
		stack_tmp = *stack;
		*stack = (*stack)->next;
		if (stack_tmp)
		{
			free(stack_tmp);
			stack_tmp = NULL;
		}
		i++;
	}
}

t_stack	*init_stack(int size, char **content)
{
	t_stack	*stack_head;
	int		i;

	stack_head = malloc(sizeof(t_stack));
	if (!stack_head)
		return (NULL);
	stack_head->nbr_elements = size;
	stack_head->prev = stack_head;
	stack_head->index_value = -1;
	stack_head->value = str_to_int(content[0]);
	stack_head->next = stack_head;
	i = 1;
	while (i < size)
	{
		push_back_new_stack(stack_head, str_to_int(content[i]), i);
		i++;
	}
	return (stack_head);
}
