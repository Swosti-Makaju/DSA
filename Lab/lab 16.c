#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void insertAtBeginning(struct Node** head_ref, int data) {
    struct Node* newNode = createNode(data);
    if (*head_ref == NULL) {
        newNode->next = newNode;
        *head_ref = newNode;
    } else {
        struct Node* last = *head_ref;
        while (last->next != *head_ref) {
            last = last->next;
        }
        newNode->next = *head_ref;
        last->next = newNode;
        *head_ref = newNode;
    }
}
void deleteNode(struct Node** head_ref, int key) {
    if (*head_ref == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }
    struct Node *temp = *head_ref, *prev;
    if (temp->data == key && temp->next == *head_ref) {
        free(temp);
        *head_ref = NULL;
        return;
    }
    if (temp->data == key) {
        while (temp->next != *head_ref)
            temp = temp->next;
        temp->next = (*head_ref)->next;
        free(*head_ref);
        *head_ref = temp->next;
    }
    while (temp->next != *head_ref && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp->data != key) {
        printf("Node with data %d not found in the list.\n", key);
        return;
    }
    prev->next = temp->next;
    free(temp);
}
void printList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head)\n");
}
int main() {
    struct Node* head = NULL;
    insertAtBeginning(&head, 5);
    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 15);
    printf("Initial circular linked list: ");
    printList(head);
    deleteNode(&head, 10);
    printf("Circular linked list after deletion: ");
    printList(head);
    return 0;
}
