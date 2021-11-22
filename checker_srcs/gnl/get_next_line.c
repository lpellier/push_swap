/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpellier <lpellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 12:36:26 by lpellier          #+#    #+#             */
/*   Updated: 2021/11/22 12:51:46 by lpellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	ft_bufflen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	return (i);
}

char	*ft_alloc(size_t size)
{
	char	*s;
	char	*ptr;

	s = (char *)malloc(sizeof(char) * (size + 1));
	if (s == NULL)
		return (NULL);
	size = size + 1;
	ptr = s;
	while (size-- > 0)
		*ptr++ = '\0';
	return (s);
}

static char	*ft_save(char *lines, size_t *a)
{
	if (ft_strchr(lines, '\n'))
	{
		ft_strcpy(lines, ft_strchr(lines, '\n') + 1);
		return (lines);
	}
	if (ft_bufflen(lines) > 0)
	{
		ft_strcpy(lines, ft_strchr(lines, '\0'));
		*a = 0;
		return (lines);
	}
	return (NULL);
}

void	read_loop(char **lines, int fd, char buf[BUFFER_SIZE + 1])
{
	char	*line_tmp;
	int		end_buff;

	while (ft_strchr(*lines, '\n') == NULL)
	{
		end_buff = read(fd, buf, BUFFER_SIZE);
		if (!(end_buff > 0))
			break ;
		buf[end_buff] = '\0';
		line_tmp = *lines;
		*lines = ft_strjoin(line_tmp, buf);
		free(line_tmp);
	}
}

int	get_next_line(int fd, char **line)
{
	static char		buf[BUFFER_SIZE + 1];
	static char		*lines = NULL;
	size_t			a;

	a = 1;
	if (fd < 0 || BUFFER_SIZE < 1 || line == NULL || read(fd, buf, 0) < 0)
		return (-1);
	if (lines == NULL)
	{
		lines = ft_alloc(0);
		if (lines == NULL)
			return (-1);
	}
	read_loop(&lines, fd, buf);
	*line = ft_substr(lines, 0, ft_bufflen(lines));
	if ((ft_save(lines, &a) != NULL) && a == 1)
		return (1);
	free(lines);
	lines = NULL;
	return (0);
}
