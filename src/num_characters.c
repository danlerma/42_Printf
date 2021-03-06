/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_characters.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlerma-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 19:50:33 by dlerma-c          #+#    #+#             */
/*   Updated: 2021/09/24 19:50:36 by dlerma-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	num_characters(unsigned int nb)
{
	int	i;

	i = 0;
	if (nb != 0)
	{
		if (nb < 0)
			i = i + 1;
		while (nb != 0)
		{
			nb = nb / 10;
			i++;
		}
	}
	else
		i = 1;
	return (i);
}
