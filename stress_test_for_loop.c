#include <stdio.h>

int main(void){
    for (float x = 0.0; x < 0.000000000000000000010; x += 0.000000000000000000001)
        printf("Hello, World\n");
    return 0;
}
