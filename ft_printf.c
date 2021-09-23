/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlerma-c <dlerma-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 20:30:24 by dlerma-c          #+#    #+#             */
/*   Updated: 2021/09/23 18:42:58 by dlerma-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_percent(const char *str, va_list ap, int i)
{
	int			count;
	int			y;
	t_percent	per;

	count = 0;
	y = 0;
	if (str[i + 1] == 'c')
		count = ft_putchar_fd(va_arg(ap, int), 1);
	//string (s)
	else if (str[i + 1] == 's')
	{
		per.s_string = va_arg(ap, char *);
		if (per.s_string == '\0')
			count += ft_putstr("(null)");
		else
			count += ft_putstr(per.s_string);
	}
	//int (d) int (i)
	else if (str[i + 1] == 'd' || str[i + 1] == 'i')
	{
		per.s_string = ft_itoa(va_arg(ap, int));
		count += ft_putstr(per.s_string);
		free(per.s_string);
	}
	//int (u)
	else if (str[i + 1] == 'u')
		count = str_to_unint(va_arg(ap, unsigned int));
	//char (p)
	else if (str[i + 1] == 'p')
	{
		count = ft_putchar_fd('p', 1);
	}
	else if (str[i + 1] == 'x')
	{
		count = ft_itoa_base(va_arg(ap, unsigned int), "0123456789abcdef");
	}
	else if (str[i + 1] == 'X')
	{
		count = ft_itoa_base(va_arg(ap, unsigned int), "0123456789ABCDEF");
	}
	else if (str[i + 1] == '%')
		count = ft_putchar_fd('%', 1);
	return (count);
}

static int	check_normal_characters(char str)
{
	int count;

	count = 0;
	count = ft_putchar_fd(str, 1);
	return (count);
}

int	ft_printf(const char *str, ...)
{
    va_list	ap;
	int		result;
	int		i;

	i = 0;
	result = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			result += check_percent(str, ap, i);
			i++;
		}
		else
			result += check_normal_characters(str[i]);
		i++;
	}
	va_end(ap);
	return (result);
}
