#include <iostream>
#include "FibonacciIterator.cpp"

int main() {
    FibonacciIterator fib;

    std::cout << "fib[]: " << fib[90] << std::endl;
    fib.goTo(3);
    std::cout << "fib.goTo(3): " << fib.value() << std::endl;
    fib.reset();
    std::cout << "*fib " << *fib << std::endl;
    fib.prev();
    std::cout << "fib.prev(); " << fib.value() << std::endl;
    fib.next();
    std::cout << "fib.next(); " << fib.value() << std::endl;
    
    return 0;
}
