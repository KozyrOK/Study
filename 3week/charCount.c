#include <stdio.h>

#define CHARACTERS 26

void nullArray(int arrayLetters[], int size) {
    for ( int i = 0; i < size; i++ ) {
        arrayLetters[i] = 0;
    }
}

void arrayScan(FILE *in, int arrayLetters[], int size) {
    int temp, symbolCode;
    char symbol;
    
    temp = fscanf(in, "%c", &symbol);
    for ( ; temp != EOF; ) {
        if ( symbol > 64 && symbol < 123 ) {
            if ( symbol > 64 && symbol < 91 ) {
                symbol -= 65;
            }
            if ( symbol > 96 ) {
                symbol -= 97;
            }
            if ( symbol < size ) {
                symbolCode = symbol;
                arrayLetters[symbolCode] += 1;
            }
        }
        temp = fscanf(in, "%c", &symbol);
    }
}

void printChar(FILE *out, int arrayLetters[], int size) {
    for ( int i = 0; i < size; i++ ) {
        if ( arrayLetters[i] > 0 ) {
            fprintf(out, "%c %d\n", i+97, arrayLetters[i]);
        }
    }
}

int main() {
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    int arrayLetters[CHARACTERS];
    
    nullArray(arrayLetters, CHARACTERS);
    arrayScan(in, arrayLetters, CHARACTERS);
    printChar(out, arrayLetters, CHARACTERS);
    
    fclose(in);
    fclose(out);
    return 0;
}
