/* Implements insertion sort using arrays via user input */

#include <stdio.h>
#include <stdlib.h>

void insertionSort(int arr[], int n)
{
    int j, k;
    for (int i=0; i<n; i++) {
        k = arr[i];
        j = i-1;
        while (j >= 0 && arr[j] > k) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = k;
    }
}

int main(void)
{
    int n = 0;
    printf("Enter the number of elements to be sorted: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("Error! The size of the array is invalid\n");
        return 0;
    }
    int *arr = (int *) malloc(n * sizeof(int));
    for (int i=0; i<n; i++) {
        printf("Enter each element: ", i+1);
        scanf("%d", &arr[i]);
    }
    printf("\n");
    insertionSort(arr, n);
    printf("Sorted array: ");
    for(int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
