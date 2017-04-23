void matrixRotate180(int target[SIZE][SIZE], int source[SIZE][SIZE], int size) {
    for ( int row = 0, newCol = size - 1; row < size; row++, newCol-- ) {
        for ( int column = 0, newRow = size - 1; column < size; column++, newRow-- ) {
            target[newRow][newCol] = source[column][row];
        }
    }
}
