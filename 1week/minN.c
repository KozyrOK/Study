#include <stdio.h>

int main() {
    int amount, current, min;
    
    scanf("%d %d", &amount, &min);
    for ( ; amount > 1; amount-- ) {
        scanf("%d", &current);
        if ( min > current ) {
            min = current;
        }
    }
    printf("%d\n", min);
    
    return 0;
}
