#include <ft_printf.h>

/*
*
*   Return the number of read bytes after handling the flag
*
*/
int	ft_handleflag (const char *str)
{
	(void) str;
	return (0);
}

/*
*
*   Check if flag is valid and returns its length
*
*/
int ft_isflag(const char *s)
{
	char *flags = "-0.*";
	char *convs = "cspdiuxX%%";
	
	(void)flags;
	(void)convs;
	(void)s;
	/*1 char read*/
	return (1);
}

