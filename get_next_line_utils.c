/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 16:13:32 by aliens            #+#    #+#             */
/*   Updated: 2020/12/18 10:41:02 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	void	*dst;

	if (!(dst = malloc(sizeof(char) * (size * count))))
		return (NULL);
	ft_bzero(dst, (count * size));
	return (dst);
}

void	ft_bzero(void *s, size_t n)
{
	char *ptr;

	ptr = (char *)s;
	if (n == 0)
		return ;
	while (n--)
		ptr[n] = 0;
}
