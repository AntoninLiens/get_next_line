/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 18:24:03 by aliens            #+#    #+#             */
/*   Updated: 2020/12/23 18:24:07 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	size_t	s;

	s = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!(dst = (char *)ft_calloc(sizeof(char), s)))
	{
		if (s1)
			free((void *)s1);
		return (NULL);
	}
	ft_memcpy(dst, s1, ft_strlen(s1));
	ft_memcpy(dst + ft_strlen(s1), s2, ft_strlen(s2));
	free((void *)s1);
	return (dst);
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
	static char	*save[OPEN_MAX];
	char		*buf;
	int			reader;

	if (fd < 0 || fd > OPEN_MAX || !line || BUFFER_SIZE < 1 ||
			!(buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1)))
		return (-1);
	reader = 1;
	while (!ft_end_line(save[fd]) && reader)
	{
		if ((reader = (int)read(fd, buf, BUFFER_SIZE)) < 0)
		{
			free(buf);
			return (-1);
		}
		buf[reader] = 0;
		save[fd] = ft_strjoin(save[fd], buf);
	}
	free(buf);
	*line = ft_line(save[fd]);
	save[fd] = ft_save(save[fd]);
	if (reader)
		return (1);
	return (0);
}
