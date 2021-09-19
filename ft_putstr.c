#include"libft.h"

int	ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
		i++;
	}
	return (i);
}
