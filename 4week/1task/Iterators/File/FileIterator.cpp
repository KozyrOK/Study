#ifndef FILE_ITERATOR_CPP
#define FILE_ITERATOR_CPP

#include <iostream>
#include <fstream>
#include <cstdlib>

template <class Type>
class FileIterator {
    private:
        std::ifstream file;
        Type *array;
        size_t size;
        size_t current;
        size_t multiplier;
    public:
        FileIterator(const char *fileName) : file(fileName), size(20), current(0), multiplier( 1.25)
        {
            array = (Type*)malloc(size*sizeof(Type));
            if (file.is_open()) {
                file >> *array;
            }
        }

        void next() {
            if (current == size) {
                size_t newSize = size * multiplier;
                Type* newArray = (Type*)realloc(array, newSize*sizeof(Type));
                array = newArray;
            }
            current += 1;
            file >> array[current];
        }

        bool over() const {
            return file.eof();
        }

        const Type& value() const{
            return array[current];
        }

        void operator++() {
            next();
        }

        void operator++(int) {
            operator++();
        }

        Type operator*() {
            return value();
        }
};

    #endif