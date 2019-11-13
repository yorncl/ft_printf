/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toputinlib1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclaudel <mclaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 13:39:00 by mclaudel          #+#    #+#             */
/*   Updated: 2019/11/13 16:17:20 by mclaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_utils.h>

int		incharset(const char *set, char c)
{
	while (*set)
		if (*set == c)
			return (1);
		else
			set++;
	return (0);
}

void	ft_putunsigned_fd(size_t n, int fd)
{
	if (n / 10 > 0)
		ft_putnbr_fd(n / 10, fd);
	ft_putchar_fd('0' + n % 10, fd);
}

void		ft_putunsignedbase_fd(unsigned int n, char *base, size_t len, int fd)
{
	if (n / len > 0)
		ft_putunsignedbase_fd(n / len, base, len, fd);
	ft_putchar_fd(base[n % len], fd);
}

//Need to manage int aswell
size_t	ft_leninbase(unsigned int i, char *base)
{
	size_t len;
	unsigned int order;

	order = ft_strlen(base);
	len = 0;
	while (i > 0 && ++len)
		i /= order;
	return (len ? len : 1);
}



int		ft_unsignedlen(unsigned int n)
{
	size_t size;

	size = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		size++;
	}
	return (size);
}
