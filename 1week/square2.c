#include <stdio.h>

int main() {
    int size, counter;
    
    scanf("%d", &size);
    
    counter = 1;
    for ( int row = 0; row < size; row++, counter++ ) {
        for ( int column = 1; column < size; column++, counter++ ) {
            printf("%d ", counter);
        }
        printf("%d\n", counter);
    }
    
    return 0;
}
