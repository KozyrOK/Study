#include <stdio.h>

int main() {
    int number, factorial;
    
    scanf("%d", &number);
    
    if ( number < 0 || number > 12 ) {
        printf("-1\n");
    } else if ( number == 0 ) {
        printf("1\n");
    } else {
        for ( factorial = 1; number > 1; number-- ) {
            factorial *= number;
        }
        printf("%d\n", factorial);
    }
    
    return 0;
}
