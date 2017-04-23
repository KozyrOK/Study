#include <stdio.h>

int main() {
    int number, divisor;
    
    scanf("%d", &number);
    for ( divisor = number / 2; divisor > 1; divisor-- ) {
        if ( number % divisor == 0 ) {
            printf("%d\n", divisor);
            return 0;
        }
    }
    printf("0\n");
    
    return 0;
}
