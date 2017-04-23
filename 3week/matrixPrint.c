void matrixPrint(FILE *out, int matrix[SIZE][SIZE], int size) {
    int last = size - 1;
    
    for ( int row = 0; row < size; row++ ) {
        for ( int column = 0; column < last; column++ ) {
            fprintf(out, "%d ", matrix[column][row]);
        }
        fprintf(out, "%d\n", matrix[last][row]);
    }
}
