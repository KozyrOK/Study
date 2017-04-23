#include <stdio.h>

int main() {
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    int limitSym = 100;
    char str[limitSym];
    int length = 0;
    
    fscanf(in, "%s", str);
    
    for ( ; str[length] != '\0'; length++ );
    
    for ( int i = 0, j = length - 1; i < j; i++, j-- ) {
        int temporary = str[j];
        
        str[j] = str[i];
        str[i] = temporary;
    }
    fprintf(out, "%s\n", str);
    
    fclose(in);
    fclose(out);
    
    return 0;
}
