#include <stdio.h>

int main() {
    int amount, current, max;
    
    scanf("%d %d", &amount, &max);
    for ( ; amount > 1; amount-- ) {
        scanf("%d", &current);
        if ( max < current ) {
            max = current;
        }
    }
    printf("%d\n", max);
    
    return 0;
}
