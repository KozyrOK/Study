#include <stdio.h>

int arraySearch(FILE *in, int size, int needle) {
    int array[size];
    
    for ( int i = 0; i < size && fscanf(in, "%d", &array[i]) == 1; i++ ) {
        if ( array[i] == needle ) {
            return i;
        }
    }
    return -1;
}

int main() {
    int needle;
    int size = 100;
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    
    fscanf(in, "%d", &needle);
    fprintf(out, "%d\n", arraySearch(in, size, needle));
    
    fclose(in);
    fclose(out);
    
    return 0;
}
