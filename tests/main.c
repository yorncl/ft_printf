#include <stdio.h>
#include <ft_printf.h>

void	f(int num,...)
{
	va_list ap;

	va_start(ap, num);

	while (num--)
	{
		printf("arg : %d\n", va_arg(ap, int));
	}
	va_end(ap);
}

int main()
{
    int number = 69;
    printf(" \"%-5d\" \n", number);
    printf(" %05d \n", number);
    printf(" %10x \n", number);  
    printf(" %#050x \n", number);
    printf(" %#-50x \n", number);
  	// printf("\"-50#u\" \n", number);
    printf("\"%-50i\" \n", number);
	ft_printf("Bonsoir %% \n", "yes");
	// f(3,1,34);
}

