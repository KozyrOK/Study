#include <stdio.h>

int main() {
    int number;
    
    scanf("%d", &number);
    
    printf("0");
    
    for ( int i = 5; i <= number; i += 5 ) {
        printf(" %d", i);
    }
    
    printf("\n");
    
    return 0;
}
