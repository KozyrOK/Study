#include <stdio.h>

int main() {
    int total;
    int counter = 1;
    
    scanf("%d", &total);
    for ( int row = 0; row < total; row++, counter++ ) {
        for ( int column = 0; column < row; column++, counter++ ) {
            printf("%d ", counter);
        }
        
        printf("%d\n", counter);
    }
    
    return 0;
}
