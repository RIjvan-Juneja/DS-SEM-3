#include <stdio.h>
// #include <stdlib.h>
// #define n 10

void enqueue();
void dequeue();
void show();

int n = 5;
int queue[5];
int Rear = -1;
int Front = -1;

int main()
{
    int ch;
    while (1)
    {
        printf("\n--------------------------------------\n");
        printf("1.Enqueue\n");
        printf("2.Dequeue\n");
        printf("3.Display\n");
        printf("4.Exit\n");
        printf("Enter operations : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            show();
            break;
        case 4:
            return 0;
            break;
        default:
            printf("Incorrect choice \n");
        }
    }
}

void enqueue()
{
    int data;
    if (Rear == n - 1)
        printf("Overflow \n");
    else
    {
        if (Front == -1)
        {
            Front = 0;
        }

        printf("Enter Element \n : ");
        scanf("%d", &data);
        Rear = Rear + 1;
        queue[Rear] = data;
    }
}

void dequeue()
{
    if (Front == -1 && Rear == -1)
    {
        printf("Underflow \n");
    }
    else if (Front == Rear)
    {
        Front = Rear = -1;
    }
    else
    {
        printf("Element deleted : %d\n", queue[Front]);
        Front = Front + 1;
    }
}

void show()
{

    if (Front == -1)
    {
        printf("Empty Queue \n");
    }
    else
    {
        printf("\n*************************\n");
        printf("Queue:");
        for (int i = Front; i <= Rear; i++)
        {
            printf("%d ", queue[i]);
        }
        printf("\n*************************\n");
    }
}