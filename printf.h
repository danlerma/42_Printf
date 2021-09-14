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

#ifndef PRINTF_H

# define PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

typedef struct s_percent
{
    char    c_character;
    int     d_integer;
}   t_percent;


int	ft_printf(const char *, ...);

#endif
