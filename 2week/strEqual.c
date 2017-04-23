#include <stdio.h>

void strEqual(FILE *out, char str1[], char str2[]) {
    for ( ; *str1 == *str2 && *str1 != '\0'; str1++, str2++ );
    if ( *str2 == *str1 ) {
        fprintf(out, "%s\n", "yes");
    } else {
        fprintf(out, "%s\n", "no");
    }
}

int main() {
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    int limitSym = 100;
    char str1[limitSym];
    char str2[limitSym];
    
    fscanf(in, "%s%s", str1, str2);
    fclose(in);
    strEqual(out, str1, str2);
    fclose(out);
    
    return 0;
}
