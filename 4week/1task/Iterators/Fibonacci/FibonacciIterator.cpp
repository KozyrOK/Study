#ifndef FIBONACCIITERATOR_CPP
#define FIBONACCIITERATOR_CPP

class OutOfRangeException {};
class OutOfMemoryException {};

class FibonacciIterator {
    private:
        int current;
        long long int fibonacciNum;
        long long int* cacheArrayPositive;
        long long int* cacheArrayNegative;
        int maxIndexPositiveValid;
        int maxIndexNegativeValid;
        
    public:
        FibonacciIterator() {
            this->current = 1;
            this->fibonacciNum = 1;
            this->cacheArrayPositive = new long long int[93];
            if ( cacheArrayPositive == NULL ) { 
                throw OutOfMemoryException();
            }
            this->cacheArrayNegative = new long long int[93];
            if ( cacheArrayNegative == NULL ) {
                throw OutOfMemoryException();
            }
            this->maxIndexPositiveValid = 2;
            this->maxIndexNegativeValid = 2;
            cacheArray0();
            cacheArrayBeginInitialization();
            }

        ~FibonacciIterator() {
            delete(cacheArrayPositive);
            delete(cacheArrayNegative);
        }
        
        long long int result(int number) {
            if (number > 93 || number < -93) {
                OutOfRangeException();
            } else if (number >= 0) {
                if (number <= this->maxIndexPositiveValid) {
                    return cacheArrayPositive[number];
                } else {
                    for(int i = this->maxIndexPositiveValid; i < number; i++) {
                        nextMaxIndex();
                    }
                    return cacheArrayPositive[number];
                }
            } else if (number < 0) {
                int numberNeg = number * (-1);
                if (numberNeg <= this->maxIndexNegativeValid) {
                    return cacheArrayNegative[numberNeg];
                } else {
                    for(int i = this->maxIndexNegativeValid; i < numberNeg; i++) {
                        prevMaxIndex();
                    }
                    return cacheArrayNegative[numberNeg];
                }
            } else {
            }
        }

        void nextMaxIndex() {
            this->maxIndexPositiveValid += 1;
            int firstIndex = this->maxIndexPositiveValid - 1;
            int secondIndex = this->maxIndexPositiveValid - 2;
            long long int first = this->cacheArrayPositive[firstIndex];
            long long int second = this->cacheArrayPositive[secondIndex];
            this->cacheArrayPositive[maxIndexPositiveValid] = first + second;
        }

        void prevMaxIndex() {
            this->maxIndexNegativeValid += 1;
            int firstIndex = this->maxIndexNegativeValid - 1;
            int secondIndex = this->maxIndexNegativeValid - 2;
            long long int first = this->cacheArrayNegative[firstIndex];
            long long int second = this->cacheArrayNegative[secondIndex];
            this->cacheArrayNegative[maxIndexNegativeValid] = second - first;
        }

        void next() {
            if (this->current > -1 && this->current < 92) {
                this->current += 1;
                if (this->current > this->maxIndexPositiveValid) {
                    nextMaxIndex();
                    int currentIndex = this->current;
                    this->fibonacciNum = this->cacheArrayPositive[currentIndex];
                } else {
                    int currentIndex = this->current;
                    this->fibonacciNum = this->cacheArrayPositive[currentIndex];
                }
            } else if (this->current < 0 && this->current > -93 ) {
                this->current += 1;
                int currentIndex = this->current * -1;
                this->fibonacciNum = this->cacheArrayNegative[currentIndex];
            } else {
            }
        }

        void prev() {
            if (this->current > 0) {
                this->current -= 1;
                int currentIndex = this->current;
                this->fibonacciNum = this->cacheArrayPositive[currentIndex];
            } else if (this->current == 0) {
                this->current -= 1;
                this->fibonacciNum = 1;
            } else if (this->current < 0 && this->current > -92) {
                this->current -= 1;
                int currentIndexNeg = this->current * -1;
                if (currentIndexNeg <= this->maxIndexNegativeValid) {
                    this->fibonacciNum = this->cacheArrayNegative[currentIndexNeg];
                } else {
                    prevMaxIndex();
                    this->fibonacciNum = this->cacheArrayNegative[currentIndexNeg];
                }
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

        long long int value() {
            return this->fibonacciNum;
        }

        long long int operator*() {
            return value();
        }

        void goTo(int number) {
            if (number > 93 || number < -93) {
                OutOfRangeException();
            } else if (number >= 0) {
                if (number <= this->maxIndexPositiveValid) {
                    this->current = number;
                    this->fibonacciNum = cacheArrayPositive[number];
                } else {
                    for(int i = this->maxIndexPositiveValid; i < number; i++) {
                        nextMaxIndex();
                    }
                    this->current = number;
                    this->fibonacciNum = cacheArrayPositive[number];
                }
            } else if (number < 0) {
                int numberNeg = number * (-1);
                if (numberNeg <= this->maxIndexNegativeValid) {
                    this->current = number;
                    this->fibonacciNum = cacheArrayNegative[numberNeg];
                } else {
                    for(int i = this->maxIndexNegativeValid; i < numberNeg; i++) {
                        prevMaxIndex();
                    }
                    this->current = number;
                    this->fibonacciNum = cacheArrayNegative[numberNeg];
                }
            } else {
            }
        }

        long long int operator[](int number) {
            return result(number);
        }        

        void reset() {
            this->current = 1;
            this->fibonacciNum = 1;
        }

        void cacheArray0() {
            for(int i = 0; i < 93; i++) {
                this->cacheArrayPositive[i] = 0;
                this->cacheArrayNegative[i] = 0;
            }
        }

        void cacheArrayBeginInitialization() {
            this->cacheArrayPositive[1] = 1;
            this->cacheArrayPositive[2] = 1;
            this->cacheArrayNegative[1] = 1;
            this->cacheArrayNegative[2] = -1;
        }
};

#endif