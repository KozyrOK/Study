#include <stdio.h>

void strRot13(char str[]) {
    for ( ; *str != '\0'; str++ ) {
        if ( *str > 64 && *str < 78 ) {
            *str += 13;
        } else if ( *str > 96 && *str < 110 ) {
            *str += 13;
        } else if ( *str > 77 && *str < 91 ) {
            *str -= 13;
        } else if ( *str > 109 && *str < 123 ) {
            *str -= 13;
        }
    }
}

int main() {
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    int limitSym = 100;
    char str[limitSym];
    
    fscanf(in, "%100s", str);
    strRot13(str);
    fprintf(out, "%s\n", str);
    
    fclose(in);
    fclose(out);
    
    return 0;
}
