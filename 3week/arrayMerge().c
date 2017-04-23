void arrayMerge(int target[], int src1[], int len1, int src2[], int len2) {
    int i = 0;
    int j = 0;
    int k = 0;
    
    for ( ; j < len1 && k < len2; i++ ) {
        if ( src1[j] <= src2[k] ) {
            target[i] = src1[j];
            j += 1;
        } else {
            target[i] = src2[k];
            k += 1;
        }
    }
    
    if ( j < len1 ) {
        for ( ; j < len1; i++, j++ ) {
            target[i] = src1[j];
        }
    } else {
        for ( ; k < len2; i++, k++ ) {
            target[i] = src2[k];
        }
    }
}
