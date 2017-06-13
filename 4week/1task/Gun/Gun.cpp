#include <iostream>
#include "Gun.h"

Gun::Gun(const std::string& model, int capacity) {
    this->amount = capacity;;
    this->capacity = capacity;
    this->isReady = false;
    this->model = model;
    this->totalShots = 0;
}

Gun::~Gun() {}

int Gun::getAmount() const {
    return this->amount;
}

int Gun::getCapacity() const {
    return this->capacity;
}

bool Gun::ready() const {
    return this-> isReady;
}

const std::string& Gun::getModel() const {
    return this->model;
}

int Gun::getTotalShots() const {
    return this->totalShots;
}

void Gun::prepare() {
    this->isReady = true;
}

void Gun::reload() {
    this->amount = this->capacity;
    this->isReady = false;
}

void Gun::shoot() {
    if ( !ready() ) {
        throw NotReady();
    }
    if ( this->amount == 0 ) {
       throw OutOfRounds();
    }
    std::cout << "Bang!" << std::endl;
    this->amount -= 1;
    this->totalShots += 1;
}

std::ostream& operator<<(std::ostream& out, const Gun& gun) {
    out << "Gun model: " << gun.getModel() << ",\n"
    << "Amount: " << gun.getAmount() <<  ",\n"
    << "Capacity: " << gun.getCapacity() << ",\n"
    << "Gun ready: " << gun.ready() <<  ",\n"
    << "Total shots: " << gun.getTotalShots() << "." << std::endl;
    return out;
}
