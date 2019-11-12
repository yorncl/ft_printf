/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printers.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclaudel <mclaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 14:49:44 by mclaudel          #+#    #+#             */
/*   Updated: 2019/11/11 14:49:44 by mclaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_PRINTERS_H
#define FT_PRINTF_PRINTERS_H

# include <ft_format.h>
# include <ft_utils.h>
# include <libft.h>

/*
**	ft_printers_utils.c
*/
size_t	ft_print_before(t_format *f, int datalen);
size_t	ft_print_after(t_format *f, int datalen);
size_t ft_print_zeroes(int n);
size_t ft_print_spaces(int n);

/*
**	ft_printers1.c
*/
size_t	ft_print_padding(t_format *f, unsigned int datasize);
size_t	ft_printchar(t_format *f, char c);
size_t	ft_printint(t_format *f, int i);
size_t	ft_printstr(t_format *f, char *str);
size_t	ft_printbase(t_format *f, char *base, size_t n);

#endif