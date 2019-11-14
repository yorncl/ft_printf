/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printers1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclaudel <mclaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 14:49:05 by mclaudel          #+#    #+#             */
/*   Updated: 2019/11/14 20:15:33 by mclaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printers.h>

size_t	ft_printchar(t_format *f, char c)
{
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
	if (!(f->flags & FLAG_ZERO) && !(f->flags & FLAG_MINUS))
		printed += ft_print_spaces(f->width -
					ft_max(datalen, f->precision + isneg));
	if (isneg)
		ft_putchar_fd('-', 1);
	if (f->flags & FLAG_ZERO)
		printed += ft_print_zeroes(f->width - datalen);
	if (f->flags & FLAG_DOT && f->precision + isneg > datalen)
		printed += ft_print_zeroes(f->precision + isneg - datalen);
	printed += ft_printint_sub(f, i, isneg, datalen);
	if (f->flags & FLAG_MINUS)
		printed += ft_print_spaces(
			f->width - ft_max(datalen, f->precision + isneg));
	return (printed);
}

size_t	ft_printstr(t_format *f, char *str)
{
	size_t	printed;
	int		datalen;

	if (!str || (int)str < 0)
		str = "(null)";
	printed = 0;
	if (f->flags & FLAG_DOT)
		datalen = f->precision < 0 ? ft_strlen(str)
			: ft_min(f->precision, ft_strlen(str));
	else
		datalen = ft_strlen(str);
	if (!(f->flags & FLAG_MINUS))
		printed += ft_print_spaces(f->width - datalen);
	write(1, str, datalen);
	printed += datalen;
	if (f->flags & FLAG_MINUS)
		printed += ft_print_spaces(f->width - datalen);
	return (printed);
}

size_t	ft_printaddr(t_format *f, size_t n)
{
	size_t	printed;
	size_t	datalen;
	char	*base;

	base = "0123456789abcdef";
	printed = 0;
	datalen = 2 + (n == 0 && f->flags & FLAG_DOT
		? 0 : ft_sizetleninbase(n, base));
	if (!(f->flags & FLAG_ZERO) && !(f->flags & FLAG_MINUS))
		printed += ft_print_spaces(f->width - datalen);
	ft_putstr_fd("0x", 1);
	if (!(n == 0 && f->flags & FLAG_DOT))
		ft_putsizetbase_fd(n, base, ft_strlen(base), 1);
	printed += datalen;
	if (f->flags & FLAG_MINUS)
		printed += ft_print_spaces(f->width - datalen);
	return (printed);
}

size_t	ft_printbase(t_format *f, char *base, unsigned int n)
{
	size_t		printed;
	int			datalen;

	printed = 0;
	if (n == 0 && f->flags & FLAG_DOT && f->precision == 0)
		datalen = 0;
	else
		datalen = ft_leninbase(n, base);
	if (!(f->flags & FLAG_ZERO) && !(f->flags & FLAG_MINUS))
		printed += ft_print_spaces(f->width -
					ft_max(datalen, f->precision));
	if (f->flags & FLAG_ZERO)
		printed += ft_print_zeroes(f->width - datalen);
	if (f->flags & FLAG_DOT && f->precision > datalen)
		printed += ft_print_zeroes(f->precision - datalen);
	if (!(n == 0 && f->flags & FLAG_DOT && f->precision == 0))
	{
		ft_putunsignedbase_fd(n, base, ft_strlen(base), 1);
		printed += datalen;
	}
	if (f->flags & FLAG_MINUS)
		printed += ft_print_spaces(
			f->width - ft_max(datalen, f->precision));
	return (printed);
}
