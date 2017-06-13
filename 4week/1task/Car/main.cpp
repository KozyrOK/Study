#include <iostream>
#include "Car.h"
#include "Point.h"

int main() {
    Car car;
    
    std::cout << car << std::endl;
    
    car.drive(Point(5, 11));
    
    std::cout << car << std::endl;
    
    car.drive(1.0, 1.0);
    
    std::cout << car << std::endl;
    
    car.refill(1.0);
    
    std::cout << car << std::endl;
}
