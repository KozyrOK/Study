#include <iostream>
#include "Countable.h"

int main() {
    Countable a;
    Countable b;
    
    std::cout << a.getCount() << std::endl;
    std::cout << b.getCount() << std::endl;
    std::cout << Countable::getCount() << std::endl;
    
    return 0;
}
