int strEqual(char str1[], char str2[]) {
    for ( ; *str1 == *str2 && *str1 != '\0'; str1++, str2++ );
    return *str2 == *str1;
}
