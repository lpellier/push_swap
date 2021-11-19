/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpellier <lpellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 14:11:48 by lpellier          #+#    #+#             */
/*   Updated: 2021/11/19 18:04:01 by lpellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// take stack_a, copy it into a new stack with numbers ranging from 0 
// to stack_size
// sort new stack using radix sort
// meaning : convert new stack values to binary
// look at each bit. start with the last one
// put all 1 in a and all 0 in b
// once it's done put everything into a
// start over with the bit before
// as you're doing this, sort the actual stack at the same time

void	index_values(t_stack *stack)
{
	t_stack	*stack_current;
	int		index;
	int		j;
	int		i;
	int		min;

	index = 0;
	j = 0;
	while (j++ < stack->nbr_elements)
	{
		min = INT_MAX;
		stack_current = stack;
		i = 0;
		while (i++ < stack->nbr_elements)
		{
			if (stack_current->index_value == -1 && stack_current->value < min)
				min = stack_current->value;
			stack_current = stack_current->next;
		}
		if (stack_at(stack, min))
			stack_at(stack, min)->index_value = index;
		index++;
	}
}

void	update_size(t_stack *stack, int amount)
{
	int	size;
	int	i;

	size = stack->nbr_elements + amount;
	i = 0;
	while (i++ < size)
	{
		stack->nbr_elements = size;
		stack = stack->next;
	}
}

int	main_errors(int ac, char **av, char ***numbers)
{
	if (ac < 2 || !av[1])
		return (EXIT_FAILURE);
	*numbers = get_av(ac, av);
	if (!(*numbers) || !(**numbers))
		return (EXIT_FAILURE);
	else if (check_errors(*numbers))
	{
		fprintf(stderr, "Error\n");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

void	sorting(t_stack **stack_a, t_stack **stack_b, int size)
{
	if (!is_sorted(*stack_a))
	{
		index_values(*stack_a);
		if (size == 2)
			rotate(stack_a, 'a');
		else if (size == 3)
			sort_smaller(stack_a, 'a');
		else if (size <= 5)
			sort_small(stack_a, stack_b);
		else
			sort_stacks(stack_a, stack_b);
	}
}

void		print_stack(t_stack * stack) {
	t_stack * stack_current;

	stack_current = stack;
	// if (!stack_current) {
	// 	printf("empty stack\n\n");
	// 	return ;
	// }
	// printf("number : %d\n", stack->nbr_elements);
	for (int i = 0; i < stack->nbr_elements; i++) {
		printf("%d ", stack_current->value);
		stack_current = stack_current->next;
	}
	printf("\n");
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**numbers;
	int		size;

	if (main_errors(ac, av, &numbers))
		exit(EXIT_FAILURE);
	size = 0;
	while (numbers[size])
		size++;
	stack_a = init_stack(size, numbers);
	stack_b = NULL;
	sorting(&stack_a, &stack_b, size);
	free_stack(&stack_a);
	free_stack(&stack_b);
	exit(EXIT_SUCCESS);
}
