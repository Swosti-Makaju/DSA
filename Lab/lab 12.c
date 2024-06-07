#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
void insertAtPosition(struct Node** head_ref, int new_data, int position) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    if (new_node == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    new_node->data = new_data;
    if (*head_ref == NULL || position == 1) {
        new_node->next = *head_ref;
        *head_ref = new_node;
        return;
    }
    struct Node* current = *head_ref;
    for (int i = 1; i < position - 1 && current != NULL; i++) {
        current = current->next;
    }
    if (current == NULL) {
        printf("Position is greater than the number of nodes. Inserting at the end.\n");
        current = *head_ref;
        while (current->next != NULL) {
            current = current->next;
        }
    }
   new_node->next = current->next;
    current->next = new_node;
}
void deleteAtPosition(struct Node** head_ref, int position) {
    if (*head_ref == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }
    struct Node* temp = *head_ref;
    if (position == 1) {
        *head_ref = temp->next; 
        free(temp);             
        return;
    }
    for (int i = 1; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        printf("Position is greater than the number of nodes.\n");
        return;
    }
    struct Node* next_node = temp->next->next;
    free(temp->next); 
    temp->next = next_node;  
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
    insertAtPosition(&head, 5, 1);  
    insertAtPosition(&head, 10, 2);  
    insertAtPosition(&head, 15, 3);  
    printf("Linked list after insertion: ");
    printList(head);
    deleteAtPosition(&head, 2);  
    printf("Linked list after deletion: ");
    printList(head);
    return 0;
}
