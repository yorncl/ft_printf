/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclaudel <mclaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 16:57:35 by mclaudel          #+#    #+#             */
/*   Updated: 2019/11/11 14:55:24 by mclaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

/*
** printf but with more style
**
** @param	s  pointer to formatted string
** @param	...  arguments to print
** @return	int
*/

int	ft_printf(const char *s, ...)
{
	size_t		printed;
	size_t		i;
	va_list		ap;
	t_format	format;

	if (!s)
		return (0);
	i = 0;
	printed = 0;
	va_start(ap, s);
	while (s[i])
		if (s[i] == '%')
		{
			ft_bzero(&format, sizeof(format));
			i += 1 + ft_parseflag(&format, &ap, s + i + 1);
			printed += ft_printflag(&format,&ap);
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
