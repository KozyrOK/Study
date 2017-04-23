#include <stdio.h>

int main() {
    int currentSpeed, maxSpeed;
    
    scanf("%d %d", &currentSpeed, &maxSpeed);
    
    if ( currentSpeed > maxSpeed ) {
        printf("violation\n");
    } else {
        printf("ok\n");
    }
    
    return 0;
}
