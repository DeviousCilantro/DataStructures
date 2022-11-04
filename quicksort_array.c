/* Quicksort using array via user input */

#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int left, int right, int arr[]) {
    int pivot = arr[right];
    int i = left - 1;
    for (int j = left; j < right; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[right]);
    return i+1;
}

void quickSort(int left, int right, int arr[]) {
    if (left < right) {
        int pivot = partition(left, right, arr);
        quickSort(left, pivot - 1, arr);
        quickSort(pivot + 1, right, arr);
    }
}

int main(void) {
    int n=0;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("Error! The size of the array is invalid\n");
        return 0;
    }
    int *arr = (int *) malloc(n * sizeof(int));
    for (int i=0; i<n; i++) {
        printf("Enter element %d: ", i+1);
        scanf("%d", &arr[i]);
    }
    printf("\n");
    quickSort(0, n-1, arr);
    printf("Final array: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
