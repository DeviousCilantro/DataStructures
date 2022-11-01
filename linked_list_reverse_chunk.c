/* Chunk-reverses a linked list created from user input */
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node* next;
};

struct Node* createLL(struct Node* head) {
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

struct Node* reverse(struct Node* head, int j)
{
    struct Node* temp = head;
    struct Node* prev = NULL;
    struct Node* next = NULL;
    while(j>0 && temp != NULL) {
        next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
        j--;
    }
    if (temp != NULL) {
        head->next = temp;
    }
    head = prev;
    return head;
}

void linked_list_print(struct Node* head)
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
    head = createLL(head);
    int j;
    printf("Enter node to reverse: ");
    scanf("%d", &j);
    head = reverse(head, j);
    linked_list_print(head);
}
