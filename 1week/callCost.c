#include <stdio.h>

int main() {
    int phoneNum, min;
    
    scanf("%d %d", &phoneNum, &min);
    
    if ( phoneNum == 101 || phoneNum == 102 || phoneNum == 103 || phoneNum == 104 || phoneNum == 112 ) {
        printf("0$\n");
    } else if ( phoneNum > 99 && phoneNum < 1000 ) {
        printf("%d$\n", 40*min);
    } else if ( phoneNum > 999999 && phoneNum < 10000000 ) {
        printf("%d$\n", min);
    } else {
        printf("-1\n");
    }
    
    return 0;
}
