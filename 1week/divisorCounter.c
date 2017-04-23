#include <stdio.h>

int main() {
    int dividend;
    int counter = 1;
    
    scanf("%d", &dividend);
    
    for ( int i = dividend / 2; i > 0; i-- ) {
        if ( dividend % i == 0 ) {
            counter += 1;
        }
    }
    
    printf("%d\n", counter);
    
    return 0;
}
