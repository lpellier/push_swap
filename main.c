/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpellier <lpellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 14:11:48 by lpellier          #+#    #+#             */
/*   Updated: 2021/11/19 14:40:43 by lpellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

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

void		print_index(t_stack * stack) {
	t_stack * stack_current;

	stack_current = stack;
	for (int i = 0; i < stack->nbr_elements; i++) {
		printf("%d ", stack_current->index_value);
		stack_current = stack_current->next;
	}
	printf("\n");
}

t_stack *	stack_at(t_stack * stack, int value) {
	t_stack * stack_current = stack;

	for (int i = 0; i < stack->nbr_elements; i++) {
		if (stack_current->value == value)
			return (stack_current);
		stack_current = stack_current->next;
	}
	return (NULL);
}

void		index_values(t_stack * stack) {
	int index = 0;
	for (int j = 0; j < stack->nbr_elements; j++) {
		int min = INT_MAX;
		t_stack * stack_current = stack;
		for (int i = 0; i < stack->nbr_elements; i++) {
			if (stack_current->index_value == -1 && stack_current->value < min)
				min = stack_current->value;
			stack_current = stack_current->next;
		}
		t_stack * indexed = stack_at(stack, min);
		if (indexed)
			indexed->index_value = index;
		index++;
	}
}

int			check_max_bits(t_stack * stack_a) {
	int ret = 0;
	int nbr = stack_a->nbr_elements - 1;
	while (nbr) {
		nbr /= 2;
		ret++;
	}
	return ret;
}

// putting 1 in A and 0 in B
void		sort_stacks(t_stack ** stack_a, t_stack ** stack_b) {
	int size = (*stack_a)->nbr_elements;
	int max_bits = check_max_bits(*stack_a);

	for (int i = 0; i < max_bits; i++) {
		for (int j = 0; j < size; j++) {
			int num = (*stack_a)->index_value;
			if (((num >> i) & 1) == 1)
				rotate(stack_a, 'a');
			else
				push(stack_b, stack_a, 'b');
		}
		int size_b = (*stack_b)->nbr_elements;
		for (int j = 0; j < size_b; j++)
			push(stack_a, stack_b, 'a');
	}
}

int			smallest(t_stack * stack ) {
	int min = INT_MAX;
	t_stack * stack_current = stack;
	for (int i = 0; i < stack->nbr_elements; i++) {
		if (stack_current->index_value < min)
			min = stack_current->index_value;
		stack_current = stack_current->next;
	}
	return (min);
}

int			biggest(t_stack * stack ) {
	int max = INT_MIN;
	t_stack * stack_current = stack;
	for (int i = 0; i < stack->nbr_elements; i++) {
		if (stack_current->index_value > max)
			max = stack_current->index_value;
		stack_current = stack_current->next;
	}
	return (max);
}

int			closest_minus(t_stack * stack, int value) {
	if (value == 0)
		return (-1);
	int closest = value - 1;
	for (int i = 0; i < stack->nbr_elements; i++) {
		if (stack->index_value == closest)
			return (closest);
		stack = stack->next;
	}
	return (closest_minus(stack, value - 1));
}

int			closest_plus(t_stack * stack, int value, int max_elem) {
	if (value == max_elem)
		return (-1);
	int closest = value + 1;
	for (int i = 0; i < stack->nbr_elements; i++) {
		if (stack->index_value == closest)
			return (closest);
		stack = stack->next;
	}
	return (closest_plus(stack, value + 1, max_elem));
}

void		sort_smaller(t_stack ** stack, char c) {
	int	small = smallest(*stack);
	if ((*stack)->index_value == small) {
		swap(stack, c);
		rotate(stack, c);
	}
	else if ((*stack)->index_value == closest_plus(*stack, small, 3)) {
		if ((*stack)->next->index_value == small)
			swap(stack, c);
		else if ((*stack)->next->index_value == biggest(*stack))
			reverse_rotate(stack, c);
	}
	else if ((*stack)->index_value == biggest(*stack)) {
		if ((*stack)->next->index_value == closest_plus(*stack, small, 3)) {
			swap(stack, c);
			reverse_rotate(stack, c);
		}
		else if ((*stack)->next->index_value == small) 
			rotate(stack, c);
	}
}

int			is_sorted(t_stack * stack) {
	int size = stack->nbr_elements;

	for (int i = 0; i < size - 1; i++) {
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void		sort_small(t_stack ** stack_a, t_stack ** stack_b) {
	int max_elem = (*stack_a)->nbr_elements;
	while ((*stack_a)->nbr_elements > 3)
		push(stack_b, stack_a, 'b');
	if (!is_sorted(*stack_a))
		sort_smaller(stack_a, 'a');
	// print_stack(*stack_a);
	while (*stack_b) {
		// printf("%d : closest -> %d | closest -> %d \n", (*stack_b)->index_value, closest_minus(*stack_a, (*stack_b)->index_value), closest_plus(*stack_a, (*stack_b)->index_value, max_elem));
		// print_stack(*stack_a);
		if (((*stack_b)->index_value > biggest(*stack_a) && (*stack_a)->prev->index_value == biggest(*stack_a))|| \
			((*stack_b)->index_value < smallest(*stack_a) && (*stack_a)->index_value == smallest(*stack_a)) || \
			((*stack_a)->prev->index_value == closest_minus(*stack_a, (*stack_b)->index_value) && (*stack_a)->index_value == closest_plus(*stack_a, (*stack_b)->index_value, max_elem)))
			push(stack_a, stack_b, 'a');
		else {
			reverse_rotate(stack_a, 'z');
			if (((*stack_b)->index_value > biggest(*stack_a) && (*stack_a)->prev->index_value == biggest(*stack_a))|| \
				((*stack_b)->index_value < smallest(*stack_a) && (*stack_a)->index_value == smallest(*stack_a)) || \
				((*stack_a)->prev->index_value == closest_minus(*stack_a, (*stack_b)->index_value) && (*stack_a)->index_value == closest_plus(*stack_a, (*stack_b)->index_value, max_elem))) {
					rotate(stack_a, 'z');
					reverse_rotate(stack_a, 'a');
			}
			else {
				rotate(stack_a, 'z');
				rotate(stack_a, 'a');
			}
		}
	}
	while (!is_sorted(*stack_a)) {
		reverse_rotate(stack_a, 'z');
		if (is_sorted(*stack_a)) {
			rotate(stack_a, 'z');
			reverse_rotate(stack_a, 'a');
		}
		else {
			rotate(stack_a, 'z');
			rotate(stack_a, 'a');
		}
	}
}

char **		get_av(int ac, char ** av) {
	char ** numbers = av + 1;
	if (ac < 2) {
		return (NULL);
	}
	else if (ac == 2) {
		numbers = ft_split(av[1], ' ');
	}
	return (numbers);
}

long long		str_to_long(char * string) {
	long long	ret;
	int i = 0;
	int negative = 0;
	
	ret = 0;
	if (string[i] == '-') {
		i++;
		negative = 1;
	}
	for (; string[i]; i++) {
		ret = ret * 10 + (string[i] - 48);
	}
	if (negative)
		ret *= -1;
	return (ret);
}

int			bigger_than_int(char * nbr) {
	long long cmp = str_to_long(nbr);
	if (cmp < INT_MIN || cmp > INT_MAX)
		return (1);
	return (0);
}

int			not_numerical(char * nbr) {
	int i = 0;
	if (nbr[i] && nbr[i] == '-')
		i++;
	if (i > 0 && !nbr[i])
		return (1);
	while (nbr[i]) {
		if (nbr[i] < '0' || nbr[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

int			duplicates(char ** numbers) {
	int size = 0;
	while (numbers[size])
		size++;
	if (size < 2)
		return (0);
	for (int i = 0; numbers[i]; i++) {
		for (int j = i + 1; numbers[j]; j++) {
			if (!ft_strcmp(numbers[i], numbers[j]))
				return (1);
		}
	}
	return (0);
}

int			check_errors(char ** numbers) {
	if (duplicates(numbers))
		return (1);
	for (int i = 0; numbers[i]; i++) {
		if (bigger_than_int(numbers[i]) || not_numerical(numbers[i]))
			return (1);
	}
	return (0);
}

// take stack_a, copy it into a new stack with numbers ranging from 0 to stack_size
// sort new stack using radix sort
// meaning : convert new stack values to binary
// look at each bit. start with the last one
// put all 1 in a and all 0 in b
// once it's done put everything into a
// start over with the bit before
// as you're doing this, sort the actual stack at the same time

int			main(int ac, char ** av) {
	t_stack *	stack_a;
	t_stack *	stack_b;

	if (ac < 2 || !av[1])
		exit(EXIT_FAILURE);
	char ** numbers = get_av(ac, av);
	if (!numbers || !(*numbers))
		exit(EXIT_FAILURE);
	else if (check_errors(numbers)) {
		fprintf(stderr, "Error\n");
		exit(EXIT_FAILURE);
	}
	int size = 0;
	while (numbers[size])
		size++;
	stack_a = init_stack(size, numbers);
	stack_b = NULL;
	// need to implement small stack (< 5) sorting
	if (!is_sorted(stack_a)) {
		index_values(stack_a);
		if (size == 2)
			rotate(&stack_a, 'a');
		else if (size == 3)
			sort_smaller(&stack_a, 'a');
		else if (size <= 5)
			sort_small(&stack_a, &stack_b);
		else
			sort_stacks(&stack_a, &stack_b);
	}
	free_stack(&stack_a);
	free_stack(&stack_b);
	exit(EXIT_SUCCESS);
}
