/* Reverses a linked list created fromm user input */

#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node* next;
};

struct Node* linked_list_create(struct Node* head) 
{
    struct Node *temp = NULL;
    int data;
    printf("Enter the values (-999 stops accepting user input): ");
    scanf("%d", &data);
    while (data != -999) {
        if (head == NULL) {
            head = (struct Node *)malloc(sizeof(struct Node));
            head->data = data;
            head->next = NULL;
            temp = head;
        } else {
            temp->next = (struct Node *)malloc(sizeof(struct Node));
            temp = temp->next;
            temp->data = data;
            temp->next = NULL;
        }
        printf("Enter each value: ");
        scanf("%d", &data);
    }
    printf("\n");
    return head;
}

struct Node* linked_list_reverse(struct Node* head) 
{
    struct Node* temp = head;
    struct Node* prev = NULL;
    struct Node* next = NULL;

    while(temp != NULL) {
        next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
    }
    head = prev;
    return head;
}

void linked_list_print(struct Node* head)
{
    struct Node* temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main(void) 
{
    struct Node *head = NULL;
    head = linked_list_create(head);
    head = linked_list_reverse(head);
    printf("\nOutput:\n");
    linked_list_print(head);
}
