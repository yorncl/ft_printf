/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printers1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclaudel <mclaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 14:49:05 by mclaudel          #+#    #+#             */
/*   Updated: 2019/11/11 20:33:01 by mclaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printers.h>
#include <stdio.h>

size_t	ft_printchar(t_format *f, char c)
{
	(void) f;
	(void) c;
	int printed;

	printed = 0;
	printed += ft_print_before(f, 1);
	ft_putchar_fd(c, 1);
	printed += 1 + ft_print_after(f, 1);
	return (printed);
}

size_t	ft_printint(t_format *f, int i)
{
	size_t			printed;
	size_t			datalen;
	unsigned int	isneg;

	printed = 0;
	datalen = ft_intlen(i);
	isneg = i < 0;
	//Print spaces
	if (!(f->flags & FLAG_ZERO) && !(f->flags & FLAG_MINUS))
		printed += ft_print_spaces(f->width -
					ft_max(datalen, f->precision + isneg));
	//Print sign
	if (isneg)
		ft_putchar_fd('-', 1);
	//Print zeros
	if (f->flags & FLAG_ZERO)
		printed += ft_print_zeroes(f->width - datalen);
	if (f->flags & FLAG_DOT && f->precision + isneg > datalen)
		printed += ft_print_zeroes(f->precision + isneg - datalen);
	//Print Number
	ft_putlong_fd(isneg ? -i : i, 1);
	printed += datalen;
	//Print spaces
	if (f->flags & FLAG_MINUS)
		printed += ft_print_spaces(
			f->width - ft_max(datalen, f->precision + isneg));
	return (printed);
}

size_t	ft_printstr(t_format *f, char *str)
{
	size_t len;
	//Check if there's a precision
	if (f->flags & FLAG_DOT)
		len = ft_min(f->precision, ft_strlen(str));
	else
		len = ft_strlen(str);
	write(1, str, len);
	return (len);
}

// size_t	ft_printaddr()
// {
	
// }

size_t	ft_printbase(t_format *f, char *base, size_t n)
{
	size_t			printed;
	//Une precision negative est-elle possible ?
	int			datalen;
	//
	printed = 0;
	datalen = ft_leninbase(n, base);
	//Print spaces
	if (!(f->flags & FLAG_ZERO) && !(f->flags & FLAG_MINUS))
		printed += ft_print_spaces(f->width -
					ft_max(datalen, f->precision));
	//Print zeros
	if (f->flags & FLAG_ZERO)
		printed += ft_print_zeroes(f->width - datalen);
	if (f->flags & FLAG_DOT && f->precision > datalen)
		printed += ft_print_zeroes(f->precision - datalen);
	//Print Number
	ft_putunsignedbase_fd(n, base, ft_strlen(base), 1);
	printed += datalen;
	//Print spaces
	if (f->flags & FLAG_MINUS)
		printed += ft_print_spaces(
			f->width - ft_max(datalen, f->precision));
	return (printed);
	return (0);
}
