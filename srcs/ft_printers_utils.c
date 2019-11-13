/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printers_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclaudel <mclaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 16:30:33 by mclaudel          #+#    #+#             */
/*   Updated: 2019/11/13 18:40:03 by mclaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printers.h>

size_t	ft_print_before(t_format *f, int datalen)
{
	int n;

	if (f->flags & FLAG_MINUS)
		return (0);
	n = f->width - datalen;
	if (n < 0)
		return (0);
	if (f->flags & FLAG_ZERO && !f->precision)
		while (n--)
			ft_putchar_fd('0', 1);
	else
		while (n--)
			ft_putchar_fd(' ', 1);
	return (f->width - datalen);
}

size_t	ft_print_after(t_format *f, int datalen)
{
	int n;

	if (!(f->flags & FLAG_MINUS))
		return (0);
	n = f->width - datalen;
	if (n < 0)
		return (0);
	while (n--)
		ft_putchar_fd(' ', 1);
	return (f->width - datalen);
}

size_t	ft_print_zeroes(int n)
{
	int size;

	size = n > 0 ? n : 0;
	while (n-- > 0)
		ft_putchar_fd('0', 1);
	return (size);
}

size_t	ft_print_spaces(int n)
{
	int size;

	size = n > 0 ? n : 0;
	while (n-- > 0)
		ft_putchar_fd(' ', 1);
	return (size);
}
