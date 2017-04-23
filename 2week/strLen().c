int strLen(char str[]) {
    int length = 0;
    
    for ( ; str[length] != '\0'; length++ );
    return length;
}
