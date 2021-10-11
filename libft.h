/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlerma-c <dlerma-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 18:00:06 by dlerma-c          #+#    #+#             */
/*   Updated: 2021/10/11 13:32:07 by dlerma-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>

# define UPPER_HEX "0123456789ABCDEF"
# define LOWER_HEX "0123456789abcdef"

int		ft_putchar_fd(char c, int fd);
int		ft_putstr(char *str);
char	*ft_itoa(int n);
int     ft_atoi(const char *str);
int		ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *c);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_memcpy(void *dst, const void *src, size_t n);

#endif
