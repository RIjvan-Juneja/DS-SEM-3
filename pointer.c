#include <stdio.h>

int main() {
    int num = 42;
    int *numPtr;  // Declare a pointer to an integer

    numPtr = &num;  // Assign the memory address of 'num' to 'numPtr'

    printf("Value of num: %d\n", num);
    printf("Address of num: %p\n", &num); 
    printf("Value of numPtr: %p\n", numPtr);  // Prints the memory address stored in 'numPtr'
    printf("Value at the memory location pointed by numPtr: %d\n", *numPtr);  // Dereferencing the pointer

    return 0;
}
   