/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 12:33:38 by aliens            #+#    #+#             */
/*   Updated: 2020/12/22 10:51:21 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	if ((char)c == 0)
		return ((char *)s + ft_strlen(s));
	i = -1;
	while (s[++i])
		if (s[i] == (char)c)
			return ((char *)s + i);
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	size_t	s;

	s = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!(dst = (char *)ft_calloc(sizeof(char), s)))
		return (NULL);
	ft_memcpy(dst, s1, ft_strlen(s1));
	ft_memcpy(dst + ft_strlen(s1), s2, ft_strlen(s2));
	return (dst);
}

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	i;

	i = -1;
	if (!(str = (char *)ft_calloc(sizeof(char), ft_strlen(s1) + 1)))
		return (NULL);
	while (s1[++i])
		str[i] = s1[i];
	return (str);
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
	size_t		size;
	char		buf[BUFFER_SIZE + 1];

	while ((size = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[size] = 0;
		*line = ft_strjoin(save, buf);
		if (ft_end_line(save))
		{
			*line = ft_line(save);
			save = ft_strdup(ft_strchr(buf, '\n') + 1);
		}
		return (1);
	}
	return (0);
}
