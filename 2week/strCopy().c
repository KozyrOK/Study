void strCopy(char target[], char source[]) {
    for ( ; *source != '\0'; target++, source++ ) {
        *target = *source;
    }
    *target = *source;
}
