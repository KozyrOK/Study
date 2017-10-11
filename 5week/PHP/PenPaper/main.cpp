#include <iostream>
#include "Paper.h"
#include "Pen.h"

int main() {
    Pen pen;
    Paper paper;
    
    pen.write(paper, "Hello, world!");

    paper.show();

    std::cout << "paper.getMaxSymbols(): " << paper.getMaxSymbols() << std::endl;

    std::cout << "paper.getSymbols(): " << paper.getSymbols() << std::endl;

    std::cout << "pen.getInkAmount(): " << pen.getInkAmount() << std::endl;

    pen.write(paper, "Ura Ura");

    std::cout << "paper.getMaxSymbols() " << paper.getMaxSymbols() << std::endl;

    std::cout << "paper.getSymbols(): " << paper.getSymbols() << std::endl;

    std::cout << "pen.getInkAmount(): " << pen.getInkAmount() << std::endl;

    paper.show();

    return 0;
}
