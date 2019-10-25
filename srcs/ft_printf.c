#include <ft_printf.h>

int ft_printf(const char *s, ...)
{
    size_t printed;
    size_t i;
    size_t l;

    if (!s)
        return (0);
    i = 0;
    printed = 0;
    while (s[i])
    {
        if (s[i] == '%' && (l = ft_isflag(s + i)) != 0)
        {
            i += l;
            printed += ft_handleflag(s + i);
        }
        else
        {
            write(1, &s[i],1);
            printed++;
            i++;
        }
    }
    printf("\n");
    return (0);
}