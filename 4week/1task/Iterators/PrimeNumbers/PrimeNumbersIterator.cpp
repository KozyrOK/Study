#ifndef PRIMENUMBERSITERATOR_CPP
#define PRIMENUMBERSITERATOR_CPP

#include <iostream>
#include <cstdlib>
#include <cmath>

class OutOfRangeException {};
class OutOfMemoryException {};

class PrimeNumbersIterator {
    private:
        int current;
        unsigned int primeNumber;
        unsigned int sizeArray;
        unsigned int* cacheArrayPrime;
        int maxIndexPrimeValid;
        int IndexPrime;
        
    public:
        PrimeNumbersIterator() {
            this->current = 1;
            this->primeNumber = 2;
            this->sizeArray = 10;
            unsigned int size = this->sizeArray;
            unsigned int* cacheArray = (unsigned int*) malloc(size * sizeof(unsigned int));
            if ( cacheArray == NULL ) {
                throw OutOfMemoryException();
            }
            this->cacheArrayPrime = cacheArray;
            this->maxIndexPrimeValid = size - 1;
            this->IndexPrime = 1;
            this->cacheArrayPrime[0] = 0;
            this->cacheArrayPrime[1] = 2;
            }

        ~PrimeNumbersIterator() {
            free(cacheArrayPrime);
        }

        bool prime(unsigned int number) {
            int index = this->IndexPrime;
            for (unsigned int i = this->cacheArrayPrime[index]; i <= sqrt(number); i++) {
                if (number % i == 0) {
                return false;
                }
            }
            return true;
        }

        void addCacheArrayPrime() {
            unsigned int* temp;
            unsigned int size = this->sizeArray;
            unsigned int newSize = size + (size / 5);
            temp = (unsigned int*) realloc (cacheArrayPrime, newSize * sizeof(unsigned int));
            if ( temp != NULL ) {
                this->cacheArrayPrime = temp;
                this->sizeArray = newSize;
                this->maxIndexPrimeValid = (int)newSize - 1;
            } else {
                throw OutOfMemoryException();
            }
        }
        
        unsigned int result(int number) {
            if (number == 0 || number > 2147483647) {
                OutOfRangeException();
            } else {
                if (number <= this->IndexPrime) {
                    return cacheArrayPrime[number];
                } else if (number <= this->maxIndexPrimeValid) {
                    cacheArrayInitialization(number);
                    return cacheArrayPrime[number];
                } else {
                    for( ; number > this->maxIndexPrimeValid; ) {
                        addCacheArrayPrime();
                    }
                    cacheArrayInitialization(number);
                    return cacheArrayPrime[number];
                }
            }
        }

        void next() {
            if (this->current < 2147483647) {
                this->current += 1;
                int number = this->current;
                if (number > this->maxIndexPrimeValid) {
                    addCacheArrayPrime();
                    cacheArrayInitialization(number);
                    this->primeNumber = cacheArrayPrime[number];
                } else if (number > this->IndexPrime) {
                    cacheArrayInitialization(number);
                    this->primeNumber = cacheArrayPrime[number];
                } else {
                    this->primeNumber = this->cacheArrayPrime[number];
                }
            } else {
            }
        }

        void prev() {
            if (this->current > 1) {
                this->current -= 1;
                int number = this->current;
                this->primeNumber = this->cacheArrayPrime[number];
            } else {
            }
        }

        void operator++() {
            next();
        }

        void operator++(int) {
            next();
        }

        void operator--() {
            prev();
        }

        void operator--(int) {
            prev();
        }

        unsigned int value() {
            return this->primeNumber;
        }

        unsigned int operator*() {
            return value();
        }

        void goTo(int number) {
             if (number == 0 || number > 2147483647) {
                OutOfRangeException();
            } else {
                if (number <= this->IndexPrime) {
                    this->current = number;
                    this->primeNumber = this->cacheArrayPrime[number];
                } else if (number <= this->maxIndexPrimeValid) {
                    cacheArrayInitialization(number);
                    this->current = number;
                    this->primeNumber = this->cacheArrayPrime[number];
                } else {
                    for( ; number > this->maxIndexPrimeValid; ) {
                        addCacheArrayPrime();
                    }
                    cacheArrayInitialization(number);
                    this->current = number;
                    this->primeNumber = this->cacheArrayPrime[number];
                }
            }
        }

        unsigned int operator[](int number) {
            return result(number);
        }

        void reset() {
            this->current = 1;
            this->primeNumber = 2;
        }

        void cacheArrayInitialization(int number) {
            int beginIndex = this->IndexPrime;
            int endIndex = number;
            int index = this->IndexPrime;
            unsigned int primeNum = cacheArrayPrime[index];
            for( ; beginIndex <= endIndex; primeNum++) {
                if ( prime(primeNum) ) {
                    this->cacheArrayPrime[beginIndex] = primeNum;
                    beginIndex += 1;
                }
            }
        }
};

#endif