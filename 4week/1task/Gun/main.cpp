#include <iostream>
#include "Gun.h"

int main() {
    Gun gun;
    Gun beretta("Beretta", 10);

    std::cout << gun << std::endl;
    std::cout << beretta << std::endl;

    beretta.reload();
    std::cout << beretta << std::endl;
    beretta.prepare();
    std::cout << beretta << std::endl;
    beretta.shoot();

    std::cout << gun << std::endl;
    std::cout << beretta << std::endl;
    
    return 0;
}
