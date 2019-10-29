<<<<<<< HEAD
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclaudel <mclaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 16:57:35 by mclaudel          #+#    #+#             */
/*   Updated: 2019/10/22 17:18:09 by mclaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

/*
** printf but with more style
**
** @param	s  pointer to string
** @param	...  arguments to print
** @return	int
*/

int	ft_printf(const char *s, ...)
{
	size_t printed;
	size_t i;
	size_t l;

	if (!s)
		return (0);
	i = 0;
	printed = 0;
	while (s[i])
	{
		if (s[i] == '%' && (l = ft_isflag(s + i)) != 0)
		{
			i += l;
			printed += ft_handleflag(s + i);
		}
		else
		{
			write(1, &s[i], 1);
			printed++;
			i++;
		}
	}
	return (0);
}

