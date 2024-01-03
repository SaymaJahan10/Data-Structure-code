#include <stdio.h>
#include <stdlib.h>
struct Node {
int data;
struct Node* next;
};
struct Node* createNode(int data) {
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
newNode->data = data;
newNode->next = NULL;
return newNode;
}
struct Node* reverseLinkedList(struct Node* head) {
struct Node *prev = NULL, *current = head, *next = NULL;
while (current != NULL) {
next = current->next;
current->next = prev;
prev = current;
current = next;
}
return prev;
}
void printLinkedList(struct Node* head) {
struct Node* current = head;
while (current != NULL) {
printf("%d -> ", current->data);
current = current->next;
}
printf("NULL\n");
}
int main() {
struct Node* head = createNode(5);
head->next = createNode(25);
head->next->next = createNode(20);

printf("Original Linked List: ");
printLinkedList(head);
head = reverseLinkedList(head);
printf("Reversed Linked List: ");
printLinkedList(head);
return 0;
}
