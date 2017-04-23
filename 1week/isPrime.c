#include <stdio.h>

int isPrime(int n) {
    if ( n < 2 ) {
        return 0;
    }
    for ( int i = n / 2; i > 1; i-- ) {
        if ( n % i == 0 ) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int primeN, n;
    int prime = 2;
    
    scanf("%d", &primeN);
    
    if ( primeN < 1 ) {
        printf("-1\n");
        return 0;
    } else {
        for ( int i = 0; i < primeN; i++ ) {
            for ( n = prime; isPrime(n) == 0; n++ ) {
                prime = n + 1;
            }
            prime += 1;
        }
    }
    printf("%d\n", n);
    
    return 0;
}
