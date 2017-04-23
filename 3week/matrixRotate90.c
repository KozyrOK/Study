void matrixRotate90(int target[SIZE][SIZE], int source[SIZE][SIZE], int size) {
    for ( int row = 0, rotate = size - 1; row < size; row++, rotate-- ) {
        for ( int column = 0; column < size; column++ ) {
            target[rotate][column] = source[column][row];
        }
    }
}
