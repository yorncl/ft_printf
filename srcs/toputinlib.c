#include <ft_utils.h>

int	incharset(const char *set, char c)
{
	while (*set)
		if (*set == c)
			return (1);
		else
			set++;
	return (0);
}


//Not really usefull I guess
void	ft_putlong_fd(long int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putchar_fd('-', fd);
		ft_putchar_fd('2', fd);
		ft_putnbr_fd(147483648, fd);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n *= -1;
	}
	if (n / 10 > 0)
		ft_putnbr_fd(n / 10, fd);
	ft_putchar_fd('0' + n % 10, fd);
}

//To Opti

int		ft_putunsignedbase_fd(size_t n, char *base, size_t len, int fd)
{
	if (n / len > 0)
		ft_putunsignedbase_fd(n / len, base, len, fd);
	ft_putchar_fd(base[n % len], fd);
	return (0);
}

size_t	ft_leninbase(int i, char *base)
{
	size_t len;
	size_t order;

	order = ft_strlen(base);
	len = 0;
	while (i > 0 && ++len)
		i /= order;
	return (len ? len : 1);
}
