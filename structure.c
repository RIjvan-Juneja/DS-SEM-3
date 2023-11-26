#include <stdio.h>

// Define a structure
struct Student {
    char name[9];
    int age;
    float spi;
};

int main() {
    // Declare a structure variable
    // struct Student student1;

    // Declare a pointer to the structure
    struct Student *ptr;
    struct Student student1;
    
    

    // Initialize the structure's members using the structure variable
    student1.name[0] = 'J';
    student1.name[1] = 'o';
    student1.name[2] = 'h';
    student1.name[3] = 'n';
    student1.name[4] = ' ';
    student1.name[5] = 'D';
    student1.name[6] = 'o';
    student1.name[7] = 'e';
    student1.name[8] = '\0'; // Null-terminate the string
    student1.age = 20;
    student1.spi = 3.8;

    // Assign the address of the structure variable to the pointer
    ptr = &student1;

    // Access structure members using the pointer
    printf("Student Name: %s\n", ptr->name);
    printf("Student Age: %d\n", ptr->age);
    printf("Student spi: %.2f\n", ptr->spi);

    return 0;
}
