/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_lists.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpellier <lpellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 23:45:57 by lpellier          #+#    #+#             */
/*   Updated: 2021/05/05 12:46:18 by lpellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list  *ft_create_elem(void *data)
{
	t_list   *res;

	if (!(res = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	res->data = data;
	res->next = NULL;
	res->prev = NULL;
	return (res);
}

void   ft_list_push_front(t_list **begin_list, void *data)
{
	t_list   *list;
	
	if (*begin_list)
	{
		list = ft_create_elem(data);
		list->next = *begin_list;
		list->prev = ft_list_at(*begin_list, ft_list_size(*begin_list));
		*begin_list = list;
	}
	else
	{
		*begin_list = ft_create_elem(data);
		(*begin_list)->next = *begin_list;
		(*begin_list)->prev = *begin_list;
	}
}

int             ft_list_size(t_list *list)
{
	t_list   *current;
	int              i;

	i = 0;
	current = list;
	while (current && current->data && current->next != list)
	{
		i++;
		current = current->next;
	}
	return (i);
}

void    ft_list_push_back(t_list **begin_list, void *data)
{
	t_list   *list;

	if (!(*begin_list))
	{
		*begin_list = ft_create_elem(data);
		(*begin_list)->next = *begin_list;
		(*begin_list)->prev = *begin_list;
	}
	else
	{
		list = *begin_list;
		while (list->next != *begin_list)
			list = list->next;
		list->next = ft_create_elem(data);
		list->next->next = *begin_list;
		list->next->prev = list;
	}
}

t_list  *ft_list_at(t_list *begin_list, unsigned int nbr)
{
	t_list              *list;
	unsigned int     i;

	i = 0;
	list = begin_list;
	while (i < nbr)
	{
		if (!list)
			return (NULL);
		list = list->next;
		i++;
	}
	return (list);
}

t_list  *ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)())
{
	t_list   *el;

	el = begin_list;
	while (el->next != begin_list)
	{
		if (cmp(el->data, data_ref) == 0)
			return (el);
		el = el->next;
	}
	return (NULL);
}

void    ft_list_clear(t_list *begin_list, void (*free_fct)(void *))
{
	t_list	*list;
	t_list   *ptr;

	list = begin_list;
	while (list->next != begin_list)
	{
		ptr = list->next;
		free_fct(list->data);
		free(list);
		list = ptr;
	}
	list = NULL;
}
