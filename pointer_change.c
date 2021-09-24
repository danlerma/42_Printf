/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer_change.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlerma-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 19:50:13 by dlerma-c          #+#    #+#             */
/*   Updated: 2021/09/24 19:50:17 by dlerma-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

static char	*conversion_number_char(uintptr_t nbr, char *base)
{
	char		*str;
	uintptr_t	i;
	char		*aux;

	i = 0;
	str = ft_calloc(sizeof(char), 1 + 1);
	if (str == NULL)
		return (NULL);
	while (i < nbr)
		i++;
	aux = str;
	ft_memcpy(str, base + i, 1);
	return (str);
}

static char	*join_the_digits(char **str, uintptr_t cal, char *base)
{
	char	*aux;
	char	*str2;

	aux = *str;
	str2 = conversion_number_char(cal, base);
	if (str2 == NULL)
		return (NULL);
	*str = ft_strjoin(*str, str2);
	free(str2);
	free(aux);
	if (*str == NULL)
		return (NULL);
	return (*str);
}

static char	*cal_base(uintptr_t num, char *base, int num_char)
{
	char		*str;
	uintptr_t	cal;

	str = ft_calloc(sizeof(char), num_char + 1);
	if (str == NULL)
		return (NULL);
	cal = num;
	while (cal >= 16 )
	{
		cal = num % 16;
		str = join_the_digits(&str, cal, base);
		cal = num / 16;
		num = cal;
	}
	str = join_the_digits(&str, cal, base);
	return (str);
}

static uintptr_t	check_negative(uintptr_t num)
{
	char	*str;

	str = ft_itoa(num);
	if (str == NULL)
		return (0);
	num = ft_atoi(str);
	free(str);
	return (num);
}

int	pointer_change(void *nbr, char *base)
{
	int			num_char;
	char		*str;
	int			count;
	uintptr_t	num;

	num = (uintptr_t)nbr;
	if (num < 0)
		num = check_negative(num);
	num_char = num_characters(num);
	str = cal_base(num, base, num_char);
	if (str == NULL)
		return (0);
	num_char = ft_strlen(str);
	count = num_char;
	num_char--;
	while (num_char >= 0)
	{
		ft_putchar_fd(str[num_char], 1);
		num_char--;
	}
	free(str);
	return (count);
}
