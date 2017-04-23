#include <stdio.h>

int main() {
    int number;
    
    scanf("%d", &number);
    
    printf("0");
    
    for ( int i = 2; i <= number; i += 2 ) {
        printf(" %d", i);
    }
    
    printf("\n");
    
    return 0;
}
