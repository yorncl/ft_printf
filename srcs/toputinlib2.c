/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toputinlib2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclaudel <mclaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 16:16:02 by mclaudel          #+#    #+#             */
/*   Updated: 2019/11/13 18:36:39 by mclaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_utils.h>

size_t	ft_sizetleninbase(size_t i, char *base)
{
	size_t len;
	size_t order;

	order = ft_strlen(base);
	len = 0;
	while (i > 0 && ++len)
		i /= order;
	return (len ? len : 1);
}

void	ft_putsizetbase_fd(size_t n, char *base, size_t len, int fd)
{
	if (n / len > 0)
		ft_putsizetbase_fd(n / len, base, len, fd);
	ft_putchar_fd(base[n % len], fd);
}
