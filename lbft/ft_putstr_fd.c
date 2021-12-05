/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlerma-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 18:01:35 by dlerma-c          #+#    #+#             */
/*   Updated: 2021/09/24 18:01:37 by dlerma-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_putstr_fd(char *s, int fd)
{
	int	i;
	int	size;

	i = 0;
	if (s != NULL)
	{
		size = ft_strlen(s);
		while (i < size)
		{
			write(fd, &s[i], 1);
			i++;
		}
	}
	return (i);
}
