
#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to merge two sorted linked lists
struct Node* mergeSortedLists(struct Node* listA, struct Node* listB) {
    struct Node* mergedList = NULL; // Initialize the merged list
    struct Node* tail = mergedList;

    while (1) {
        if (listA == NULL) {
            // If listA is empty, append the remaining of listB
            tail->next = listB;
            break;
        }
        if (listB == NULL) {
            // If listB is empty, append the remaining of listA
            tail->next = listA;
            break;
        }

        if (listA->data <= listB->data) {
            if (mergedList == NULL) {
                mergedList = tail = listA;
            } else {
                tail->next = listA;
                tail = listA;
            }
            listA = listA->next;
        } else {
            if (mergedList == NULL) {
                mergedList = tail = listB;
            } else {
                tail->next = listB;
                tail = listB;
            }
            listB = listB->next;
        }
    }

    return mergedList;
}

// Function to print a linked list
void printLinkedList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* listA = createNode(5);
    listA->next = createNode(10);

    struct Node* listB = createNode(7);
    listB->next = createNode(12);

    printf("List A: ");
    printLinkedList(listA);

    printf("List B: ");
    printLinkedList(listB);

    struct Node* mergedList = mergeSortedLists(listA, listB);

    printf("Merged List: ");
    printLinkedList(mergedList);

    return 0;
}
