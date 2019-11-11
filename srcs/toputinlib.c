#include <ft_printf_utils.h>

int	incharset(const char *set, char c)
{
	while (*set)
		if (*set == c)
			return (1);
		else
			set++;
	return (0);
}

int ft_strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

