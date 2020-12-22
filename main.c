/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 16:26:59 by aliens            #+#    #+#             */
/*   Updated: 2020/12/22 16:40:24 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main(void)
{
	char	*str;
	int	fd;
	int	i;

	i = 50;
	if (!(fd = open("test.txt", O_RDONLY)))
		return (-1);
	str = NULL;
	while (i--)
	{
		get_next_line(fd, &str);
		printf("%s\n", str);
	}
	close(fd);
	return (0);
}
