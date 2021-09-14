/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlerma-c <dlerma-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 20:30:24 by dlerma-c          #+#    #+#             */
/*   Updated: 2021/09/14 18:42:21 by dlerma-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	check_percent(const char *str, va_list ap)
{
	int			i;
	t_percent	per;
	
	i = 0;
	while (str[i])
	{
		//caracter (c)
		if (str[i] == '%' && str[i + 1] == 'c')
		{
			per.c_character = va_arg(ap, int);
			printf("CARACTER: %c\n", per.c_character);
		}
		//int (d)
		if (str[i] == '%' && str[i + 1] == 'd')
		{
			per.d_integer = va_arg(ap, int);
			printf("CARACTER: %c\n", per.d_integer);
		}
		i++;
	}
}

int	ft_printf(const char *str, ...)
{
    va_list	ap;

	va_start(ap, str);
	check_percent(str, ap);
	va_end(ap);
	return (0);
}
