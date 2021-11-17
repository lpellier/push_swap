/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpellier <lpellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 16:17:05 by lpellier          #+#    #+#             */
/*   Updated: 2021/11/15 17:53:06 by lpellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void		push_front(t_stack ** stack_head, int * new_value) {
	t_stack *	stack_front;
	
	if (!(stack_front = malloc(sizeof(t_stack))))
		return;
		
	stack_front->nbr_elements = (*stack_head)->nbr_elements;
	stack_front->prev = (*stack_head)->prev;
	stack_front->value = new_value;
	*((*stack_head)->nbr_elements) += 1;
	if (!(*stack_head) || !(*stack_head)->value) 
		stack_front->next = stack_front;
	else 
		stack_front->next = *stack_head;
	*stack_head = stack_front;
}

// push_back for initialization of t_stack
void		push_back(t_stack * stack_head, int * new_value) {
	t_stack * stack_back;
	t_stack * stack_current;

	if (!stack_head->value) {
		stack_head->value = new_value;
		return ;
	}
	
	if (!(stack_back = malloc(sizeof(t_stack))))
		return;

	stack_back->nbr_elements = stack_head->nbr_elements;
	stack_current = stack_head;
	for (int i = 1; i < *(stack_head->nbr_elements); i++)
		stack_current = stack_current->next;

	stack_head->prev = stack_back;
	stack_current->next = stack_back;

	stack_back->prev = stack_current;
	stack_back->value = new_value;
	stack_back->next = stack_head;
	*(stack_head->nbr_elements) += 1;
}

// when removing front, only destroy stack but not value
// value is reutilized in other stacks
// need to free all values at the end
void		destroy_stack(t_stack * stack, int destroy) {
	if (stack) {
		if (destroy && stack->value) {
			free(stack->value);
			stack->value = NULL;
		}
		free(stack);
		stack = NULL;
	}
}

void		remove_front(t_stack ** stack_head, int destroy) {
	t_stack *	stack_tmp;

	if (!destroy)
		*(*stack_head)->nbr_elements -= 1;
	if ((*stack_head)->next) {
		stack_tmp = *stack_head;
		*stack_head = (*stack_head)->next;
		destroy_stack(stack_tmp, destroy);
	}
	else if (!(*stack_head)->next && !destroy)
		(*stack_head)->value = NULL;
	else
		destroy_stack(*stack_head, destroy);
}

void		free_stack(t_stack ** stack) {
	t_stack *	stack_tmp;
	int			nbr_elements;

	nbr_elements = *((*stack)->nbr_elements);
	if ((*stack)->nbr_elements) {
		free((*stack)->nbr_elements);
		(*stack)->nbr_elements = NULL;
	}
	for (int i = 0; i < nbr_elements; i++)  {
		stack_tmp = *stack;
		*stack = (*stack)->next;
		destroy_stack(stack_tmp, 1);
	}
}

t_stack *	init_stack(int size, char ** content) {
	t_stack *	stack_head;

	if (!(stack_head = malloc(sizeof(t_stack))))
		return (NULL);

	if (!(stack_head->nbr_elements = malloc(sizeof(int))))
		return (NULL);
	*(stack_head->nbr_elements) = 1;
	stack_head->prev = stack_head;
	if (content != NULL)
		stack_head->value = str_to_int(content[0]);
	else {
		stack_head->value = NULL;
		*(stack_head->nbr_elements) = 0;
	}
	stack_head->next = stack_head;

	for (int i = 1; i < size; i++)
		push_back(stack_head, str_to_int(content[i]));

	return (stack_head);
}
