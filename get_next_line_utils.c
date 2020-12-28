/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 16:13:32 by aliens            #+#    #+#             */
/*   Updated: 2020/12/28 14:45:35 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

size_t	ft_strlen(const char *a)
{
	size_t	i;

	if (!a)
		return (0);
	i = 0;
	while (a[i])
		i++;
	return (i);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*ptrsrc;
	char	*ptrdst;

	ptrdst = (char *)dst;
	ptrsrc = (char *)src;
	if (dst == NULL && src == NULL)
		return (dst);
	while (n--)
		ptrdst[n] = ptrsrc[n];
	return (dst);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*dst;
	size_t	i;

	if (!(dst = (char *)malloc(sizeof(char) * (size * count))))
		return (NULL);
	i = -1;
	while (++i < size * count)
		dst[i] = 0;
	return (dst);
}

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
