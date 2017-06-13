#include <iostream>
#include <cstdlib>
#include <cmath>
#include "PrimeNumbersIterator.cpp"

int main() {
    PrimeNumbersIterator seq;
    
    std::cout << "seq[12]: 12 " << seq[12] << std::endl;
    std::cout << "*seq " << *seq << std::endl;
    seq.next();
    std::cout << "seq.next(2); " << seq.value() << std::endl;
    seq.reset();
    std::cout << "seq.reset(); " << seq.value() << std::endl;
    seq.next();
    std::cout << "seq.next(3); " << seq.value() << std::endl;
    seq.next();
    std::cout << "seq.next(4); " << seq.value() << std::endl;
    seq.next();
    std::cout << "seq.next(5); " << seq.value() << std::endl;
    seq.next();
    std::cout << "seq.next(6); " << seq.value() << std::endl;
    seq.next();
    std::cout << "seq.next(7); " << seq.value() << std::endl;
    seq.next();
    std::cout << "seq.next(8); " << seq.value() << std::endl;
    seq.next();
    std::cout << "seq.next(9); " << seq.value() << std::endl; // error
    seq.next();
    std::cout << "seq.next(10); " << seq.value() << std::endl;
    seq.next();
    std::cout << "seq.next(11); " << seq.value() << std::endl;
    seq.next();
    std::cout << "seq.next(12); " << seq.value() << std::endl;
    seq.goTo(46);
    std::cout << "seq.goTo(46) 199: " << seq.value() << std::endl;
    seq.prev();
    std::cout << "seq.prev(11); " << seq.value() << std::endl;
    seq.next();
    std::cout << "seq.next(12); " << seq.value() << std::endl;
    seq.prev();
    std::cout << "seq.prev(11); " << seq.value() << std::endl;
    seq.next();
    std::cout << "seq.next(12); " << seq.value() << std::endl;
    seq.next();
    std::cout << "seq.next(13); " << seq.value() << std::endl;
    seq.next();
    std::cout << "seq.next(14); " << seq.value() << std::endl;
    seq.next();
    std::cout << "seq.next(15); " << seq.value() << std::endl;
    seq.next();
    std::cout << "seq.next(16); " << seq.value() << std::endl;
    seq.next();
    std::cout << "seq.next(17); " << seq.value() << std::endl;
    seq.next();
    std::cout << "seq.next(18); " << seq.value() << std::endl;
    seq.next();
    std::cout << "seq.next(19); " << seq.value() << std::endl;
    seq.next();
    std::cout << "seq.next(20); " << seq.value() << std::endl;
    seq.next();
    std::cout << "seq.next(21)end; " << seq.value() << std::endl;
    
    return 0;
}
