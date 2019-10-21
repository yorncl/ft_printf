#include <stdio.h>
#include <ft_printf.h>

int main()
{
    int number = 69;
    printf(" \"%-5d\" \n", number);
    printf(" %05d \n", number);
    printf(" %10x \n", number);  
    printf(" %#x \n", number);
    printf(" %i \n", number);
    ft_printf("Ma grosse teub ouais");
}