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
# include <ft_printers.h>
# include <ft_format.h>
# include <ft_utils.h>
/* Main functions */
int ft_printf(const char *, ...);
int ft_printflag (t_format *f, va_list *ap);
int ft_parseflag(t_format *f, va_list *ap, const char *s);
#endif