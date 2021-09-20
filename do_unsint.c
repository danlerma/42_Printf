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

int	str_to_unint(unsigned int num)
{
	int		count;
	char	*str;

	count = num_characters(num);
	str = numbers_to_chars(num, count);
    ft_putstr_fd(str, 1);
    free(str);
	return (count);
}
