void matrixMultiply(int matrix[SIZE][SIZE], int size, int multiplier) {
    for ( int row = 0; row < size; row++ ) {
        for ( int column = 0; column < size; column++ ) {
            matrix[row][column] *= multiplier;
        }
    }
}
