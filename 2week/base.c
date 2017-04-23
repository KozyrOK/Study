#include <stdio.h>

int powerBase(int base, int power) {
    int result = 1;
    
    for ( int i = 1; i <= power; i++ ) {
        result *= base;
    }
    return result;
}

int main() {
    int number10, base;
    int power = 0;
    
    scanf("%d %d", &number10, &base);
    if ( number10 < 0 ) {
        number10 *= -1;
        printf("-");
    }
    
    for ( int dividend = number10 / base; dividend > 0; dividend /= base ) {
        power += 1;
    }
    
    for ( ; power > -1; power-- ) {
        int basePower = powerBase(base, power);
        int numberXX = number10 / basePower;
        
        printf("%d", numberXX);
        number10 %= basePower;
    }
    printf("\n");
    
    return 0;
}
