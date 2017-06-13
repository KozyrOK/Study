#include <iostream>
#include "Identifiable.h"

Identifiable::Identifiable() {
    counter += 1;
    this->identNumber = counter;
}

Identifiable::Identifiable(const Identifiable& identifiable) {
    counter += 1;
    this->identNumber = counter;
}

int Identifiable::getCounter() { 
    return counter;
}

int Identifiable::getIdentNumber() const { 
    return this->identNumber;
}

int Identifiable::counter = 0;
