/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlerma-c <dlerma-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 20:30:24 by dlerma-c          #+#    #+#             */
/*   Updated: 2021/09/24 22:54:27 by dlerma-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_number(va_list ap, const char *str, int i)
{
	int			count;
	t_percent	per;

	count = 0;
	if (str[i + 1] == 'd' || str[i + 1] == 'i')
	{
		per.s_string = ft_itoa(va_arg(ap, int));
		count += ft_putstr_fd(per.s_string, 1);
		free(per.s_string);
	}
	else if (str[i + 1] == 'u')
		count = do_unsint(va_arg(ap, unsigned int));
	else if (str[i + 1] == 'x')
		count = ft_itoa_base(va_arg(ap, int), "0123456789abcdef");
	else if (str[i + 1] == 'X')
		count = ft_itoa_base(va_arg(ap, int), "0123456789ABCDEF");
	return (count);
}

static int	check_percent(const char *str, va_list ap, int i)
{
	int			count;
	t_percent	per;

	count = 0;
	count = check_number(ap, str, i);
	if (str[i + 1] == 'c')
		count = ft_putchar_fd(va_arg(ap, int), 1);
	else if (str[i + 1] == 's')
	{
		per.s_string = va_arg(ap, char *);
		if (per.s_string == '\0')
			count += ft_putstr_fd("(null)", 1);
		else
			count += ft_putstr_fd(per.s_string, 1);
	}
	else if (str[i + 1] == 'p')
	{
		ft_putstr_fd("0x", 1);
		count = pointer_change(va_arg(ap, void *), "0123456789abcdef");
		count = count + 2;
	}
	else if (str[i + 1] == '%')
		count = ft_putchar_fd('%', 1);
	return (count);
}

static int	check_normal_characters(char str)
{
	int	count;

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
		if (str[i] == '\0')
			return (result);
		i++;
	}
	va_end(ap);
	return (result);
}
