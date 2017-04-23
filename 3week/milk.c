#include <stdio.h>

#define PRICE 1001

long long unsigned getValue(FILE *in) {
    long long unsigned buffer;
    
    fscanf(in, "%llu", &buffer);
    return buffer;
}

void arrayNull(long long unsigned array[]) {
    for ( int i = 0; i < PRICE; i++ ) {
        array[i] = 0;
    }
}

void arrayFill(FILE *in, long long unsigned array[], long long unsigned farmerQuantity) {
    long long int amount, price;
    
    for ( int i = 0; i < farmerQuantity; i++ ) {
        fscanf(in, "%llu", &amount);
        fscanf(in, "%llu", &price);
        
        array[price] += amount;
    }
}

long long unsigned minPrice(long long unsigned array[], long long unsigned amountNeeded) {
    long long unsigned amountLeft = amountNeeded;
    long long unsigned totalCost = 0;
    int i = 1;
    
    for ( ; i < PRICE && amountLeft > 0; i++ ) {
        if ( amountLeft > array[i] ) {
            totalCost += array[i] * i;
            amountLeft -= array[i];
        } else {
            totalCost += amountLeft * i;
            amountLeft = 0;
        }
    }
    if ( amountLeft > 0 ) {
        return 0;
    } else {
        return totalCost;
    }
}

int main() {
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    long long unsigned array[PRICE];
    long long unsigned farmerQuantity = getValue(in);
    long long unsigned amountNeeded = getValue(in);
    
    if ( amountNeeded <= 0 || amountNeeded <= 0 ) {
        fprintf(out, "0\n");
    } else {
        arrayNull(array);
        arrayFill(in, array, farmerQuantity);
        fprintf(out, "%llu\n", minPrice(array, amountNeeded));
    }
    
    fclose(in);
    fclose(out);
    return 0;
}
