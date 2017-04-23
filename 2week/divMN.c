#include <stdio.h>

int gcd(int a, int b) {
    if ( b == 0 ) {
        return a;
    }
    return gcd(b, a%b);
}

int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

int main() {
    int min, max, m, n, dividend;
    
    scanf("%d %d %d %d", &min, &max, &m, &n);
    
    dividend = lcm(m, n);
    
    if ( min < 0 ) {
        min -= min % dividend;
    } else if ( min % dividend != 0 ) {
        min += dividend - min % dividend;
    }
    for ( int i = min; i <= max; i += dividend ) {
        printf("%d\n", i);
    }
    
    return 0;
}
