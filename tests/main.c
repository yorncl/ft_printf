#include <stdio.h>
#include <ft_printf.h>

int main()
{
    int number = 69;
    printf(" \"%-5d\" \n", number);
    printf(" %05d \n", number);
    printf(" %10x \n", number);  
    printf(" %#050x \n", number);
    printf(" %#-50x \n", number);
    printf("\"-50#u\" \n", number);
    printf("\"%-50i\" \n", number);
    ft_printf("Bonsoir");
}