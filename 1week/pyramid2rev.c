#include <stdio.h>

int main() {
    int size, counter;
    int rowCounter = 1;
    
    scanf("%d", &size);
    for ( int row = size; row > 1; row--, rowCounter++ ) {
        counter = (size * size) - (size * rowCounter + 2);
        for ( int column = 1; column < row; column++, counter++ ) {
            printf("%d ", counter);
        }
        if ( counter < 0 ) {
            counter *= -1;
        }
        printf("%d\n", counter);
    }
    printf("1\n");
    return 0;
}



#include <stdio.h>

int start(int x) {
    int count = 0;
    
    for ( int i = 0; i < x; i++ ) {
        for ( int j = 0; j <= i; j++ ) {
            count += 1;
        }
    }
    return count - x + 1;
}

int main() {
    int size;
    int count = 0;
    
    scanf("%d", &size);
    
    count = start(size);
    
    for ( int i = 1; i <= size; i++ ) {
        for ( int j = 1; j <= size - i; j++ ) {
            printf("%d ", count);
            count += 1;
        }
        printf("%d\n", count);
        count = start(size-i);
    }
    
    return 0;
}

