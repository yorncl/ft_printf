/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printers.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclaudel <mclaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 18:59:27 by mclaudel          #+#    #+#             */
/*   Updated: 2019/11/13 19:19:05 by mclaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTERS_H
# define FT_PRINTERS_H

# include <ft_format.h>
# include <ft_utils.h>
# include <libft.h>

size_t	ft_print_before(t_format *f, int datalen);
size_t	ft_print_after(t_format *f, int datalen);
size_t	ft_print_zeroes(int n);
size_t	ft_print_spaces(int n);
size_t	ft_print_padding(t_format *f,
			unsigned int datasize);
size_t	ft_printchar(t_format *f, char c);
size_t	ft_printint(t_format *f, int i);
size_t	ft_printstr(t_format *f, char *str);
size_t	ft_printbase(t_format *f, char *base,
			unsigned int n);
size_t	ft_printaddr(t_format *f, size_t n);
size_t	ft_printpercent(t_format *f);
size_t	ft_printunsigned(t_format *f, unsigned int i);
void	ft_printint_sub(int i, int isneg);
#endif
