/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlerma-c <dlerma-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 20:43:03 by dlerma-c          #+#    #+#             */
/*   Updated: 2021/09/13 20:54:44 by dlerma-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include "../lbft/libft.h"
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

typedef struct s_percent
{
	char			c_character;
	int				d_integer;
	char			*s_string;
	unsigned int	u_integer;
}	t_percent;

int	ft_printf(const char *str, ...);

int	ft_itoa_base(unsigned int num, char *base);
int	do_unsint(unsigned int num);
int	num_characters(unsigned int nb);
int	pointer_change(void *num, char *base);

#endif
