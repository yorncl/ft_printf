/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handleflag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclaudel <mclaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 16:09:49 by mclaudel          #+#    #+#             */
/*   Updated: 2019/10/29 17:54:21 by mclaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

/*
** Return the number of read bytes after handling the flag
**
** @param	str  pointer to flag in string
** @return	int
*/

int	ft_handleflag(const char *str)
{
	(void)str;
	if (*str == '%')
	{
		ft_putchar_fd(*str, 1);
		return (1);
	}
	return (0);
}

/*
** Check if given flag is valid and returns its length
**
** @param	s  pointer to flag in string
** @return	int
*/

int	ft_isflag(const char *s)
{
	char	*flags;
	char	*convs;
	size_t	length;

	flags = "-0.*";
	convs = "cspdiuxX%%";
	(void)flags;
	(void)convs;
	(void)s;
	length = 0;
	/*
	**	Parse flags
	*/
	while (*s && incharset(flags, *s++))
		length++;
	if (*s && incharset(convs, *s))
		length += 1;
	return (length);
}
