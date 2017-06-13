#ifndef ARITHMETICPROGITERATOR_CPP
#define ARITHMETICPROGITERATOR_CPP

class OutOfRangeException {};

class ArithmeticProgIterator {
    private:
        long long int firstNum;
        long long int step;
        long long int currentNum;
        unsigned int lastIndex;
        unsigned int currentIndex;
        bool isEndOfseq;
    public:
        ArithmeticProgIterator(long long int firstNum, long long int step, unsigned int lastIndex) {
            this->firstNum = firstNum;
            this->step = step;
            this->currentNum = firstNum;
            this->lastIndex = lastIndex;
            this->currentIndex = 1;
            this->isEndOfseq = false;
        }
        
        void next() {
            if ( over() ) {
                return;
            }
            if (this->currentIndex != this->lastIndex) {
                this->currentIndex += 1; 
                this->currentNum += this->step;
            } else {
                this->isEndOfseq = true;
                over();
            }
        }
        
        void operator++() { 
            next();
        }
        
        void operator++(int) { 
            operator++();
        }
        
        bool over() {
            if (this->currentIndex == this->lastIndex && this->isEndOfseq) {
                return true;
            } else {
                return false;
            }
        }
        
        long long int value() {
            return this->currentNum;
        }
        
        long long int operator*() {
            return value();
        }

        void reset() {
            this->currentIndex = 1;
            this->currentNum = firstNum;
            this->isEndOfseq = false;
        }

        void goTo(unsigned int index) { 
            if (index > this->lastIndex || index < 1) {
                throw OutOfRangeException();
            } else if (index > this->currentIndex) {
                long long int x = this->currentNum;
                long long int y = this->step;
                unsigned int i = this->currentIndex;
                unsigned int j = index;
                for ( ; i < j; i += 1) {
                    x += y;
                }
                this->currentIndex = index;
                this->currentNum = x;
                    if (index == lastIndex) {
                        this->isEndOfseq = true;
                    }
            } else if (index < this->currentIndex) {
                long long int x = this->currentNum;
                long long int y = this->step;
                unsigned int i = this->currentIndex;
                unsigned int j = index;
                for ( ; i > j; i -= 1) {
                    x -= y;
                }
                this->currentIndex = index;
                this->currentNum = x;
            } else {
            }
        }

        long long int operator[](unsigned int index) {
            if (index > this->lastIndex || index < 0) {
                throw OutOfRangeException();
            } else if (index > this->currentIndex) {
                long long int x = this->currentNum;
                long long int y = this->step;
                unsigned int i = this->currentIndex;
                unsigned int j = index;
                for ( ; i < j; i += 1) {
                    x += y;
                }
                return x;
            } else if (index < this->currentIndex) {
                long long int x = this->currentNum;
                long long int y = this->step;
                unsigned int i = this->currentIndex;
                unsigned int j = index;
                for ( ; i > j; i -= 1) {
                    x -= y;
                }
                return x;
            } else {
                return this->currentNum;
            }
        }
};

#endif