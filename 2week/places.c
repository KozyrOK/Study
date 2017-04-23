#include <stdio.h>

int main() {
    int input;
    int amountSymbols = 1;
    
    scanf("%d", &input);
    
    if ( input < 0 ) {
        input *= -1;
        amountSymbols += 1;
    }
    
    for ( ; input > 9; input /= 10 ) {
        amountSymbols += 1;
    }
    
    printf("%d\n", amountSymbols);
    
    return 0;
}
