/* Selection sort using arrays */

#include <stdio.h>
#include <stdlib.h>

void selectionSort(int a[], int n)
{
    for(int i=0; i<n; i++) {
        int smallest = a[i];
        int smallestIndex = i;
        
        for(int j=i+1; j<n; j++) {
            if (a[j] < smallest) {
                smallest = a[j];
                smallestIndex = j;
            }
        }
        int temp = a[i];
        a[i] = smallest;
        a[smallestIndex] = temp;
        
    }
}


int main(void) 
{

    int n = 0;
    printf("Enter the number of elements to be sorted: ");
    scanf("%d", &n);

    int *a = (int *) malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        printf("\nEnter each element: ", i+1);
        scanf("%d", &a[i]);
    }
    printf("\n");
    selectionSort(a, n);
    printf("Array after sorting: ");
    for (int i=0; i<n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}
