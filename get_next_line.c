/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 12:33:38 by aliens            #+#    #+#             */
/*   Updated: 2020/12/28 14:34:25 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*ft_error(int fd, char **line)
{
	char	*buf;

	if (fd < 0 || fd > OPEN_MAX || !line || BUFFER_SIZE < 1 ||
			!(buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1)))
		return (0);
	return (buf);
}

char	*ft_save(const char *str)
{
	size_t	i;
	char	*dst;

	if (!str)
		return (0);
	i = -1;
	while (str[++i])
		if (str[i] == '\n')
		{
			dst = ft_strdup(str + i + 1);
			free((void *)str);
			return (dst);
		}
	free((void *)str);
	return (0);
}

char	*ft_line(char *str)
{
	size_t	s;
	char	*dst;

	s = 0;
	while (str[s] && str[s] != '\n')
		s++;
	if (!(dst = ft_calloc(sizeof(char), s + 1)))
		return (NULL);
	while (s--)
		dst[s] = str[s];
	return (dst);
}

int		ft_end_line(char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = -1;
	while (str[++i])
		if (str[i] == '\n')
			return (1);
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char	*save;
	char		*buf;
	int			reader;

	if (!(buf = ft_error(fd, line)))
		return (-1);
	reader = 1;
	while (!ft_end_line(save) && reader)
	{
		if ((reader = (int)read(fd, buf, BUFFER_SIZE)) < 0)
		{
			free(buf);
			return (-1);
		}
		buf[reader] = 0;
		if (!(save = ft_strjoin(save, buf)))
			return (-1);
	}
	free(buf);
	if (!(*line = ft_line(save)) ||
			(!(save = ft_save(save)) && reader != 0))
		return (-1);
	if (reader)
		return (1);
	return (0);
}
