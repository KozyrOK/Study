void sliceReverse(int array[], int lo, int hi) {
    for ( ; lo < hi; lo++, hi-- ) {
        int temporary = array[hi];
        
        array[hi] = array[lo];
        array[lo] = temporary;
    }
}
