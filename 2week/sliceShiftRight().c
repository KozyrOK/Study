void sliceShiftRight(int array[], int start, int end) {
    if ( start < end ) {
        int temporary = array[end];
        
        for ( int i = end; i > start; i-- ) {
            array[i] = array[i-1];
        }
        array[start] = temporary;
    }
}
