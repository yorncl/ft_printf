#ifndef FT_PRINTF_UTILS_H
#define FT_PRINTF_UTILS_H

# include <libft.h>

/*
**	toputinlib.c 
*/ 
int		incharset(const char *set, char c);
void	ft_putlong_fd(long int n, int fd);
int		ft_putunsignedbase_fd(size_t n, char *base, size_t len, int fd);
size_t	ft_leninbase(int i, char *base);

#endif
