void bubbleSort(int array[], int size) {
    int isSorted = 0;
    int last = size - 1;
    
    for ( int i = 0; i < last && isSorted != 1; i++ ) {
        int limit = last - i;
        
        isSorted = 1;
        
        for ( int j = 0; j < limit; j++ ) {
            int next = j + 1;
            
            if ( array[j] > array[next] ) {
                int temp = array[j];
                
                array[j] = array[next];
                array[next] = temp;
                isSorted = 0;
            }
        }
    }
}
