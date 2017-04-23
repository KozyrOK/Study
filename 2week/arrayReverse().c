void arrayReverse(int array[], int size) {
    for ( int i = 0, j = size - 1; i < j; i++, j-- ) {
        int temporary = array[j];
        
        array[j] = array[i];
        array[i] = temporary;
    }
}
