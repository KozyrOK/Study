#include <stdio.h>

int main() {
    int number, step, member;
    
    scanf("%d %d %d", &number, &step, &member);
    
    for ( ; 1 < member; member-- ) {
        printf("%d ", number);
        number += step;
    }
    printf("%d\n", number);
    
    return 0;
}
