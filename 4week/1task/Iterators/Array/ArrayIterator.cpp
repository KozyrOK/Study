#include <iostream>

template <typename Type>

class ArrayIterator {
    private:
        Type* start;
        Type* current;
        unsigned int counter;
        unsigned int finish;
    public:
        ArrayIterator(Type* array, unsigned int size) {
            this->start = array;
            this->current = array;
            this->counter = 0;
            this->finish = size;
        }

        ~ArrayIterator() {}
        
        bool overLo() {
            return this->counter <= 0;
        }

        bool overHi() {
            return this->counter >= finish;
        }

        void next() {
            if ( overHi() ) {
                return;
            }
            this->current += 1;
            this->counter += 1;
        }

        void prev() {
            if ( overLo() ) {
                return;
            }
            this->current -= 1;
            this->counter -= 1;
        }

        Type value() {
            return *current;
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

        Type operator*() {
            return value();
        }
};
