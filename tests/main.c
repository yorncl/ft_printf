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
	(void) number;
    // printf(" \"%-5d\" \n", number);
    // printf(" %05d \n", number);
    // printf(" %10x \n", number);  
    // printf(" %#050x \n", number);
    // printf(" %#-50x \n", number);
  	// // printf("\"-50#u\" \n", number);
    // printf("\"%-50i\" \n", number);
	 char *str = "Bonsoir \"%-10X\"\n";
	 int nb = 666;
	 int r1 = ft_printf(str, nb);
	 int r2 = printf(str, nb);
	 printf("r1 = %d vs r2 = %d\n", r1, r2);
	
	// // printf("\n\n\n");

	// str = "Bonsoir \"%--50.5d\"\n";
	// r1 = ft_printf(str, -150);
	// r2 = printf(str, -150);
	// printf("r1 = %d vs r2 = %d\n", r1, r2);
	// // f(3,1,34);
}

