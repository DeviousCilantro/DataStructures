/* Insertion sort using linked lists via user input */

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
} Node;

void insertionSort(struct Node *head) {

    for(struct Node* temp_i = head; temp_i != NULL; temp_i = temp_i->next) {

        for (struct Node* temp_j = head; temp_j != temp_i; temp_j = temp_j->next) {

            if (temp_i->data < temp_j->data) {
                int temp = temp_i->data;
                temp_i->data = temp_j->data;
                temp_j->data = temp;
            }
        }
    }
}

struct Node* linked_list_create(struct Node* head) {
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

void linked_list_print(struct Node* head) {
    struct Node* temp = head;
    
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(void)
{
    struct Node *head = NULL;
    head = linked_list_create(head);
    insertionSort(head);
    printf("Final linked list: ");
    linked_list_print(head);
}
