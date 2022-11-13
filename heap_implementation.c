#include <stdio.h>
#include <stdlib.h>

int heap[100], n=0;

void createHeap(int x) {
    int i;
    if(n == 100) {
        printf("Heap is full");
        return;
    }
    n++;
    i = n;
    while(i > 1 && x < heap[i/2]) {
        heap[i] = heap[i/2];
        i = i/2;
    }
    heap[i] = x;
}

int extractMin() {
    int i, child;
    int min, last;

    if(n == 0) {
        printf("\nHeap is empty");
        return -1;
    }

    min = heap[1];
    last = heap[n];
    n--;
    i = 1;

    while ((i*2) <= n) {
        child = i*2;
        if(child != n && heap[child+1] < heap[child])
            child++;
        if(last > heap[child])
            heap[i] = heap[child];
        else
            break;
        i = child;
    }
    heap[i] = last;
    return min;
}

void printHeap()
{
    int i;
    if(n==0) {
        printf("Error! Heap is empty");
        return;
    }

    printf("Heap: ");
    for(i = 1;i <= n;i++) {
        printf("%d ", heap[i]);
    }
}

int main(void) {
    int choice,x;
    while(1) {
        printf("Enter 1 to insert into heap, 2 to extract min, 3 to display and 4 to exit: ");
        scanf("%d", &choice);
        if (choice == 1) {
            printf("Enter element to be inserted into the heap: ");
            scanf("%d",&x);
            createHeap(x);
        } else if (choice == 2) {
            x = extractMin();
            printf("Element: %d",x);
            break;
        } else if (choice == 3) {
            printHeap();
            break;
        } else if (choice == 4) {
            exit(0);
        } else {
            printf("\nInvalid choice\n");
            exit(0);
        }
    }
}
