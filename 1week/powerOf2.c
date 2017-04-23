#include <stdio.h>

int main() {
    int power;
    int total = 1;
    
    printf("1");
    scanf("%d", &power);
    
    for ( int i = 1; i < power + 1; i++ ) {
        total *= 2;
        printf(" %d", total);
    }
    
    printf("\n");
    return 0;
}
