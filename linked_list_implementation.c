/* Creates a linked list, given user input */

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node *next;
};

struct Node* linked_list_create(struct Node* head) {
    struct Node *temp = NULL;
    int value;
    printf("Enter the values (-999 stops user input): ");
    scanf("%d", &value);
    while (value != -999) {
        if (head == NULL) {
            head = (struct Node *)malloc(sizeof(struct Node));
            head->value = value;
            head->next = NULL;
            temp = head;
        } else {
            temp->next = (struct Node *)malloc(sizeof(struct Node));
            temp = temp->next;
            temp->value = value;
            temp->next = NULL;
        }
        printf("Enter each value: ");
        scanf("%d", &value);
    }
    printf("\n");
    return head;
}

void linked_list_display(struct Node* head)
{
    struct Node* temp = head;
    while(temp != NULL) {
        printf("%d ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}

int main(void) 
{
    struct Node *head = NULL;
    head = linked_list_create(head);
    linked_list_display(head);
}
