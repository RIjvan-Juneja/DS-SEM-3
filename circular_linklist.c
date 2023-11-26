#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
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
    newNode->next = NULL;
    return newNode;
}

// Function to display the circular linked list
void displayList() {
    if (head == NULL) {
        printf("Circular Linked List is empty.\n");
        return;
    }

    struct Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("(Head)\n");
}

// Function to insert a node at the end of the circular linked list
void insertAtEnd(int value) {
    struct Node* newNode = createNode(value);

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        struct Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->next = head;
    }

    printf("%d inserted at the end.\n", value);
}

// Function to insert a node before a specified position in the circular linked list
void insertBeforePosition(int position, int value) {
    if (position <= 0) {
        printf("Invalid position. Cannot insert.\n");
        return;
    }

    struct Node* newNode = createNode(value);

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
        printf("%d inserted before position %d.\n", value, position);
        return;
    }

    struct Node* temp = head;
    struct Node* prev = NULL;
    int count = 0;

    do {
        prev = temp;
        temp = temp->next;
        count++;
    } while (temp != head && count < position - 1);

    if (count == 0) {
        newNode->next = head;
        head = newNode;
        struct Node* last = head;
        while (last->next != head) {
            last = last->next;
        }
        last->next = head;
    } else if (count == position - 1) {
        prev->next = newNode;
        newNode->next = temp;
    } else {
        printf("Invalid position. Cannot insert.\n");
        free(newNode);
        return;
    }

    printf("%d inserted before position %d.\n", value, position);
}

// Function to delete the first node of the circular linked list
void deleteFirstNode() {
    if (head == NULL) {
        printf("Circular Linked List is empty. Cannot delete.\n");
        return;
    }

    struct Node* temp = head;

    if (head->next == head) {
        head = NULL;
    } else {
        while (temp->next != head) {
            temp = temp->next;
        }

        temp->next = head->next;
        head = head->next;
    }

    free(temp);
    printf("First node deleted.\n");
}

// Function to delete a node after a specified position in the circular linked list
void deleteAfterPosition(int position) {
    if (position < 0) {
        printf("Invalid position. Cannot delete.\n");
        return;
    }

    if (head == NULL) {
        printf("Circular Linked List is empty. Cannot delete.\n");
        return;
    }

    struct Node* temp = head;
    struct Node* prev = NULL;
    int count = 0;

    do {
        prev = temp;
        temp = temp->next;
        count++;
    } while (temp != head && count < position);

    if (count == position) {
        if (temp->next == head) {
            printf("No node after position %d. Cannot delete.\n", position);
            return;
        }

        prev = temp;
        temp = temp->next;
        prev->next = temp->next;
        free(temp);
        printf("Node after position %d deleted.\n", position);
    } else {
        printf("Invalid position. Cannot delete.\n");
    }
}

int main() {
    int choice, position, value;

    while (1) {
        printf("\nMENU\n");
        printf("1. Insert at End\n");
        printf("2. Insert Before Position\n");
        printf("3. Delete First Node\n");
        printf("4. Delete After Position\n");
        printf("5. Display\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert at the end: ");
                scanf("%d", &value);
                insertAtEnd(value);
                break;

            case 2:
                printf("Enter the position before which node should be inserted: ");
                scanf("%d", &position);
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                insertBeforePosition(position, value);
                break;

            case 3:
                deleteFirstNode();
                break;

            case 4:
                printf("Enter the position after which node should be deleted: ");
                scanf("%d", &position);
                deleteAfterPosition(position);
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
