#include <iostream>
#include <cstdlib>
#include "List.h"

List::List(int capacity, double multiplier) : capacity(capacity), current(0), multiplier(multiplier) {
    this->array = (int*)malloc(capacity*sizeof(int));
    
    if ( this->array == NULL ) {
        throw OutOfMemoryException();
    }
}

List::~List() {
    free(this->array);
}

int List::size() const {
    return this->current;
}

int List::max_size() const {
    return this->capacity;
}

void List::erase(int index) {
    if (index >= this->current || index < 0 || index > this->current) {
        throw OutOfMemoryException();
    }
    if ( this->current == 0 ) {
        throw ZeroLenException();
    }
    
    for ( int i = index; i < this->current; i++ ) {
        this->array[i] = this->array[i+1];
    }
    this->current -= 1;
}

void List::insert(int value, int index) {
    if (index < 0 || index > this->current) {
        throw OutOfMemoryException();
    } else {
        int newCurrent = this->current + 1;
        
        if ( newCurrent > this->capacity ) {
            int newCapacity = this->capacity * this->multiplier;
            int* newArray = (int*)realloc(array, newCapacity*sizeof(int));
                if ( newArray == NULL ) {
                    throw OutOfMemoryException();
                }
            this->capacity = newCapacity;
            this->array = newArray;
        }
        this->current = newCurrent;
        int i = newCurrent;
        
        for ( ; i > index; i-- ) {
            this->array[i] = this->array[i-1];
        }
        this->array[index] = value;
    }
}

int List::find(int value) const {
    int index = 0;
    for ( ; index < this->capacity ; index++) {
        if (this->array[index] == value) {
            return index;
        }
    }
    return -1;
}

void List::push_back(int value) {
    int newCurrent = this->current + 1;
    
    if ( newCurrent > this->capacity ) {
        int newCapacity = this->capacity * this->multiplier;
        int* newArray = (int*)realloc(array, newCapacity*sizeof(int));
        
        if ( newArray == NULL ) {
            throw OutOfMemoryException();
        }
        
        this->capacity = newCapacity;
        this->array = newArray;
    }
    this->array[current] = value;
    this->current = newCurrent;
}

int List::pop_back() {
    if ( this->current == 0 ) {
        throw ZeroLenException();
    }
    this->current -= 1;
    return this->array[current];
}

void List::sort() {
    for ( int i = 1; i < this->current; i++ ) {
        int j = i;
        int temp = this->array[i];
        
        for ( int prev = j - 1; j > 0 && temp < this->array[prev]; j--, prev-- ) {
            this->array[j] = this->array[prev];
        }
        this->array[j] = temp;
    }
}

int List::operator[](int index) const {
    return this->array[index];
}

bool List::operator==(const List& other) const {
    return this->capacity == other.capacity;
}

bool List::operator!=(const List& other) const {
    return this->capacity != other.capacity;
}

std::ostream& operator<<(std::ostream& out, const List& list) {
   int last = list.size() - 1;

   for ( int i = 0; i < last; i++ ) {
       out << list[i] << ' ';
   }
   out << list[last];
   return out;
}
