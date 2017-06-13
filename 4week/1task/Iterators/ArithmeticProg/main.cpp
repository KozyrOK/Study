#include <iostream>
#include "ArithmeticProgIterator.cpp"

int main() {
    ArithmeticProgIterator seq(1, 2, 11);

    for ( ; !seq.over(); seq++ ) {
        std::cout << *seq << std::endl;
    }
    std::cout << seq.value() << std::endl;
    
    seq.reset();

    std::cout << "seq.reset(): " << seq.value() << std::endl;

    seq.goTo(14);

    std::cout << "seq.goTo(11): " << seq.value() << std::endl;

    std::cout << seq[1] << std::endl;

    std::cout << seq[11] << std::endl;

    return 0;
}
