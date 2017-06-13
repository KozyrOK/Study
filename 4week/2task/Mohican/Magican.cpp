#include <iostream>
#include "Magican.h"

Magican::Magican() {
    counter += 1;
    name = "";
    lastMagican = this;
}

Magican::Magican(Magican& magican) {
    counter += 1;
    name = "";
    lastMagican = this;
}

int Magican::getCounter() { 
    return counter;
}

std::string Magican::getName() { 
    return this->name;
}

void Magican::setName(std::string name) { 
    this->name = name;
}

std::string Magican::getLastMagican() { 
    return lastMagican->name;
}

int Magican::counter = 0;
Magican* Magican::lastMagican = NULL;
