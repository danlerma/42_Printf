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

	i = 0;
	str = ft_calloc(sizeof(char), 1 + 1);
	while (i < nbr)
		i++;
	ft_memcpy(str, base + i, 1);
	return (str);
}

static char	*cal_base(unsigned int num, char *base, int num_char)
{
	char			*str;
	char			*aux;
	unsigned int	cal;

	str = ft_calloc(sizeof(char), num_char + 1);
	cal = num;
	while (cal > 16 )
	{
		cal = num % 16;
		aux = str;
		str = ft_strjoin(aux, conversion_number_char(cal, base));
		free(aux);
		cal = num / 16;
		num = cal;
	}
	aux = str;
	str = ft_strjoin(aux, conversion_number_char(num, base));
	free(aux);
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
		num = ft_atoi(str);
		free(str);
	}
	num_char = num_characters(num);
	str = cal_base(num, base, num_char);
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
