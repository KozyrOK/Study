#include <stdio.h>

#define CHAR_LIMIT 4294967295
#define ZERO 48
#define ONE 49

unsigned numberOfNeedle(FILE *in, char needle, unsigned limit) {
    int counter = 0;
    char buffer;
    
    for ( unsigned i = 0; fscanf(in, "%c", &buffer) != -1 && i < limit; i++ ) {
        if ( buffer == needle ) {
            counter += 1;
        }
    }
    return counter;
}

int main() {
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    unsigned zeroes;
    
    zeroes = numberOfNeedle(in, ZERO, CHAR_LIMIT);
    rewind(in);
    fprintf(out, "%u\n", numberOfNeedle(in, ONE, zeroes));
    
    fclose(in);
    fclose(out);
    return 0;
}
