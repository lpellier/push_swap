/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpellier <lpellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 14:11:48 by lpellier          #+#    #+#             */
/*   Updated: 2021/11/20 12:35:12 by lpellier         ###   ########.fr       */
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
