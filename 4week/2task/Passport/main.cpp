#include <iostream>
#include "Passport.h"

int main() {
    Passport::printLastNumberAndSerias();
    std::cout << std::endl;
    Passport artem("Artem", "Kozyr", 7, 1, 1984);
    std::cout << artem << std::endl;
    std::cout << std::endl;
    Passport::printLastNumberAndSerias();
    std::cout << std::endl;
    Passport artem1("Artem1", "Kozyr1", 7, 11, 1984);
    std::cout << artem1 << std::endl;
    std::cout << std::endl;
    Passport::printLastNumberAndSerias();
    std::cout << std::endl;
    Passport artem2("Artem2", "Kozyr2", 8, 11, 1984);
    std::cout << artem2 << std::endl;
    std::cout << std::endl;
    Passport::setSeries('S', 'S');
    Passport::printLastNumberAndSerias();
    std::cout << std::endl;
    Passport::setNumberAndSerias('Z','Y', 999999);
    Passport::printLastNumberAndSerias();
    std::cout << std::endl;
    Passport kirilo("Kirilo", "Kozyr", 23, 12, 1986);
    std::cout << kirilo << std::endl;
    std::cout << std::endl;
    Passport::printLastNumberAndSerias();
    return 0;
}
