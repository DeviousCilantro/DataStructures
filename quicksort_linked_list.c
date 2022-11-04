/* Quicksort using linked list via user input */

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* partition(struct Node* head, struct Node* tail) {
    struct Node* pivot = head;
    struct Node* temp = head;
    int temp_data;
    while (temp != tail) {
        if (temp->data < tail->data) {
            pivot = head;
            temp_data = temp->data;
            temp->data = pivot->data;
            pivot->data = temp_data;
            head = head->next;
        }
        temp = temp->next;
        
    }
    temp_data = head->data;
    head->data = tail->data;
    tail->data = temp_data;
    return pivot;
    
}

void quickSort(struct Node* head, struct Node* tail) {
    if (head == tail) {
        return;
    }
    struct Node* pivot = partition(head, tail);
 
    if (pivot != NULL && pivot->next != NULL) {
        quickSort(pivot->next, tail);
    }
    if (pivot != NULL && head != pivot) {
        quickSort(head, pivot);
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

int linked_list_length(struct Node* head) {
    struct Node* temp = head;
    int count = 0;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

void linked_list_print(struct Node* head) {
    struct Node* temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(void) {
    struct Node *head = NULL;
    head = linked_list_create(head);
    int lenLL = linked_list_length(head);
    if (lenLL <= 0) {
        printf("Error! Linked list is empty\n");
        return 0;
    }
    struct Node* tail = head;
    while (tail->next != NULL) {
        tail = tail->next;
    }
    quickSort(head, tail);
    printf("\nFinal linked list: ");
    linked_list_print(head);

}
