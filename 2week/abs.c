#include <stdio.h>

void arrayPrintAbs(FILE *in, FILE *out, int size) {
    int array[size];
    int last = size - 1;
    
    for ( int i = 0; i < size && fscanf(in, "%d", &array[i]) == 1; i++ );
    
    for ( int i = 0; i < size; i++ ) {
        if ( array[i] < 0 ) {
            array[i] *= -1;
        }
    }
    
    for ( int i = 0; i < last; i++ ) {
        fprintf(out, "%d ", array[i]);
    }
    fprintf(out, "%d\n", array[last]);
}

int main() {
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    int size;
    
    fscanf(in, "%d", &size);
    arrayPrintAbs(in, out, size);
    
    fclose(in);
    fclose(out);
    
    return 0;
}
