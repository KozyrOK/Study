#include <stdio.h>

int main() {
    int number;
    
    scanf("%d", &number);
    
    printf("0");
    
    for ( int i = 3; i <= number; i += 3 ) {
        printf(" %d", i);
    }
    
    printf("\n");
    
    return 0;
}
