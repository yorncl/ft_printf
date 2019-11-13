/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclaudel <mclaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 19:00:55 by mclaudel          #+#    #+#             */
/*   Updated: 2019/11/13 19:01:09 by mclaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <libft.h>
# include <ft_printers.h>
# include <ft_format.h>
# include <ft_utils.h>

int		ft_printf(const char *s, ...);
int		ft_printflag (t_format *f, va_list *ap);
int		ft_parseflag(t_format *f, va_list *ap, const char *s);
char	*ft_parsewidth(const char *s, int *len, t_format *f, va_list *ap);
char	*ft_parseprecision(const char *s, int *len, t_format *f, va_list *ap);
#endif
