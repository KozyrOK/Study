#include <iostream>
#include "Point.h"
#include "Car.h"

Car::Car(double capacity, double consumption, const Point& location, const std::string& model) {
    this->fuelAmount = capacity;
    this->fuelCapacity = capacity;
    this->fuelConsumption = consumption;
    this->location = location;
    this->model = model;
}

Car::~Car() {}

double Car::getFuelAmount() const {
    return this->fuelAmount;
}

double Car::getFuelCapacity() const {
    return this->fuelCapacity;
}

double Car::getFuelConsumption() const {
    return this->fuelConsumption;
}

const Point& Car::getLocation() const {
    return this->location;
}

const std::string& Car::getModel() const {
    return this->model;
}

void Car::drive(const Point& destination) {
    
    Point locationCar = getLocation();
    double distance = this->location.distance(destination);
    double fuelNeeded = distance * this->fuelConsumption;
    
    if (fuelNeeded > this->fuelAmount) {
        throw OutOfFuel();
    }
    this->location = destination;
    this->fuelAmount -= fuelNeeded;
}

void Car::drive(double x, double y) {
    Point locationAfterDrive(x, y);
    double distance = this->location.distance(locationAfterDrive);
    double fuelNeeded = distance * this->fuelConsumption;
    
    if (fuelNeeded > this->fuelAmount) {
        throw OutOfFuel();
    }
    this->location = locationAfterDrive;
    this->fuelAmount -= fuelNeeded;
}

void Car::refill(double fuel) {
        if ((fuel + this->fuelAmount) > this->fuelCapacity) {
            throw ToMuchFuel();
    }
    this->fuelAmount += fuel;
}

std::ostream& operator<<(std::ostream& out, const Car& car) {
    out << "Model: " << car.getModel() << "\n"
        << "Location: " << car.getLocation() << "\n"
        << "Fuel consumption: " << car.getFuelConsumption() << "\n"
        << "Fuel amount: " << car.getFuelAmount() << "\n"
        << "Fuel capacity: " << car.getFuelCapacity() << "\n";
    return out;
}
