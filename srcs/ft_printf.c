/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclaudel <mclaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 16:57:35 by mclaudel          #+#    #+#             */
/*   Updated: 2019/10/29 17:55:33 by mclaudel         ###   ########.fr       */
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
	size_t	printed;
	size_t	i;
	size_t	l;
	va_list	ap;

	if (!s)
		return (0);
	i = 0;
	printed = 0;
	va_start(ap, s);
	while (s[i])
		if (s[i] == '%' && (l = ft_isflag(s + i)) != 0)
		{
			printed += ft_handleflag(s + i + 1);
			i += l;
		}
		else
		{
			write(1, &s[i], 1);
			printed++;
			i++;
		}
	va_end(ap);
	return (0);
}
