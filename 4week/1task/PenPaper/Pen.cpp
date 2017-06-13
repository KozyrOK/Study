#include <iostream>
#include "Pen.h"

Pen::Pen(int inkCapacity) {
    this->inkAmount = inkCapacity;
    this->inkCapacity = inkCapacity;
}

Pen::~Pen() { }

int Pen::getInkAmount() const {
    return this->inkAmount;
}

int Pen::getInkCapacity() const {
    return this->inkCapacity;
}

void Pen::write(Paper& paper, const std::string& message) {
    if (this->inkAmount == 0) {
        throw OutOfInk();
    } else if (message.size() > this->inkAmount) {
        std::string shotMessage = message.substr(0, this->inkAmount);
        paper.addContent(shotMessage);
        this->inkAmount = 0;
    } else {
        paper.addContent(message);
        this->inkAmount -= message.size();
    }
}

void Pen::refill() {
    this->inkAmount = this->inkCapacity;
}
