#include <stdio.h>

int main() {
    int organism, hour;
    
    scanf("%d %d", &organism, &hour);
    
    for ( int i = 1; i <= hour; i++ ) {
        organism *=2;
        printf("%dh => %d amoeba(s)\n", i, organism);
    }
    
    return 0;
}
