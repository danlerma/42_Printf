#include"ft_printf.h"

static int	num_characters(unsigned int nb)
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

static char	*conversion_number_char(unsigned int nbr, char *base)
{
	char			*str;
	unsigned int	i;
	char			*aux;

	i = 0;
	str = ft_calloc(sizeof(char), 1 + 1);
	if (str == NULL)
		return (NULL);
	while (i < nbr)
		i++;
	aux = str;
	ft_memcpy(str, base + i, 1);
	str[1] = '\0';
	return (str);
}

static char	*cal_base(unsigned int num, char *base, int num_char)
{
	char			*str;
	char			*aux;
	char			*str2;
	unsigned int	cal;

	str = ft_calloc(sizeof(char), num_char + 1);
	if (str == NULL)
		return (NULL);
	cal = num;
	while (cal > 16 )
	{
		cal = num % 16;
		aux = str;
		str2 = conversion_number_char(cal, base);
		if (str2 == NULL)
			return (NULL);
		str = ft_strjoin(str, str2);
		free(str2);
		free(aux);
		if (str == NULL)
			return (NULL);
		cal = num / 16;
		num = cal;
	}
	aux = str;
	str2 = conversion_number_char(cal, base);
	if (str2 == NULL)
		return (NULL);
	str = ft_strjoin(str, str2);
	free(str2);
	free(aux);
	if (str == NULL)
		return (NULL);
	return (str);
}

int	ft_itoa_base(unsigned int num, char *base)
{
	int		num_char;
	char	*str;
	int		count;

	if (num < 0)
	{
		str = ft_itoa(num);
		if (str == NULL)
			return (0);
		num = ft_atoi(str);
		free(str);
	}
	num_char = num_characters(num);
	str = cal_base(num, base, num_char);
	if (str == NULL)
		return (0);
	num_char = ft_strlen(str);
	count = num_char;
	while (num_char >= 0)
	{
		printf("%c", str[num_char]);
		num_char--;
	}
	free(str);
	return (count);
}
