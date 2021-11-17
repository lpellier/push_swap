/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpellier <lpellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 14:11:48 by lpellier          #+#    #+#             */
/*   Updated: 2021/11/15 18:14:42 by lpellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void		print_stack(t_stack * stack) {
	t_stack * stack_current;

	stack_current = stack;
	printf("number : %d\n", *(stack->nbr_elements));
	for (int i = 0; i < *(stack->nbr_elements); i++) {
		if (stack_current->value)
			printf("%d ", *(stack_current->value));
		else
			printf(". ");
		stack_current = stack_current->next;
	}
	printf("\n");
}

int			main(int ac, char ** av) {
	t_stack *	stack_a;
	t_stack *	stack_b;

	// Need to change that, stacks can be empty
	if (ac < 3) {
		printf("Not enough numbers in the stack\n");
		exit(EXIT_FAILURE);
	}

	// ac - 1 is number of elements in stack a
	// av + 1 is those numbers as strings
	stack_a = init_stack(ac - 1, av + 1);
	stack_b = init_stack(1, NULL);

	print_stack(stack_a);
	print_stack(stack_b);

	rotate(&stack_a);
	reverse_rotate(&stack_a);

	print_stack(stack_a);
	print_stack(stack_b);

	free_stack(&stack_a);
	free_stack(&stack_b);
	exit(EXIT_SUCCESS);
}
