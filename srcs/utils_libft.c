/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_libft.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpellier <lpellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 16:04:21 by lpellier          #+#    #+#             */
/*   Updated: 2021/11/19 18:06:13 by lpellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

char	**get_av(int ac, char **av)
{
	char	**numbers;

	numbers = av + 1;
	if (ac < 2)
		return (NULL);
	else if (ac == 2)
		numbers = ft_split(av[1], ' ');
	return (numbers);
}

long long	str_to_long(char *string)
{
	long long	ret;
	int			i;
	int			negative;

	negative = 0;
	i = 0;
	ret = 0;
	if (string[i] == '-')
	{
		i++;
		negative = 1;
	}
	while (string[i]) {
		ret = ret * 10 + (string[i] - 48);
		i++;
	}
	if (negative)
		ret *= -1;
	return (ret);
}

int	str_to_int(char *string)
{
	int	ret;
	int	i;
	int	negative;

	negative = 0;
	i = 0;
	ret = 0;
	if (string[i] == '-')
	{
		i++;
		negative = 1;
	}
	while (string[i]) {
		ret = ret * 10 + (string[i] - 48);
		i++;
	}
	if (negative)
		ret *= -1;
	return (ret);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		++i;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
