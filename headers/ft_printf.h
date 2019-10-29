/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclaudel <mclaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 16:59:44 by mclaudel          #+#    #+#             */
/*   Updated: 2019/10/22 16:59:44 by mclaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/* Test and global includes */
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

# include <libft.h>

/* Project headers */
# include <ft_printf_converters.h>
# include <ft_printf_utils.h>
/* Main functions */
int ft_printf(const char *, ...);
int ft_handleflag (const char *str);
int ft_isflag(const char *s);
#endif