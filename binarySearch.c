#include <stdio.h>
// #include <stdio.h>
// Binary search function
int binarySearch(int arr[], int n, int key) {
    int s = 0;
    int e = n - 1;
    int mid;
    while (s <= e) {
         mid = (s+e)/2;

        if (arr[mid] == key) {
            return mid; // key found at index 'mid'
        } else if(arr[mid] < key) {
            s = mid + 1; // Adjust s boundary
        } else {
            e = mid - 1; // Adjust e boundary
        }
    }
    return -1; // key not found  
}

int main() {
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 45, 56, 72};
    // int n = nof(arr) / nof(arr[0]);
    int n = 10;
    int key = 8;

    int result = binarySearch(arr, n, key);

    if (result == -1) {
        printf("Element not found in the array\n");
    } else {
        printf("Element found at index %d\n",result);
    }

    return 0;
}
 