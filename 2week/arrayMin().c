int arrayMin(int array[], int size) {
    int min = array[0];
    
    for ( int i = 1; i < size; i++ ) {
        if ( array[i] < min ) {
            min = array[i];
        }
    }
    return min;
}
