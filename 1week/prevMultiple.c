#include <stdio.h>

int main() {
    int dividend, divisor, rest;
    
    scanf("%d %d", &dividend, &divisor);
    
    if ( divisor < 0 ) {
        divisor *= -1;
    }
    rest = dividend % divisor;
    if ( rest < 0 ) {
        dividend -= divisor;
    }
    printf("%d\n", dividend-rest);
    
    return 0;
}
