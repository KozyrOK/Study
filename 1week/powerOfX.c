#include <stdio.h>

int main() {
    int base, power;
    int total = 1;
    
    scanf("%d %d", &base, &power);
    
    printf("1");
    for ( int i = 1; i < power + 1; i++ ) {
        total *= base;
        printf(" %d", total);
    }
    printf("\n");
    
    return 0;
}
