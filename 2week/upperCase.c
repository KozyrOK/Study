#include <stdio.h>

int main() {
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    
    for ( char temp; fscanf(in, "%c", &temp) != EOF; ) {
        if ( temp > 96 && temp < 123 ) {
            fprintf(out, "%c", temp-32);
        } else {
            fprintf(out, "%c", temp);
        }
    }
    fprintf(out, "\n");
    fclose(in);
    fclose(out);
    
    return 0;
}
