#include <stdio.h>

#define DIVISOR 2

int main() {
    int min, max;
    
    scanf("%d %d", &min, &max);
    
    if ( min % DIVISOR != 0 ) {
        min += 1;
    }
    
    for ( int i = min; i <= max; i += DIVISOR ) {
        printf("%d\n", i);
    }
    
    return 0;
}
