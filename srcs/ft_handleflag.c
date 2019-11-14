/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handleflag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclaudel <mclaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 16:09:49 by mclaudel          #+#    #+#             */
/*   Updated: 2019/11/14 16:00:02 by mclaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

char	*ft_parsewidth(const char *s, int *len, t_format *f, va_list *ap)
{
	if (*s == '*')
	{
		f->typedwidth = va_arg(*ap, int);
		if (f->typedwidth < 0)
		{
			f->width = -f->typedwidth;
			f->flags |= FLAG_MINUS;
		}
		else
			f->width = f->typedwidth;
		s++;
		*len += 1;
	}
	else
	{
		f->width = ft_atoi(s);
		while (ft_isdigit(*s))
		{
			s++;
			*len += 1;
		}
	}
	return ((char *)s);
}

char	*ft_parseprecision(const char *s, int *len, t_format *f, va_list *ap)
{
	if (*s == '.')
	{
		f->flags |= FLAG_DOT;
		if (*(++s) == '*')
		{
			f->flags |= FLAG_STAR;
			f->precision = va_arg(*ap, int);
			// if (f->precision < 0)
			// 	f->flags -= FLAG_DOT;
			s++;
			*len += 1;
		}
		else
			f->precision = ft_atoi(s);
		*len += 1;
	}
	while (ft_isdigit(*s))
	{
		s++;
		*len += 1;
	}
	return ((char *)s);
}

/*
** Parses the flag and returns the numbers of char read
**
** @param	str  pointer to flag in string
** @return	int
*/
#include <stdio.h>
int		ft_parseflag(t_format *f, va_list *ap, const char *s)
{
	int len;

	len = 0;
	while (incharset(INDICATORS, *s))
	{
		if (*s == '0')
			f->flags |= FLAG_ZERO;
		if (*s == '-')
			f->flags |= FLAG_MINUS;
		len++;
		s++;
	}
	s = ft_parsewidth(s, &len, f, ap);
	// printf("\033[1;36m %d \033[0m", f->flags & FLAG_ZERO);
	s = ft_parseprecision(s, &len, f, ap);
	f->type = *s;
	len++;
	// if (f->flags & FLAG_MINUS && f->typedwidth < 0)
	// 	f->flags -= FLAG_MINUS;
	if ((f->flags & FLAG_ZERO && f->flags & FLAG_MINUS)	|| (incharset(INTEGERS, f->type) && f->flags & FLAG_ZERO && f->flags & FLAG_DOT))
		f->flags ^= FLAG_ZERO;
	if ((f->flags & FLAG_ZERO && f->type == 'p') || (f->flags & FLAG_DOT && f->type == 'p' && (ft_isdigit(*(s - 1)) || f->flags & FLAG_STAR)))
		f->type = 'o';
	return (incharset(CONVERTERS, f->type) ? len : 0);
}

/*
** Return the number of read bytes after printing the flag
**
** @param	f  	format parsed
** @param	ap  arguments struct from stdarg
** @return	int
*/

int		ft_printflag(t_format *f, va_list *ap)
{
	if (f->type == 'c')
		return (ft_printchar(f, va_arg(*ap, int)));
	if (f->type == 'd' || f->type == 'i')
		return (ft_printint(f, va_arg(*ap, int)));
	if (f->type == 's')
		return (ft_printstr(f, va_arg(*ap, char*)));
	if (f->type == 'x')
		return (ft_printbase(f, "0123456789abcdef", va_arg(*ap, unsigned int)));
	if (f->type == 'X')
		return (ft_printbase(f, "0123456789ABCDEF", va_arg(*ap, unsigned int)));
	if (f->type == 'p')
		return (ft_printaddr(f, va_arg(*ap, size_t)));
	if (f->type == '%')
		return (ft_printpercent(f));
	if (f->type == 'u')
		return (ft_printunsigned(f, va_arg(*ap, unsigned int)));
	return (0);
}
