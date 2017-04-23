#include <stdio.h>

int main() {
    int a;
    int flag = 1;
    
    scanf("%d", &a);
    
    if ( a % 2 == 0 ) {
        printf("alpha\n");
        flag = 0;
    }
    if ( a % 3 == 0 ) {
        printf("bravo\n");
        flag = 0;
    }
    if ( a % 5 == 0 ) {
        printf("charlie\n");
        flag = 0;
    }
    if ( flag ) {
        printf("zulu\n");
    }
    
    return 0;
}
