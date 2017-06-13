#ifndef FACTORIALITERATOR_CPP
#define FACTORIALITERATOR_CPP

class OutOfRangeException {};

class FactorialIterator {
    private:
        int number;
        long long unsigned factorialNum;
        bool isEndOfseq;
        bool isBeginOfseq;
    public:
        FactorialIterator() {
            this->number = 1;
            this->factorialNum = 1;
            this->isEndOfseq = false;
            this->isBeginOfseq = false;
        }
        
        void next() {
            if ( isLast() ) {
                return;
            } else if (this->number == 0) {
                this->number = 1;
                this->factorialNum = 1;
            } else if (this->number == 19) {
                this->number += 1;
                this->factorialNum *= this->number;
            } else {
                this->number += 1;
                this->factorialNum *= this->number;
                isLast();
                this->isBeginOfseq = false;
            }
        }
        
        void prev() {
            if ( isFirst() ) {
                return;
            } else if (this->number == 1 ) {
                this->number -= 1;
                this->factorialNum = 1;
            } else if (this->number == 2) {
                this->number -= 1;
                this->factorialNum = 1;
            } else {
                this->factorialNum /= this->number;
                this->number -= 1;
                isFirst();
                this->isEndOfseq = false;
            }
        }
        
        void operator++() {
            next();
        }
        
        void operator++(int) {
            operator++();
        }
        
        void operator--() {
            prev();
        }

        void operator--(int) {
            operator--();
        }

        bool isFirst() {
            if (this->number == 0 && this->isBeginOfseq) {
                return true;
            } else if (this->number == 0) {
                this->isBeginOfseq = true;
                return false;
            } else {
                return false;
            }
        }

        bool isLast() {
            if (this->number == 20 && this->isEndOfseq) {
                return true;
            } else if (this->number == 20) {
                this->isEndOfseq = true;
                return false;
            } else {
                return false;
            }
        }
        
        long long unsigned value() {
            return this->factorialNum;
        }
        
        long long unsigned operator*() {
            return value();
        }

        void reset() {
            this->number = 1;
            this->factorialNum = 1;
            this->isEndOfseq = false;
        }

        void goTo(unsigned int index) {
            if (index > 20 || index < 0) {
                throw OutOfRangeException();
            } else if (index > this->number) {
                for ( ; this->number < index; next() );
            } else if (index < this->number) {
                for ( ; this->number > index; prev() );
            } else {
            }
        }

        long long int operator[](unsigned int index) {
            long long int tempNumber = this->number;
            long long int tempFactorialNum = this->factorialNum;
            if (index > 20 || index < 0) {
                throw OutOfRangeException();
            } else if (index > this->number) {
                for ( ; this->number < index; next() );
                long long int tempFactorialNum1 = this->factorialNum;
                this->factorialNum = tempFactorialNum;
                this->number = tempNumber;
                return tempFactorialNum1;
            } else if (index < this->number) {
                for ( ; this->number > index; prev() );
                long long int tempFactorialNum1 = this->factorialNum;
                this->factorialNum = tempFactorialNum;
                this->number = tempNumber;
                return tempFactorialNum1;
            } else {
                return this->factorialNum;
            }
        }
};

#endif