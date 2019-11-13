#include <ft_printf.h>
#include <stdio.h>

int	main (void)
{
	int i;

	// printf("\033[0;36m======================= TEST\033[0m 167\n");
	// i = printf("%*s|fin\n", -150, "coucou");
	// fflush(stdout);
	// printf("                                             \033[1;33mretour officiel   : %d\033[0m\n", i);
	// i = ft_printf("%*s|fin\n", -150, "coucou");
	// printf("                                             \033[1;33mretour unofficiel : %d\033[0m\n", i);

// 	printf("\033[0;36m======================= TEST\033[0m 165\n");
// 	i = printf("ultimate4 %*.*x %*.*X\n", 1, 50, 500, 1, 0, 10);
// 	fflush(stdout);
// 	printf("                                             \033[1;33mretour officiel   : %d\033[0m\n", i);
// 	i = ft_printf("ultimate4 %*.*x %*.*X\n", 1, 50, 500, 1, 0, 10);
// 	printf("                                             \033[1;33mretour unofficiel : %d\033[0m\n", i);


// 	printf("\033[0;36m======================= TEST\033[0m 163\n");
// 	i = printf("ultimate2 %*d %*s %*x %*X %*i %*u\n", 1, 500, 1, "hey", 10, 54700, 1, 300, 1000, -55, 1, -60);
// 		fflush(stdout);
// 	printf("                                             \033[1;33mretour officiel   : %d\033[0m\n", i);
// 	i = ft_printf("ultimate2 %*d %*s %*x %*X %*i %*u\n", 1, 500, 1, "hey", 10, 54700, 1, 300, 1000, -55, 1, -60);
// 	printf("                                             \033[1;33mretour unofficiel : %d\033[0m\n", i);

// ft_printf("***************%*s%*d**************%*u*************\n", 10, "coucou", 10, 10, -50, 20);
	ft_printf("|%p|\n", 0x7ffee42a99a0);
	printf("|%p|\n", 0x7ffee42a99a0);

}