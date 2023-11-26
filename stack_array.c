#include <stdio.h>
// #include <stdlib.h>

// #define n 4
int n =4;

int top = -1, stack[4];
void push();
void pop();
void Display();
void PEEP();

int main(){
    int choice;

    while (1)
    {
        printf("**********************************\n");
        printf("\nPerform operations on the stack:");
        printf("\n1.Push the element\n2.Pop the element\n3.Display\n4.PEEP\n5.End");
        printf("\n\nEnter the choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            Display();
            break;
        case 4:
            PEEP();
            break;
        case 5:
            return 0;

        default:
            printf("\nInvalid choice!!");
        }
    }
}

void push()
{
    int x;

    if (top == n - 1)
    {
        printf("\nOverflow!!");
    }
    else
    {
        printf("\nEnter the element : ");
        scanf("%d", &x);
        top = top + 1;
        stack[top] = x;
    }
}

void pop()
{
    if (top == -1)
    {
        printf("\nUnderflow!!");
    }
    else
    {
        printf("\nPopped element: %d", stack[top]);
        top = top - 1;
    }
}
void PEEP(){
    
    if (top == -1)
    {
        printf("\nUnderflow!!");
    } else{
        printf("Last Element :%d",stack[top]);
    }
}
void Display()
{
    if (top == -1)
    {
        printf("\nUnderflow!!");
    }
    else
    {
        printf("\nElements present in the stack: \n");
    //     for (int i = top; i >= 0; --i)
    //         printf("%d\n", stack[i]);
    // }
    for (int i = 0; i <= top; i++)
    {
        printf("%d\n", stack[i]);
    }
}
    
}