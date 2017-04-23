#include <stdio.h>

int strLen(char str[]) {
    int length = 0;
    
    for ( ; str[length] != '\0'; length++ );
    return length;
}

int main() {
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    int limitSym = 100;
    char str[limitSym];
    
    fscanf(in, "%s", str);
    
    fprintf(out, "%d\n", strLen(str));
    
    fclose(in);
    fclose(out);
    
    return 0;
}

