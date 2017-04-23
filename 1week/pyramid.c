#include <stdio.h>

int main() {
    int total, rows, cols;
    
    scanf("%d %d %d", &total, &rows, &cols);
    
    if ( cols > rows ) {
        rows = cols;
    }
    for ( int row = rows + 1; row <= total; row++ ) {
        int column;
        
        for ( column = cols + 1; column < row; column++ ) {
            printf("%d ", column);
        }
        printf("%d\n", column);
    }
    
    return 0;
}
