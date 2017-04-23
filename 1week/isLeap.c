#include <stdio.h>

int main() {
    int leap;

    scanf("%d", &leap);

    if ( leap == 366 ) {
        printf("yes\n");
    } else if ( leap == 365 ) {
        printf("no\n");
    } else {
        printf("Invalid param\n");
    }

    return 0;
}     