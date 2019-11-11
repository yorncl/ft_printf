/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handleflag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclaudel <mclaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 16:09:49 by mclaudel          #+#    #+#             */
/*   Updated: 2019/11/11 16:11:00 by mclaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

/*
** Parses the flag and returns the numbers of char read
**
** @param	str  pointer to flag in string
** @return	int
*/

int	ft_parseflag(t_format *f, va_list *ap, const char *s)
{
	int len;

	len = 0;
	/*
	**	Parse Indicator
	*/
	if (incharset(INDICATORS, *s))
	{

		if (*s == '0')
			f->flags += FLAG_ZERO;
		else if (*s == '-')
			f->flags += FLAG_MINUS;
		len++;
		s++;
	}
	printf("Indicateurs %d\n", f->flags);
	/*
	**	Parse width
	*/
	f->width = ft_atoi(s);
	while (ft_isdigit(*s))
	{
		s++;
		len++;
	}	
	printf("Minimal width %d\n", f->width);
	/*
	**	Parse precision
	*/
	if (*s == '.')
	{
		if (*(++s) == '*')
		{
			f->precision = va_arg(*ap, int);
			s++;
			len++;
		}
		else
			f->precision = ft_atoi(s);
		len++;
	}
	while (ft_isdigit(*s))
	{
		s++;
		len++;
	}
	printf("Precision %d\n", f->precision);
	/*
	**	Parse size (stay null for now)
	*/
	/*
	**	Parse type
	*/
	f->type = *s;
	len++;
	printf("Type %c\n", f->type);
	printf("Len %d\n", len);
	return (len);
}

/*
** Return the number of read bytes after handling the flag
**
** @param	str  pointer to flag in string
** @return	int
*/

int	ft_printflag(t_format *f, va_list *ap)
{
	unsigned int printed;

	printed = 0;
	if (f->type == 'c')
		ft_printchar(f, va_arg(*ap, int));
	if (f->type == 'c')
		ft_printchar(f, va_arg(*ap, int));
	return (0);
}
