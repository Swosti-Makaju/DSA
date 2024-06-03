#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
void insertAtBeginning(struct Node** head_ref, int new_data) { 
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    if (new_node == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}
void deleteAtBeginning(struct Node** head_ref) {  
    if (*head_ref == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }
    struct Node* temp = *head_ref;
*head_ref = (*head_ref)->next;
    free(temp);
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
    insertAtBeginning(&head, 5);
    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 15);    
    printf("Linked list after insertion: ");
    printList(head);
    deleteAtBeginning(&head);
    printf("Linked list after deletion: ");
    printList(head);
    return 0;
}
