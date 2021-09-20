#include"libft.h"

int	ft_putstr_fd(char *s, int fd)
{
	int	i;
	int	size;

	i = 0;
	if (s != NULL)
	{
		size = ft_strlen(s);
		while (i < size)
		{
			write(fd, &s[i], 1);
			i++;
		}
	}
	return (i);
}
