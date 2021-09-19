/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlerma-c <dlerma-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 20:30:24 by dlerma-c          #+#    #+#             */
/*   Updated: 2021/09/19 18:42:18 by dlerma-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_percent(const char *str, va_list ap)
{
	int			i;
	int			count;
	t_percent	per;

	i = 0;
	count = 0;
	while (str[i])
	{
		//caracter (c)
		if (str[i] == '%' && str[i + 1] == 'c')
		{
			per.c_character = va_arg(ap, int);
			ft_putchar_fd(per.c_character, 1);
			count++;
			i++;
		}
		//string (s)
		else if (str[i] == '%' && str[i + 1] == 's')
		{
			per.s_string = va_arg(ap, char *);
			if (per.s_string == '\0')
				count += ft_putstr("(null)");
			else
				count += ft_putstr(per.s_string);
			i++;
		}
		//int (d)
		else if (str[i] == '%' && str[i + 1] == 'd')
		{
			per.d_integer = va_arg(ap, int);
			ft_putnbr_fd(per.d_integer, 1);
			count++;
			i++;
		}
		//si no hay nada
		else if (str[i] != '%')
		{
			ft_putchar_fd(str[i], 1);
			count++;
		}
		i++;
	}
	return (count);
}

int	ft_printf(const char *str, ...)
{
    va_list	ap;
	int		result;

	va_start(ap, str);
	result = check_percent(str, ap);
	va_end(ap);
	return (result);
}
