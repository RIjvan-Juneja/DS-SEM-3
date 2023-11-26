#include <stdio.h>

void merge(int arr[], int left[], int right[], int left_size, int right_size)
{
    int i = 0, j = 0, k = 0;

    while (i < left_size && j < right_size)
    {
        if (left[i] <= right[j])
        {
            arr[k] = left[i];
            k++;
            i++;
        }
        else
        {
            arr[k] = right[j];
            k++;
            j++;
        }
    }

    while (i < left_size)
    {
        arr[k] = left[i];
        k++;
        i++;
    }

    while (j < right_size)
    {
        arr[k] = right[j];
        k++;
        j++;
    }
}

void mergeSort(int arr[], int size)
{
    int i;
    if (size <= 1)
    {
        return; // Base case: already sorted
    }
 
    int mid = size / 2;
    int left[mid];               
    int right[size - mid];

    // Split the array into two halves
    for (i = 0; i < mid; i++)
    {
        left[i] = arr[i];
    }

    for (i = mid; i < size; i++)
    {
        right[i - mid] = arr[i];
    }

    // Recursively sort the left and right halves
    mergeSort(left, mid);
    mergeSort(right, size - mid);

    // Merge the sorted halves
    merge(arr, left, right, mid, size - mid);
}

int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int size = 6;

    printf("Original array: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    mergeSort(arr, size);

    printf("Sorted array: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
