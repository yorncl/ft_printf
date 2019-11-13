/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclaudel <mclaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 14:49:42 by mclaudel          #+#    #+#             */
/*   Updated: 2019/11/13 18:55:07 by mclaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FORMAT_H
# define FT_FORMAT_H

typedef struct		s_format
{
	unsigned int	flags;
	unsigned int	width;
	int				precision;
	unsigned int	size;
	char			type;
}					t_format;

# define INDICATORS	"0-"
# define INTEGERS	"iuxXd"
# define CONVERTERS	"cspdiuxX%"
# define FLAG_MINUS	1
# define FLAG_ZERO	2
# define FLAG_DOT	4
# define FLAG_STAR	8

#endif
