/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_lists.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpellier <lpellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 23:45:57 by lpellier          #+#    #+#             */
/*   Updated: 2021/03/12 14:23:24 by lpellier         ###   ########.fr       */
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
	return (res);
}

void   ft_list_push_front(t_list **begin_list, void *data)
{
	t_list   *list;
	
	if (*begin_list)
	{
		list = ft_create_elem(data);
		list->next = *begin_list;
		*begin_list = list;
	}
	else
		*begin_list = ft_create_elem(data);
}

int             ft_list_size(t_list *list)
{
	t_list   *current;
	int              i;

	i = 0;
	current = list;
	while (current)
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
		return ;
	}
	list = *begin_list;
	while (list->next)
		list = list->next;
	list->next = ft_create_elem(data);
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

void    ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	t_list   *el;

	if (!begin_list)
		return ;
	el = begin_list;
	while (el)
	{
		f(el->data);
		el = el->next;
	}
}

t_list  *ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)())
{
	t_list   *el;

	el = begin_list;
	while (el)
	{
		if (cmp(el->data, data_ref) == 0)
			return (el);
		el = el->next;
	}
	return (NULL);
}

void    ft_list_remove_if(t_list **begin_list, void *data_ref,
			int (*cmp)(), void (*free_fct)(void *))
{
	t_list   *tmp;
	t_list   *el;

	while (*begin_list && !cmp((*begin_list)->data, data_ref))
	{
		tmp = *begin_list;
		*begin_list = (*begin_list)->next;
		free_fct(tmp->data);
		free(tmp);
	}
	el = *begin_list;
	while (el && el->next)
	{
		if (!cmp(el->next->data, data_ref))
		{
			tmp = el->next;
			el->next = tmp->next;
			free_fct(tmp->data);
			free(tmp);
		}
		el = el->next;
	}
}

void    ft_list_clear(t_list *begin_list, void (*free_fct)(void *))
{
	t_list   *ptr;

	while (begin_list)
	{
		ptr = begin_list->next;
		free_fct(begin_list->data);
		free(begin_list);
		begin_list = ptr;
	}
	begin_list = NULL;
}
