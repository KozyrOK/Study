void arraySort(int array[], int size) {
    int lastNum = size - 1;
    int temporary;
    
    for ( int i = 0; i < size; i++ ) {
        for ( int j = 0; j < lastNum - i; j++ ) {
            if ( array[j] > array[j+1] ) {
                temporary = array[j];
                array[j] = array[j+1];
                array[j+1] = temporary;
            }
        }
    }
}
