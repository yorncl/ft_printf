/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printers2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclaudel <mclaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 13:23:05 by mclaudel          #+#    #+#             */
/*   Updated: 2019/11/12 17:14:31 by mclaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printers.h>

size_t	ft_printpercent(t_format *f)
{
	size_t			printed;

	printed = 0;
	//Print spaces
	if (!(f->flags & FLAG_ZERO) && !(f->flags & FLAG_MINUS))
		printed += ft_print_spaces(f->width - 1);
	//Print zeros
	if (f->flags & FLAG_ZERO)
		printed += ft_print_zeroes(f->width - 1);
	//Print Char
	ft_putchar_fd('%', 1);
	printed += 1;
	//Print spaces
	if (f->flags & FLAG_MINUS)
		printed += ft_print_spaces(f->width - 1);
	return (printed);
}

size_t	ft_printunsigned(t_format *f, size_t i)
{
	size_t			printed;
	int				datalen;

	printed = 0;
	if (i == 0 && f->flags & FLAG_DOT && f->precision == 0)
		datalen = 0;
	else
		datalen = ft_unsignedlen(i);
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
	if (!(i == 0 && f->flags & FLAG_DOT && f->precision == 0))
	{
		ft_putunsigned_fd(i, 1);
		printed += datalen;
	}
	//Print spaces
	if (f->flags & FLAG_MINUS)
		printed += ft_print_spaces(
			f->width - ft_max(datalen, f->precision));
	return (printed);
}
