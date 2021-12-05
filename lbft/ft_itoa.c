/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlerma-c <dlerma-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 19:00:57 by dlerma-c          #+#    #+#             */
/*   Updated: 2021/09/19 19:09:57 by dlerma-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static int	num_characters(int nb)
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

static char	*num_negative(char *str, int nb, int i)
{
	unsigned int	num;

	str[0] = '-';
	nb = nb * (-1);
	num = nb;
	while (i > 0)
	{
		str[i] = (num % 10) + '0';
		num = num / 10;
		i--;
	}
	return (str);
}

static char	*numbers(int nb, int numc)
{
	char	*str;
	int		i;

	i = numc - 1;
	str = (char *)malloc(numc + 1);
	if (str == NULL)
		return (NULL);
	if (nb >= 0)
	{
		while (i >= 0)
		{
			str[i] = (nb % 10) + '0';
			nb = nb / 10;
			i--;
		}
	}
	else
		str = num_negative(str, nb, i);
	str[numc] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	unsigned int		num_char;
	char				*str;

	num_char = num_characters(n);
	str = numbers(n, num_char);
	return (str);
}
