#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

int front = -1;
int rear = -1;
int queue[MAX_SIZE];

// Function to check if the queue is empty
int isEmpty() {
    return (front == -1);
}

// Function to check if the queue is full
int isFull() {
    return ((front == 0 && rear == MAX_SIZE - 1) || (rear == (front - 1) % (MAX_SIZE - 1)));
}

// Function to enqueue an element to the circular queue
void enqueue(int data) {
    if (isFull()) {
        printf("Queue is full. Cannot enqueue %d\n", data);
        return;
    }

    if (isEmpty())
        front = 0;

    rear = (rear + 1) % MAX_SIZE;
    queue[rear] = data;
    printf("%d enqueued to the queue\n", data);
}

// Function to dequeue an element from the circular queue
int dequeue() {
    if (isEmpty()) {
        printf("Queue is empty. Cannot dequeue\n");
        return -1;
    }

    int data = queue[front];

    if (front == rear)
        front = rear = -1; // Queue is now empty
    else
        front = (front + 1) % MAX_SIZE;

    printf("%d dequeued from the queue\n", data);
    return data;
}

// Function to display the elements in the circular queue
void display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }

    printf("Elements in the queue: ");
    int i = front;
    do {
        printf("%d ", queue[i]);
        i = (i + 1) % MAX_SIZE;
    } while (i != (rear + 1) % MAX_SIZE);

    printf("\n");
}

int main() {
    int choice, data;

    while (1) {
        printf("\nCircular Queue Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to enqueue: ");
                scanf("%d", &data);
                enqueue(data);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}
