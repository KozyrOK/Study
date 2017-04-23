void arrayShiftLeft(int array[], int size) {
    int temporary = array[0];
    
    for ( int i = 1; i < size; i++ ) {
        array[i-1] = array[i];
    }
    array[size-1] = temporary;
}
