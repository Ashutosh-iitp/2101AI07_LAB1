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
//Function Definiton for Insertion Sort
void Insertion(int n,int arr[])
{
    int i,j,kys;
    for (i = 1; i < n; i++)
    {
        kys = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > kys)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = kys;
    }
}
//Function Definition for Selection Sort
void Selection( int n,int arr[])
{
    int i, j, mindx;


    for (i = 0; i < n-1; i++)
    {
        // Finding the index of min element in unsorted part
        mindx = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[mindx])
            mindx = j;

        // Swap the found minimum element with the first element of unsorted part
        swap(&arr[mindx], &arr[i]);

    }
}
//Function Definition for Merge Sort
void com(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    /* create temp arrays */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[] */
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[]*/
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void Merge(int arr[], int l, int r)
{
    if (l < r) {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l + (r - l) / 2;

        // Sort first and second halves
        Merge(arr, l, m);
        Merge(arr, m + 1, r);

        com(arr, l, m, r);
    }
}
//Function Definition for Quick Sort

int partition(int array[], int l, int r) {

  // select the rightmost element as pivot
  int pivot = array[r];

  // pointer for greater element
  int i = (l - 1);

  // traverse each element of the array
  // compare them with the pivot
  for (int j = l; j < r; j++) {
    if (array[j] <= pivot) {

      // if element smaller than pivot is found
      // swap it with the greater element pointed by i
      i++;

      // swap element at i with element at j
      swap(&array[i], &array[j]);
    }
  }

  // swap the pivot element with the greater element at i
  swap(&array[i + 1], &array[r]);

  // return the partition point
  return (i + 1);
}


void Quick(int array[], int l, int r) {
  if (l < r) {

    // find the pivot element such that
    // elements smaller than pivot are on left of pivot
    // elements greater than pivot are on right of pivot
    int p = partition(array, l, r);

    // recursive call on the left of pivot
    Quick(array, l, p - 1);

    // recursive call on the right of pivot
    Quick(array, p + 1, r);
  }
}
