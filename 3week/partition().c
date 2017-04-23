int partition(int array[], int start, int end) {
    int average = (start + end) / 2;
    int marker;
    int buffer = array[average];
    
    array[average] = array[end];
    array[end] = buffer;
    
    for ( marker = start; array[marker] < array[end]; marker++ );
    for ( int i = marker + 1; i < end; i++ ) {
        if ( array[i] <= array[end] ) {
            buffer = array[i];
            array[i] = array[marker];
            array[marker] = buffer;
            marker += 1;
        }
    }
    
    buffer = array[marker];
    array[marker] = array[end];
    array[end] = buffer;
    
    return marker;
}
