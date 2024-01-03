#include <stdio.h>
#include <stdlib.h>
struct Node {
int data;
struct Node *next;
};
struct Node *createNode(int data) {
struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
newNode->data = data;
newNode->next = NULL;
return newNode;
}
struct Node *addToBeginning(struct Node *head, int data) {
struct Node *newNode = createNode(data);
newNode->next = head;
return newNode;
}
struct Node *addToEnd(struct Node *head, int data) {
struct Node *newNode = createNode(data);
if (head == NULL) {
return newNode;
}
struct Node *current = head;
while (current->next != NULL) {
current = current->next;
}
current->next = newNode;
return head;
}
void printLinkedList(struct Node *head) {
struct Node *current = head;
while (current != NULL) {
printf("%d", current->data);
if (current->next != NULL) {
printf(" -> ");
 }
current = current->next;
}
printf("\n");
}
int main() {
struct Node *head = NULL;
head = addToBeginning(head, 5);
head = addToEnd(head, 10);
head = addToEnd(head, 15);
printf("Linked List: ");
printLinkedList(head);
return 0;
}
