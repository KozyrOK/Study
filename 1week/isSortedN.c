#include <stdio.h>

int main() {
    int len, min, current;
       
    scanf("%d %d", &len, &min);
    
    for ( int i = 0; i < len; i++ ) {
        scanf("%d", &current);
        if ( min > current ) {
        printf("no\n");
        return 0;
        } else {
        min = current;
        }
    }
       
    printf("yes\n");
    return 0;
}
