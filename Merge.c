#include <stdio.h>

/*
    m = l + (r - l) / 2;
*/

#define leftArray 4
#define rightArray 3

void merge(int *arr, int l, int m, int r);
void mergeSort(int *arr, int l, int r);
void printArray(int *arr, int n);

int main()
{
    int arr[] = {90, 80, 60, 40, 30, 50};
    int size = sizeof(arr) / sizeof(arr[0]);
    mergeSort(arr, 0, size - 1);
    printArray(arr, size);
}

void merge(int *arr, int l, int m, int r)
{
    int i, j, k;
    int n1 = leftArray;
    int n2 = rightArray;
    // Create temporary arrays
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
    {
        L[i] = arr[l + i];
    }
    for (j = 0; i < n2; j++)
    {
        R[j] = arr[m + j + 1];
    }
    // Merge the temp arrays
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    // Copy the remaining elements of L[]
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    // Copy the remaining elements of R[]
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int *arr, int l, int r)
{
    if (l < r)
    {
        // Finding mid element
        int m = l + (r - l) / 2;
        // Recursively sorting both the halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        // Merge the array
        merge(arr, l, m, r);
    }
}

void printArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d  ", arr[i]);
    }
}