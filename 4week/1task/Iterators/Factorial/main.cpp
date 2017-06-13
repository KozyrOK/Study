#include <iostream>
#include "FactorialIterator.cpp"

int main() {
    FactorialIterator seq;

    for ( ; !seq.isLast(); seq++ ) {
        std::cout << *seq << std::endl;
    }

    std::cout << seq.value() << std::endl;

    seq.reset();

    std::cout << "seq.reset(): " << seq.value() << std::endl;

    std::cout << "seq[20]: " << seq[20] << std::endl;

    std::cout << "seq.value(): " << seq.value() << std::endl;

    std::cout << "seq[0]: " << seq[0] << std::endl;

    std::cout << "seq.value(): " << seq.value() << std::endl;

    seq.goTo(10);

    std::cout << "seq.goTo(10): " << seq.value() << std::endl;

    seq.prev();

    std::cout << "seq.prev(): " << seq.value() << std::endl;

    seq.reset();

    std::cout << "seq.reset(): " << seq.value() << std::endl;

    return 0;
}
