#include <stdio.h>

#define DIVISOR 3

int main() {
    int min, max, i;
    
    scanf("%d %d", &min, &max);
    
    i = min - min % DIVISOR;
    if ( i < min ) {
        i += DIVISOR;
    }
    
    for ( ; i <= max; i += DIVISOR ) {
        printf("%d\n", i);
    }
    
    return 0;
}
