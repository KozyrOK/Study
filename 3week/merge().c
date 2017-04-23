void merge(int array[], int lo, int mid, int hi) {
    int sizeTemp = hi - lo;
    int tempArray[sizeTemp];
    int index1 = lo;
    int index2 = mid;
    int indexTemp = 0;
    
    for ( ; index1 < mid && index2 < hi; indexTemp++ ) {
        if ( array[index2] < array[index1] ) {
            tempArray[indexTemp] = array[index2];
            index2 += 1;
        } else {
            tempArray[indexTemp] = array[index1];
            index1 += 1;
        }
    }
    for ( ; index1 < mid; indexTemp++, index1++ ) {
        tempArray[indexTemp] = array[index1];
    }
    
    for ( ; index2 < hi; indexTemp++, index2++ ) {
        tempArray[indexTemp] = array[index2];
    }
    
    for ( int i = lo, j = 0; i < hi; i++, j++ ) {
        array[i] = tempArray[j];
    }
}
