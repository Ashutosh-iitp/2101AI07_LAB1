#include <stdio.h>

//Function to swap numbers
int swap(int *aj, int *bj)
{
    int temp = *aj;
    *aj = *bj;
    *bj = temp;

    return 0;
}
//Function Definiton for Bubble Sort
void Bubble(int n,int arr[])
{
    int i, j;
    for (i = 0; i < n - 1; i++)

        for (j = 0; j < n - i - 1; j++)

            if (arr[j] > arr[j + 1])
            {
                //Algorithm for swapping two numbers
                arr[j]=arr[j] - arr[j+1];
                arr[j + 1]=arr[j] + arr[j + 1];
                arr[j]=arr[j+1] - arr[j];

            }
}