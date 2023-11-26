#include <stdio.h>
#include <stdlib.h>

int main() {
    // Allocate memory for an integer using malloc
    int *ptr1 = (int *)malloc(sizeof(int));
    if (ptr1 == NULL) {
        printf("Memory allocation using malloc failed.\n");
        return 1;
    } 
   
    *ptr1 = 42;
    printf("%d \n", *ptr1);

    // Allocate memory for an integer array using calloc
    int *ptr2 = (int *)calloc(5, sizeof(int));
    if (ptr2 == NULL) {
        printf("Memory allocation using calloc failed.\n");
        return 1;
    }
  
     ptr2[0] = 10;
     ptr2[1] = 10;
     ptr2[2] = 30;
     ptr2[3] = 10;
     ptr2[4] = 30;
    for (int i = 0; i < 5; i++) {
       printf("%d \n", ptr2[i]);
    }

    // Deallocate memory
    free(ptr1);
    free(ptr2);  

    return 0;
}
