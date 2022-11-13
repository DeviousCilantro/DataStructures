#include <stdio.h>

int main(){
    int x;
    int  *pointerX;
    x = 7;
    pointerX = &x;
    printf("Value of x: %d\n", x);
    printf("Memory location of x: %d\n", pointerX);
    *pointerX = 54;
    printf("New value at location %d: %d\n", pointerX, x);
    return 0;
}
