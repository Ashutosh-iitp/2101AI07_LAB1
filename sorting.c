#include <stdio.h>

//Function to swap numbers
int swap(int *aj, int *bj)
{
    int temp = *aj;
    *aj = *bj;
    *bj = temp;

    return 0;
}
