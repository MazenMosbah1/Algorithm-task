#include <stdio.h>

void insertionSort(int *arr, int n);
void printArray(int *arr, int n);

int main()
{
    int arr[] = {80, 90, 60, 30, 50, 40};
    int size = sizeof(arr) / sizeof(arr[0]);
    insertionSort(arr, size);
    printArray(arr, size);
}

void insertionSort(int *arr, int n)
{
    int key, i, j;
    for (int i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void printArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d  ", arr[i]);
    }
}