/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclaudel <mclaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 19:01:56 by mclaudel          #+#    #+#             */
/*   Updated: 2019/11/13 19:03:05 by mclaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_H
# define FT_UTILS_H

# include <libft.h>

/*
**	toputinlib.c
*/
int		incharset(const char *set, char c);
void	ft_putunsigned_fd(size_t n, int fd);
void	ft_putunsignedbase_fd(unsigned int n, char *base, size_t len, int fd);
size_t	ft_leninbase(unsigned int i, char *base);
int		ft_unsignedlen(unsigned int n);

/*
**	toputinlib2.c
*/
void	ft_putsizetbase_fd(size_t n, char *base, size_t len, int fd);
size_t	ft_sizetleninbase(size_t i, char *base);
#endif
