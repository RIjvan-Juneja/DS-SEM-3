#include <stdio.h>
// int linearearch(int arr[], int n, int key);

int linearearch(int arr[], int n, int key){
    
    for (int i = 0; i<n; i++)
    {
        if (arr[i] == key)
        {
            return i;
        }  
    }
    return -1;
}

void main(){
    int arr[]= {0,1,2,3,4,5,6,7};
    int n=8;
    int key=500;
    int result = linearearch(arr,n,key);
    if (result == -1)
    {
        printf("element not found");
    } 
    else{
        printf("element found at index %d\n",result);
    }
    
}