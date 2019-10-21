#include <stdio.h>

int main()
{
    int number = 69;
    printf(" \"%-5d\" \n", number);
    printf(" %05d \n", number);
    printf(" %10x \n", number);  
    printf(" %#x \n", number);
}