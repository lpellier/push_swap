/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpellier <lpellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 16:17:02 by lpellier          #+#    #+#             */
/*   Updated: 2021/11/15 16:17:29 by lpellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

int	*		str_to_int(char * string) {
	int *	ret;
	
	if (!(ret = malloc(sizeof(int))))
		return (NULL);

	*ret = 0;
	for (int i = 0; string[i]; i++) {
		*ret = *ret * 10 + (string[i] - 48);
		// printf("%c -> %d\n", string[i], *ret);
	}
	return (ret);
}
