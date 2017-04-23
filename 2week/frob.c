#include <stdio.h>

int main() {
    int length;
    int variable;
    
    scanf("%d", &length);
    
    for ( int i = 0; i < length; i++ ) {
        scanf("%d", &variable);
        printf("%d\n", variable^42);
    }
    
    return 0;
}