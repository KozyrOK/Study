void arrayExchange(int array[], int len) {
    for ( int i = 0, j = 1; j < len; i += 2, j += 2 ) {
        int temporary = array[j];
        
        array[j] = array[i];
        array[i] = temporary;
    }
}
