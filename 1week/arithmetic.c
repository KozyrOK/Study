#include <stdio.h>

int main() {
    
    int x, y, plus, minus, mul, div, mod;
    scanf("%d %d", &x , &y);
    
    plus = x + y;
    minus = x - y;
    mul = x * y;
    div = x / y;
    mod = x % y;
    
    printf("%d+%d=%d\n", x, y, plus);
    printf("%d-%d=%d\n", x, y, minus);
    printf("%d*%d=%d\n", x, y, mul);
    printf("%d/%d=%d\n", x, y, div);
    printf("%d%%%d=%d\n", x, y, mod);
    
    return 0;
}
