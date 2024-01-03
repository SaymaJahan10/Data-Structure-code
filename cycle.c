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

// Function to check if a linked list contains a cycle and find the cycle start node
bool hasCycle(struct Node* head, int* cycleStartNode) {
    if (head == NULL || head->next == NULL) {
        // No cycle if the list is empty or has only one node
        return false;
    }

    struct Node* slow = head;
    struct Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;      // Move one step at a time
        fast = fast->next->next; // Move two steps at a time

        if (slow == fast) {
            // If they meet, there's a cycle
            slow = head; // Reset one pointer to the head

            while (slow != fast) {
                // Move both pointers one step at a time
                slow = slow->next;
                fast = fast->next;
            }

            *cycleStartNode = slow->data; // Set the cycle start node
            return true;
        }
    }

    return false; // If the fast pointer reaches the end, there's no cycle
}

int main() {
    struct Node* head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);
    head->next->next->next = createNode(40);

    // Create a cycle
    head->next->next->next->next = head;

    int cycleStartNode;
    if (hasCycle(head, &cycleStartNode)) {
        printf("Has Cycle: Yes\n");
        printf("Cycle Start Node: %d\n", cycleStartNode);
    } else {
        printf("Has Cycle: No\n");
    }

    return 0;
}
