/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printers2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclaudel <mclaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 13:23:05 by mclaudel          #+#    #+#             */
/*   Updated: 2019/11/14 15:38:36 by mclaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printers.h>

size_t	ft_printpercent(t_format *f)
{
	size_t			printed;

	printed = 0;
	if (!(f->flags & FLAG_ZERO) && !(f->flags & FLAG_MINUS))
		printed += ft_print_spaces(f->width - 1);
	if (f->flags & FLAG_ZERO)
		printed += ft_print_zeroes(f->width - 1);
	ft_putchar_fd('%', 1);
	printed += 1;
	if (f->flags & FLAG_MINUS)
		printed += ft_print_spaces(f->width - 1);
	return (printed);
}

size_t	ft_printunsigned(t_format *f, unsigned int i)
{
	size_t			printed;
	int				datalen;

	printed = 0;
	if (i == 0 && f->flags & FLAG_DOT && f->precision == 0)
		datalen = 0;
	else
		datalen = ft_unsignedlen(i);
	if (!(f->flags & FLAG_ZERO) && !(f->flags & FLAG_MINUS))
		printed += ft_print_spaces(f->width -
					ft_max(datalen, f->precision));
	if (f->flags & FLAG_ZERO)
		printed += ft_print_zeroes(f->width - datalen);
	if (f->flags & FLAG_DOT && f->precision > datalen)
		printed += ft_print_zeroes(f->precision - datalen);
	if (!(i == 0 && f->flags & FLAG_DOT && f->precision == 0))
	{
		ft_putunsigned_fd(i, 1);
		printed += datalen;
	}
	if (f->flags & FLAG_MINUS)
		printed += ft_print_spaces(
			f->width - ft_max(datalen, f->precision));
	return (printed);
}

size_t	ft_printint_sub(t_format *f, int i, int isneg, int datalen)
{
	size_t printed;

	printed = 0;
	if (!(i == 0 && f->flags & FLAG_DOT && f->precision == 0))
	{
		if (i == -2147483648)
			write(1, "2147483648", 11);
		else
			ft_putnbr_fd(isneg ? -i : i, 1);
		printed = datalen;
	}
	else if (i == 0 & f->typedwidth < 0)
	{
		ft_putchar_fd(' ', 1);
		printed = 1;
	}
	return (printed);
}
