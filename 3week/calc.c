#include <stdio.h>

int main() {
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    float number[101];
    char symbol[100];
    float numberMulty[101];
    float numberPlus[101];
    float sum = 0;
    
    for ( int i = 0, j = 0; fscanf(in, "%g", &number[i]) == 1 && i < 334 && j < 100; i++, j++ ) {
        fscanf(in, "%c", &symbol[j]);
        i++;
        fscanf(in, "%g", &secondDigit);
    }
    
    for ( int i = 0, j=0, x=0; i < 101; i++, j++, x++ ) {
        if ( symbol[i] == '*' ) {
            float numberMulty[x] = number[j] * number[j+1];
        } else if ( symbol [i] == '/' ) {
            float numberMulty[x] = number[j] * number[j+1];
        }
    
    for ( int i = 0, j=0, x=0; i < 101; i++, j++, x++ ) {
        if ( symbol[i] == '-' ) {
            float numberMulty[x] = number[j] - number[j+1];
        } else if ( symbol [i] == '+' ) {
            float numberMulty[x] = number[j] + number[j+1];
        }
    
    }
    fprintf(out, "%g\n", sum);
    fclose(in);
    fclose(out);
    
    return 0;
}
