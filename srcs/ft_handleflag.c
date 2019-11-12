/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handleflag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclaudel <mclaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 16:09:49 by mclaudel          #+#    #+#             */
/*   Updated: 2019/11/12 17:29:09 by mclaudel         ###   ########.fr       */
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
	while (incharset(INDICATORS, *s))
	{
		if (*s == '0')
			f->flags |= FLAG_ZERO;
		if (*s == '-')
			f->flags |= FLAG_MINUS;
		len++;
		s++;
	}
	// printf("Indicateurs %d\n", f->flags);
	/*
	**	Parse width
	*/
	f->width = ft_atoi(s);
	while (ft_isdigit(*s))
	{
		s++;
		len++;
	}	
	// printf("Minimal width %d\n", f->width);
	/*
	**	Parse precision
	*/
	if (*s == '.')
	{
		f->flags += FLAG_DOT;
		if (*(++s) == '*')
		{
			f->precision = va_arg(*ap, int);
			if (f->precision < 0)
				f->flags -= FLAG_DOT;
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
	// printf("Precision %d\n", f->precision);
	/*
	**	Parse size (stay null for now)
	*/
	/*
	**	Parse type
	*/
	f->type = *s;
	len++;
	// printf("Type %c\n", f->type);
	// printf("Len %d\n", len);
	if ((f->flags & FLAG_ZERO && f->flags & FLAG_MINUS)
		|| (incharset(INTEGERS, f->type) 
	&& f->flags & FLAG_ZERO && f->flags & FLAG_DOT))
		f->flags -= FLAG_ZERO;
	return (len);
}

/*
** Return the number of read bytes after printing the flag
**
** @param	f  	format parsed
** @param	ap  arguments struct from stdarg
** @return	int
*/

int	ft_printflag(t_format *f, va_list *ap)
{
	if (f->type == 'c')
		return (ft_printchar(f, va_arg(*ap, int)));
	if (f->type == 'd' || f->type == 'i')
		return (ft_printint(f, va_arg(*ap, int)));
	if (f->type == 's')
		return (ft_printstr(f, va_arg(*ap, char*)));
	if (f->type == 'x')
		return (ft_printbase(f, "0123456789abcdef", va_arg(*ap, size_t)));
	if (f->type == 'X')
		return (ft_printbase(f, "0123456789ABCDEF", va_arg(*ap, size_t)));
	if (f->type == 'p')
		return (ft_printaddr(f, va_arg(*ap, size_t)));
	if (f->type == '%')
		return (ft_printpercent(f));
	if (f->type == 'u')
		return (ft_printunsigned(f, va_arg(*ap, size_t)));
	return (0);
}
