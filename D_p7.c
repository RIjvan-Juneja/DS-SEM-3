#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

// Function to display the linked list
void displayList() {
    struct Node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to insert a node at the front of the linked list
void insertAtFront(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    head = newNode;
    printf("%d inserted at the front.\n", value);
}

// Function to insert a node at the end of the linked list
void insertAtEnd(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    printf("%d inserted at the end.\n", value);
}

// Function to insert a node in ascending order
void insertInAscending(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    if (head == NULL || value < head->data) {
        newNode->next = head;
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL && temp->next->data < value) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    printf("%d inserted in ascending order.\n", value);
}

// Function to delete the first node of the linked list
void deleteFirstNode() {
    if (head == NULL) {
        printf("Linked List is empty. Cannot delete.\n");
        return;
    }

    struct Node* temp = head;
    head = head->next;
    printf("%d deleted from the front.\n", temp->data);
    free(temp);
}

// Function to delete a node before a specified position
void deleteBeforePosition(int position) {
    if (head == NULL || position <= 1) {
        printf("Invalid position or Linked List is empty. Cannot delete.\n");
        return;
    }

    struct Node* temp = head;
    struct Node* prev = NULL;

    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("Invalid position. Cannot delete.\n");
        return;
    }

    if (prev == NULL) {
        head = temp->next;
    } else {
        prev->next = temp->next;
    }

    printf("Node before position %d deleted.\n", position);
    free(temp);
}

// Function to delete a node after a specified position
void deleteAfterPosition(int position) {
    if (head == NULL || position < 0) {
        printf("Invalid position or Linked List is empty. Cannot delete.\n");
        return;
    }

    struct Node* temp = head;
    for (int i = 1; i < position && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("Invalid position. Cannot delete.\n");
        return;
    }

    struct Node* deleteNode = temp->next;
    temp->next = deleteNode->next;

    printf("Node after position %d deleted.\n", position);
    free(deleteNode);
}

int main() {
    int choice, value, position;

    while (1) {
        printf("\nMENU\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at End\n");
        printf("3. Insert in Ascending Order\n");
        printf("4. Delete First Node\n");
        printf("5. Delete Before Position\n");
        printf("6. Delete After Position\n");
        printf("7. Display\n");
        printf("8. Exit\n");

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
                printf("Enter the value to insert in ascending order: ");
                scanf("%d", &value);
                insertInAscending(value);
                break;

            case 4:
                deleteFirstNode();
                break;

            case 5:
                printf("Enter the position before which node should be deleted: ");
                scanf("%d", &position);
                deleteBeforePosition(position);
                break;

            case 6:
                printf("Enter the position after which node should be deleted: ");
                scanf("%d", &position);
                deleteAfterPosition(position);
                break;

            case 7:
                displayList();
                break;

            case 8:
                exit(0);

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}
