/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpellier <lpellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 18:13:15 by lpellier          #+#    #+#             */
/*   Updated: 2021/11/20 12:23:39 by lpellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"
#include "get_next_line/get_next_line.h"

int	line_error(char *line)
{
	if (ft_strcmp(line, "sa") && ft_strcmp(line, "sb") && \
		ft_strcmp(line, "ss") && ft_strcmp(line, "pa") && \
		ft_strcmp(line, "pb") && ft_strcmp(line, "ra") && \
		ft_strcmp(line, "rb") && ft_strcmp(line, "rr") && \
		ft_strcmp(line, "rra") && ft_strcmp(line, "rrb") && \
		ft_strcmp(line, "rrr"))
		return (1);
	return (0);
}

void	respond_cmd(t_stack ** stack_a, t_stack ** stack_b, char * cmd) {
	if (!ft_strcmp(cmd, "sa"))
		swap(stack_a, 'z');
	else if (!ft_strcmp(cmd, "sb"))
		swap(stack_b, 'z');
	else if (!ft_strcmp(cmd, "ss"))
		sswap(stack_a, stack_b);
	else if (!ft_strcmp(cmd, "pa"))
		push(stack_a, stack_b, 'z');
	else if (!ft_strcmp(cmd, "pb"))
		push(stack_b, stack_a, 'z');
	else if (!ft_strcmp(cmd, "ra"))
		rotate(stack_a, 'z');
	else if (!ft_strcmp(cmd, "rb"))
		rotate(stack_b, 'z');
	else if (!ft_strcmp(cmd, "rr"))
		rrotate(stack_a, stack_b);
	else if (!ft_strcmp(cmd, "rra"))
		reverse_rotate(stack_a, 'z');
	else if (!ft_strcmp(cmd, "rrb"))
		reverse_rotate(stack_b, 'z');
	else if (!ft_strcmp(cmd, "rrr"))
		rreverse_rotate(stack_a, stack_b);
}

int main(int ac, char **av)
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

	char *line = NULL;
	while (get_next_line(0, &line)) {
		if (line_error(line)) {
			free(line);
			line = NULL;
			free_stack(&stack_a);
			free_stack(&stack_b);
			printf("arg error\n");
			exit(EXIT_FAILURE);
		}
		respond_cmd(&stack_a, &stack_b, line);
	}
	if (is_sorted(stack_a))
		printf("OK\n");
	else
		printf("KO\n");
	exit(EXIT_SUCCESS);
}
