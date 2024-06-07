#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};
void insertAtPosition(struct Node** head_ref, int new_data, int position) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    if (new_node == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
   new_node->data = new_data;
  if (position == 1) {
        new_node->next = *head_ref;
        new_node->prev = NULL;
        if (*head_ref != NULL)
            (*head_ref)->prev = new_node;
        *head_ref = new_node;
        return;
    }
    struct Node* current = *head_ref;
    int i;
    for (i = 1; current != NULL && i < position - 1; i++)
        current = current->next;
    if (current == NULL) {
        printf("Position is greater than the number of nodes. Inserting at the end.\n");
        insertAtEnd(head_ref, new_data);
        return;
    }
    new_node->next = current->next;
    if (current->next != NULL)
        current->next->prev = new_node;
    current->next = new_node;
    new_node->prev = current;
}
void deleteAtPosition(struct Node** head_ref, int position) {
    if (*head_ref == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }
    struct Node* current = *head_ref;
    if (position == 1) {
        *head_ref = current->next;
        if (current->next != NULL)
            current->next->prev = NULL;
        free(current);
        return;
    }
    int i;
    for (i = 1; current != NULL && i < position; i++)
        current = current->next;
    if (current == NULL) {
        printf("Position is greater than the number of nodes.\n");
        return;
    }
    if (current->next != NULL)
        current->next->prev = current->prev;
    current->prev->next = current->next;
    free(current);
}
void insertAtEnd(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    if (new_node == NULL) {
        printf("Memory allocation failed.\n");
       return;
    }
    new_node->data = new_data;
    new_node->next = NULL;
    if (*head_ref == NULL) {
        new_node->prev = NULL;
        *head_ref = new_node;
        return;
    }
    struct Node* last = *head_ref;
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
    new_node->prev = last;
}
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main() {
    struct Node* head = NULL;
    insertAtEnd(&head, 5);
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 15);
    printf("Linked list after insertion: ");
    printList(head);
    insertAtPosition(&head, 20, 2);
    printf("Linked list after insertion at position 2: ");
    printList(head);
    deleteAtPosition(&head, 3);
    printf("Linked list after deletion at position 3: ");
    printList(head);
    return 0;
}
