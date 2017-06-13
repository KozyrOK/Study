#include <iostream>
#include "Mohican.h"

int main() {
    Mohican artem;
    Mohican kirilo;

    artem.setName("Artem");
    kirilo.setName("Kirilo");
    
    std::cout << artem.getName() << std::endl;
    std::cout << Mohican::getLastMohican() << std::endl;
    
    return 0;
}
