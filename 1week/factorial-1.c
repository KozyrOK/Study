#include <stdio.h>

int main() {
    int number;
    int factorial = 1;
    
    scanf("%d", &number);
    
    if ( number < 0 || number > 12 ) {
        printf("-1\n");
    } else if ( number == 0 ) {
        printf("1\n");
    } else {
        for ( char i = 1; i <= number; i++ ) {
            factorial *= i;
        }
    printf("%d\n", factorial);
    }
    return 0;
}
