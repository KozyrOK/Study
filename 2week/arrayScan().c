int arrayScan(FILE *in, int array[], int limit) {
    int symbol = 0;
    
    for ( ; symbol < limit && fscanf(in, "%d", &array[symbol]) == 1; symbol++ );
    return symbol;
}
