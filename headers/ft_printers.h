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
# include <libft.h>

int	ft_print_padding(t_format *f, unsigned int datasize);
int	ft_printchar(t_format *f, char c);
#endif