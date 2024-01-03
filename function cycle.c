#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

// Function to check if a linked list contains a cycle
bool hasCycle(struct Node* head) {
    struct Node* slow = head;
    struct Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;      // Move one step at a time
        fast = fast->next->next; // Move two steps at a time

        if (slow == fast) {
            return true; // If they meet, there's a cycle
        }
    }

    return false; // If the fast pointer reaches the end, there's no cycle
}

int main() {
    struct Node* head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);
    head->next->next->next = createNode(40);
    head->next->next->next->next = head; // Create a cycle

    if (hasCycle(head)) {
        printf("Has Cycle: Yes\n");

        // Find the starting node of the cycle
        struct Node* slow = head;
        struct Node* fast = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                slow = head;
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                printf("Cycle Start Node: %d\n", slow->data);
                break;
            }
        }
    } else {
        printf("Has Cycle: No\n");
    }

    return 0;
}
