void arrayShiftRight(int array[], int size) {
    int temporary = array[size-1];
    
    for ( size -= 1; size > 0; size-- ) {
        array[size] = array[size-1];
    }
    array[0] = temporary;
}
