#include <stdio.h>

int main() {
    int number;
    
    scanf("%d", &number);
    
    printf("1");
    
    for ( int i = 3; i <= number; i += 2 ) {
        printf(" %d", i);
    }
    
    printf("\n");
    
    return 0;
}
