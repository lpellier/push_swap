/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpellier <lpellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 23:55:52 by lpellier          #+#    #+#             */
/*   Updated: 2021/03/13 15:23:32 by lpellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef					PUSH_SWAP_H
# define				PUSH_SWAP_H

# include 				"libft/libft.h"

# define RED			"\033[31m"
# define BLUE			"\033[34m"
# define CYAN			"\x1b[36m"
# define RESET			"\x1b[0m"

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

typedef struct s_list
{
		struct s_list	*next;
		void			*data;
}						t_list;

void					swap(t_list *stack, int operation);
void					swap_both(t_list *stack_a, t_list *stack_b);
void					push(t_list **stack_receiver, t_list **stack_donor, int operation);
void					rotate(t_list *stack, int operation);
void					rotate_both(t_list *stack_a, t_list *stack_b);
void					reverse_rotate(t_list *stack, int operation);
void					reverse_rotate_both(t_list *stack_a, t_list *stack_b);

int						sort(t_list **stack_a, t_list **stack_b);

void					free_stack(void *data);
void					print_linked_list(void *data);
int						init_linked_list(t_list *a, char **av);
int						error_in_args(char **av);
int						is_numeric(int c);

t_list					*ft_create_elem(void *data);
t_list					*ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)());
t_list					*ft_list_at(t_list *begin_list, unsigned int nbr);
int						ft_list_size(t_list *list);
void					ft_list_push_front(t_list **begin_list, void *data);
void					ft_list_push_back(t_list **begin_list, void *data);
void					ft_list_clear(t_list *begin_list, void (*free_fct)(void *));
void					ft_list_foreach(t_list *begin_list, void (*f)(void *));
void					ft_list_remove_if(t_list **begin_list, void *data_ref,
							int (*cmp)(), void (*free_fct)(void *));

#endif
