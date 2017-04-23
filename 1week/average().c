#include <stdio.h>

unsigned int average(unsigned int a, unsigned int b) {
    return a / 2 + b / 2 + (a % 2 + b % 2) / 2;
}

int main() {
    unsigned int a, b;
    
    scanf("%u %u", &a, &b);
    
    printf("%u\n", average(a, b));
    
    return 0;
}
