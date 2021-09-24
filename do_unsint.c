/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_unsint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlerma-c <dlerma-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 17:18:38 by dlerma-c          #+#    #+#             */
/*   Updated: 2021/09/24 18:39:02 by dlerma-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

static char	*numbers_to_chars(unsigned int nb, int numc)
{
	char	*str;
	int		i;

	i = numc - 1;
	str = (char *)malloc(numc + 1);
	if (str == NULL)
		return (NULL);
	while (i >= 0)
	{
		str[i] = (nb % 10) + '0';
		nb = nb / 10;
		i--;
	}
	str[numc] = '\0';
	return (str);
}

int	do_unsint(unsigned int num)
{
	int		count;
	char	*str;

	count = num_characters(num);
	str = numbers_to_chars(num, count);
	ft_putstr_fd(str, 1);
	free(str);
	return (count);
}
