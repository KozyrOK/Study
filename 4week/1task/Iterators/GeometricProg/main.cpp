#include <iostream>
#include "GeometricProg.cpp"

int main() {
    GeometricProg seq(1, 3, 10);
    
    for ( ; !seq.over(); seq++ ) {
        std::cout << *seq << std::endl;
    }
    std::cout << seq.value() << std::endl;
    
    seq.reset();

    std::cout << "seq.reset(): " << seq.value() << std::endl;

    seq.goTo(10);

    std::cout << "seq.goTo(10): " << seq.value() << std::endl;

    std::cout << seq[1] << std::endl;

    std::cout << seq[10] << std::endl;

    return 0;
}
