#ifndef FT_PRINTF_UTILS_H
#define FT_PRINTF_UTILS_H

# include <libft.h>

/*
**	toputinlib.c 
*/ 
int		incharset(const char *set, char c);
void	ft_putunsigned_fd(size_t n, int fd);
void	ft_putunsignedbase_fd(size_t n, char *base, size_t len, int fd);
size_t	ft_leninbase(unsigned int i, char *base);
int		ft_unsignedlen(unsigned int n);

#endif