#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/* Test and global includes */
# include <stdio.h>
# include <stdlib.h>

/* Project headers */
# include <converters.h>
/* Main functions */
int ft_printf(const char *, ...);
int ft_handleflag (const char *str);
int ft_isflag(const char *s);
#endif