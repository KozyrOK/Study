#include <stdio.h>

int main() {
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    int value, counter;
    
    for ( counter = 0; fscanf(in, "%d", &value) == 1 && counter < 100; counter++ );
    
    fclose(in);
    fprintf(out, "%d\n", counter);
    fclose(out);
    
    return 0;
}
