#include <iostream>
#include "Paper.h"

Paper::Paper(int maxSymbols) { 
    this->maxSymbols = maxSymbols;
    this->symbols = 0;
    this->content = "";
}

Paper::~Paper() {}

int Paper::getMaxSymbols() const {
    return this->maxSymbols;
}

int Paper::getSymbols() const {
    return this->symbols;
}

void Paper::addContent(const std::string& message) {
    if (this->symbols == this->maxSymbols) {
        throw OutOfSpace ();
    } else if ((this->maxSymbols) - (this->symbols) < message.size()) {
        size_t lengthMessage = (this->maxSymbols) - (this->symbols);
        this->content += message.substr(0, lengthMessage);
        this->symbols += lengthMessage;
    } else {
        this->content += message;
        this->symbols += message.size();
    }
}

void Paper::show() const {
    std::cout << this->content << std::endl;
}
