#include <iostream>
#include "Vector.h"

int main() {
    Vector vec = Vector(3, 2);
    Vector vec2 = vec;
    
    std::cout << vec << std::endl;
    std::cout << vec2 << std::endl;

    return 0;
}
