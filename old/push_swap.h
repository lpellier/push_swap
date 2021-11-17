/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpellier <lpellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 23:55:52 by lpellier          #+#    #+#             */
/*   Updated: 2021/05/05 17:31:32 by lpellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef					PUSH_SWAP_H
# define				PUSH_SWAP_H

# include 				"libft/libft.h"

# define RED			"\033[31m"
# define BLUE			"\033[34m"
# define CYAN			"\x1b[36m"
# define RESET			"\x1b[0m"
# define LINE_MAX		4096

# define sa				swap(*stack_a, 1);
# define sb				swap(*stack_b, 2);
# define ss				swap_both(*stack_a, *stack_b);
# define pa				push(stack_a, stack_b, 1);
# define pb				push(stack_b, stack_a, 2);
# define ra				rotate(*stack_a, 1);
# define rb				rotate(*stack_b, 2);
# define rr				rotate_both(*stack_a, *stack_b);
# define rra			reverse_rotate(*stack_a, 1);
# define rrb			reverse_rotate(*stack_b, 2);
# define rrr			reverse_rotate_both(*stack_a, *stack_b);

# define TRUE			1
# define FALSE			0

void		swap(int *stack, int operation);
void		swap_both(int *stack_a, int *stack_b);
void		push(int *stack_receiver, int *stack_donor, int operation);
void		rotate(int *stack, int operation);
void		rotate_both(int *stack_a, int *stack_b);
void		reverse_rotate(int *stack, int operation);
void		reverse_rotate_both(int *stack_a, int *stack_b);

void					print_linked_list(void *data);
int						init_tab(int *a, char **av);
int						error_in_args(char **av);
int						is_numeric(int c);

int		int_lint(int *lint);
void    remove_int(int  *lint, int index);
void    add_int(int *dest, int key, int index);

#endif
