void arrayShift(int array[], int size, int shift) {
    int buffer = size / 2;
    int bufferArray[buffer];
    
    shift %= size;
    if ( shift < 0 ) {
        shift += size;
    }
    if ( shift <= buffer ) {
        for ( int i = size - shift, j = 0; i < size; i++, j++ ) {
            bufferArray[j] = array[i];
        }
        for ( int i = size - 1, j = size - shift - 1; i >= shift; i--, j-- ) {
            array[i] = array[j];
        }
        for ( int i = 0; i < shift; i++ ) {
            array[i] = bufferArray[i];
        }
    } else {
        for ( int i = size - shift - 1; i >= 0; i-- ) {
            bufferArray[i] = array[i];
        }
        for ( int i = 0, j = size - shift; i < shift; i++, j++ ) {
            array[i] = array[j];
        }
        for ( int i = size - 1, j = size - 1 - shift; j >= 0; i--, j-- ) {
            array[i] = bufferArray[j];
        }
    }
}
