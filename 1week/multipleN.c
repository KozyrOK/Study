#include <stdio.h>

int main() {
    int max, divisor;
    
    scanf("%d %d", &max, &divisor);
    
    if ( divisor < 0 ) {
        divisor *= -1;
    }
    max -= max % divisor;
    
    for ( int i = 0; i < max; i += divisor ) {
        printf("%d ", i);
    }
    printf("%d\n", max);
    
    return 0;
}