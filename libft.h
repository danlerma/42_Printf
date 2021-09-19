#ifndef LIBFT_H

# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>

int	    ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
int	    ft_putstr(char *str);
char	*ft_itoa(int n);
int     ft_atoi(const char *str);

#endif
