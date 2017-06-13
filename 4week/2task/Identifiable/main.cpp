#include <iostream>
#include "Identifiable.h"

int main() {
    Identifiable first;
    Identifiable second;
    Identifiable third = first;
    
    std::cout << "Counter: " << first.getCounter() << ", IdentNumber: " << first.getIdentNumber() << std::endl;
    std::cout << "Counter: " << second.getCounter() << ", IdentNumber: " << second.getIdentNumber() << std::endl;
    std::cout << "Counter: " << third.getCounter() << ", IdentNumber: " << third.getIdentNumber() << std::endl;
    
    return 0;
}

