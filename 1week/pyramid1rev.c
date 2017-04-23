#include <stdio.h>

int main() {
    int size;
    
    scanf("%d", &size);
    
    for ( int row = size; row > 0; row-- ) {
        for ( int column = 1; column < row; column++ ) {
            printf("%d ", column);
        }
        printf("%d\n", row);
    }
    
    return 0;
}
