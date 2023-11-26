#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL;

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to display the doubly linked list
void displayList() {
    struct Node* temp = head;
    printf("Doubly Linked List: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to insert a node at the front of the linked list
void insertAtFront(int value) {
    struct Node* newNode = createNode(value);

    if (head == NULL) {
        head = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    printf("%d inserted at the front.\n", value);
}

// Function to insert a node at the end of the linked list
void insertAtEnd(int value) {
    struct Node* newNode = createNode(value);

    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }

    printf("%d inserted at the end.\n", value);
}

// Function to delete the last node of the linked list
void deleteLastNode() {
    if (head == NULL) {
        printf("Linked List is empty. Cannot delete.\n");
        return;
    }

    if (head->next == NULL) {
        free(head);
        head = NULL;
        printf("Last node deleted.\n");
        return;
    }

    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->prev->next = NULL;
    free(temp);
    printf("Last node deleted.\n");
}

// Function to delete a node before a specified position
void deleteBeforePosition(int position) {
    if (head == NULL || position <= 1) {
        printf("Invalid position or Linked List is empty. Cannot delete.\n");
        return;
    }

    struct Node* temp = head;

    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->prev == NULL) {
        printf("Invalid position. Cannot delete.\n");
        return;
    }

    struct Node* deleteNode = temp->prev;
    temp->prev = deleteNode->prev;

    if (temp->prev != NULL) {
        temp->prev->next = temp;
    } else {
        head = temp;
    }

    free(deleteNode);
    printf("Node before position %d deleted.\n", position);
}

int main() {
    int choice, value, position;

    while (1) {
        printf("\nMENU\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at End\n");
        printf("3. Delete Last Node\n");
        printf("4. Delete Before Position\n");
        printf("5. Display\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert at the front: ");
                scanf("%d", &value);
                insertAtFront(value);
                break;

            case 2:
                printf("Enter the value to insert at the end: ");
                scanf("%d", &value);
                insertAtEnd(value);
                break;

            case 3:
                deleteLastNode();
                break;

            case 4:
                printf("Enter the position before which node should be deleted: ");
                scanf("%d", &position);
                deleteBeforePosition(position);
                break;

            case 5:
                displayList();
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}
