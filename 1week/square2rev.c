#include <stdio.h>

int main() {
    int size, counter;
    
    scanf("%d", &size);
    
    for ( int row = 1; row < size + 1; row++ ) {
        counter = (size * size) - (size * row) + 1;
        for ( int column = 1; column < size; column++, counter++ ) {
            printf("%d ", counter);
        }
        printf("%d\n", counter);
    }
    
    return 0;
}
