#include <iostream>
#include "Mohican.h"

Mohican::Mohican() {
    counter += 1;
    name = "";
    lastMohican = this;
}

Mohican::Mohican(Mohican& mohican) {
    counter += 1;
    name = "";
    lastMohican = this;
}

int Mohican::getCounter() { 
    return counter;
}

std::string Mohican::getName() { 
    return this->name;
}

void Mohican::setName(std::string name) { 
    this->name = name;
}

std::string Mohican::getLastMohican() { 
    return lastMohican->name;
}

int Mohican::counter = 0;
Mohican* Mohican::lastMohican = NULL;
