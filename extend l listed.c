#include <stdio.h>
#include <stdlib.h>

// Define a struct for a singly linked list node.
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node.
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node after a specific value.
void insertAfterValue(struct Node* head, int valueToInsertAfter, int dataToInsert) {
    struct Node* current = head;
    while (current != NULL) {
        if (current->data == valueToInsertAfter) {
            struct Node* newNode = createNode(dataToInsert);
            newNode->next = current->next;
            current->next = newNode;
            return;
        }
        current = current->next;
    }
    printf("Value %d not found in the list.\n", valueToInsertAfter);
}

// Function to delete a node with a given value.
void deleteNodeByValue(struct Node* head, int valueToDelete) {
    struct Node* current = head;
    struct Node* prev = NULL;
    while (current != NULL) {
        if (current->data == valueToDelete) {
            if (prev == NULL) {
                // If the node to delete is the head node.
                head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
    printf("Value %d not found in the list.\n", valueToDelete);
}

// Function to insert a node at a given position.
void insertAtPosition(struct Node* head, int position, int dataToInsert) {
    if (position < 1) {
        printf("Invalid position.\n");
        return;
    }

    struct Node* newNode = createNode(dataToInsert);
    if (position == 1) {
        // Insert at the beginning.
        newNode->next = head;
        head = newNode;
        return;
    }

    struct Node* current = head;
    int currentPosition = 1;
    while (currentPosition < position - 1 && current != NULL) {
        current = current->next;
        currentPosition++;
    }

    if (current == NULL) {
        printf("Position %d is beyond the length of the list.\n", position);
    } else {
        newNode->next = current->next;
        current->next = newNode;
    }
}

// Function to delete a node at a given position.
void deleteNodeByPosition(struct Node* head, int position) {
    if (position < 1) {
        printf("Invalid position.\n");
        return;
    }

    if (position == 1) {
        // Deleting the head node.
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return;
    }

    struct Node* current = head;
    struct Node* prev = NULL;
    int currentPosition = 1;
    while (currentPosition < position && current != NULL) {
        prev = current;
        current = current->next;
        currentPosition++;
    }

    if (current == NULL) {
        printf("Position %d is beyond the length of the list.\n", position);
    } else {
        prev->next = current->next;
        free(current);
    }
}

// Function to print the linked list.
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = createNode(5);

    // Insert 25 after 10.
    insertAfterValue(head, 10, 25);

    // Delete the node with the value 10.
    deleteNodeByValue(head, 10);

    // Insert 20 at position 2.
    insertAtPosition(head, 2, 20);

    // Delete the node at position 3.
    deleteNodeByPosition(head, 3);

    // Print the linked list.
    printf("Linked List: ");
    printList(head);

    return 0;
}
