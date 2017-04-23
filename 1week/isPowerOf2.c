#include <stdio.h>

int powerOf2(int digit) {
    unsigned currentDigit = 2;
    
    for ( char i = 0; i < 33; i++ ) {
        if ( currentDigit == digit ) {
            return 1;
        } else if ( currentDigit > digit ) {
            return 0;
        } else {
            currentDigit *= 2;
        }
    }
    return 0;
}

int main() {
    int digit;
    
    scanf("%d", &digit);
    if ( digit < 1 ) {
        printf("no\n");
    } else if ( digit == 1 ) {
        printf("yes\n");
        return 0;
    } else if ( digit % 2 != 0 ) {
        printf("no\n");
        return 0;
    } else if ( powerOf2(digit) == 1 ) {
        printf("yes\n");
    } else {
        printf("no\n");
    }
    return 0;
}
