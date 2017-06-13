#include <iostream>
#include "Complex.h"

int main() {
    Complex com1(5, 8);
    Complex com2(5, 11);
    Complex com3(5, 10);

    std::cout << com1 << std::endl;
    std::cout << com2 << std::endl;
    com1 += com2;
    com2 -= com1;

    std::cout << com2.getReal() << std::endl;
    std::cout << com1.getImaginary() << std::endl;

    com3 = com1 * com2;
    
    std::cout << com3 << std::endl;

    return 0;
}
