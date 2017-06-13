#include <iostream>
#include "Passport.h"

Passport::Passport(std::string name, std::string secondName, int day, int month, int year) {
    this->name = name;
    this->secondName = secondName;
    Passport::validate(day, month, year);
    this->dayBirth = day;
    this->monthBirth = month;
    this->yearBirth = year;
    if (lastSeries[0] == 'A' && lastSeries[1] == 'A' && lastNumber == 0 && isFirstPassport == false) {
        this->number = lastNumber;
        this->series[0] = lastSeries[0];
        this->series[1] = lastSeries[1];
        isFirstPassport = true;
    } else if ( lastNumber < 999999 ) {
        lastNumber += 1;
        this->number = lastNumber;
        this->series[0] = lastSeries[0];
        this->series[1] = lastSeries[1];
    } else if ( lastSeries[0] == 'Z' && lastSeries[1] == 'Z' && lastNumber == 999999 ) {
        throw PassportNumberIsOverException(); 
    } else if (lastSeries[0] == 'Z' && lastNumber == 999999) { 
        lastSeries[1] += 1;
        lastNumber = 0;
        this->number = lastNumber;
        this->series[0] = lastSeries[0];
        this->series[1] = lastSeries[1];
    } else if (lastSeries[1] == 'Z' && lastNumber == 999999) {
        lastSeries[0] += 1;
        lastSeries[1] = 'A';
        lastNumber = 0;
        this->number = lastNumber;
        this->series[0] = lastSeries[0];
        this->series[1] = lastSeries[1];
    }
}

void Passport::validate(int day, int month, int year) {
    if (day < 1 || day > 31) { 
        throw InvalidDateOfBirthday();
    }
    
    bool month31 = true;
    if (month == 2 || month== 4 || month== 6 || 
        month== 9 || month== 11) {
        month31 = false;
    }
    
    if (month31 == false && day == 31) {
        throw InvalidDateOfBirthday();
    }
    
        bool leapYear = false;
    
    if (year % 400 == 0) {
        leapYear = true;
    } else if (year % 100 == 0) {
        leapYear = false;
    } else if (year % 4 == 0) {
        leapYear = true;
    }
    
    if (leapYear == false && month == 2 && day > 28) {
        throw InvalidDateOfBirthday();
    } else if (leapYear == true && month == 2 && day > 29) {
        throw InvalidDateOfBirthday();
    }
    
    if (month < 1 || month > 12) { 
        throw InvalidDateOfBirthday();
    }
    
    if (year < 1 || year > 9999) { 
        throw InvalidDateOfBirthday();
    }
}

void Passport::setSeries(char ser1, char ser2) {
    if (ser1 < 65 || ser1 > 90 ) {
        throw IncorrectSeries();
    } else if (ser2 < 65 || ser2 > 90 ) {
        throw IncorrectSeries();
    } else {
        lastSeries[0] = ser1;
        lastSeries[1] = ser2;
        lastNumber = 0;
    }
}

void Passport::setNumberAndSerias(char ser1, char ser2, int num) {
    if (ser1 < 65 || ser1 > 90 ) {
        throw IncorrectSeries();
    } else if (ser2 < 65 || ser2 > 90 ) {
        throw IncorrectSeries();
    } else {
        lastSeries[0] = ser1;
        lastSeries[1] = ser2;
    }
    if (num < 0 || num > 999999 ) {
        throw IncorrectPassportNumber();
    } else {    
    lastNumber = num;
    }
}

std::string Passport::getName() const {
    return this->name;
}

std::string Passport::getSecondName() const {
    return this->secondName;
}

int Passport::getNumber() const {
    return this->number;
}

char Passport::getSeries0() const {
    return this->series[0];
}

char Passport::getSeries1() const {
    return this->series[1];
}

int Passport::getDayBirth() const {
    return this->dayBirth;
}

int Passport::getMonthBirth() const {
    return this->monthBirth;
}

int Passport::getYearBirth() const {
    return this->yearBirth;
}

void Passport::printLastNumberAndSerias() {
    if (lastNumber > 99999) {
        std::cout << "Last number and serias: " << lastNumber << lastSeries[0] << lastSeries[1] << std::endl;
    } else if (lastNumber < 10) {
        std::cout << "Last number and serias: " << "00000" << lastNumber << lastSeries[0] << lastSeries[1] << std::endl;
    } else if (lastNumber < 100) {
        std::cout << "Last number and serias: " << "0000" << lastNumber << lastSeries[0] << lastSeries[1] << std::endl;
    } else if (lastNumber < 1000) {
        std::cout << "Last number and serias: " << "000" << lastNumber << lastSeries[0] << lastSeries[1] << std::endl;
    } else if (lastNumber < 10000) {
        std::cout << "Last number and serias: " << "00" << lastNumber << lastSeries[0] << lastSeries[1] << std::endl;
    }else {
        std::cout << "Last number and serias: " << "0" << lastNumber << lastSeries[0] << lastSeries[1] << std::endl;
    }
}

std::ostream& operator<<(std::ostream& out, const Passport& passport) {
    if (passport.getNumber() > 99999) {
        out << "Name: " << passport.getName() << "." << "\n"
        << "Second name : " << passport.getSecondName() << "." << "\n"
        << "Date of birth: " << passport.getDayBirth() << "/" << passport.getMonthBirth() << "/" << passport.getYearBirth() << "." << "\n"
        << "Number and serias of passport: " << passport.getNumber() << passport.getSeries0() << passport.getSeries1()<< ".";
    } else if (passport.getNumber() < 10) {
        out << "Name: " << passport.getName() << "." << "\n"
        << "Second name : " << passport.getSecondName() << "." << "\n"
        << "Date of birth: " << passport.getDayBirth() << "/" << passport.getMonthBirth() << "/" << passport.getYearBirth() << "." << "\n"
        << "Number and serias of passport: " << "00000" << passport.getNumber() << passport.getSeries0() << passport.getSeries1()<< ".";
    } else if (passport.getNumber() < 100) {
        out << "Name: " << passport.getName() << "." << "\n"
        << "Second name : " << passport.getSecondName() << "." << "\n"
        << "Date of birth: " << passport.getDayBirth() << "/" << passport.getMonthBirth() << "/" << passport.getYearBirth() << "." << "\n"
        << "Number and serias of passport: " << "0000" << passport.getNumber() << passport.getSeries0() << passport.getSeries1()<< ".";
    } else if (passport.getNumber() < 1000) {
        out << "Name: " << passport.getName() << "." << "\n"
        << "Second name : " << passport.getSecondName() << "." << "\n"
        << "Date of birth: " << passport.getDayBirth() << "/" << passport.getMonthBirth() << "/" << passport.getYearBirth() << "." << "\n"
        << "Number and serias of passport: " << "000" << passport.getNumber() << passport.getSeries0() << passport.getSeries1()<< ".";
    } else if (passport.getNumber() < 10000) {
        out << "Name: " << passport.getName() << "." << "\n"
        << "Second name : " << passport.getSecondName() << "." << "\n"
        << "Date of birth: " << passport.getDayBirth() << "/" << passport.getMonthBirth() << "/" << passport.getYearBirth() << "." << "\n"
        << "Number and serias of passport: " << "00" << passport.getNumber() << passport.getSeries0() << passport.getSeries1()<< ".";
    }else {
        out << "Name: " << passport.getName() << "." << "\n"
        << "Second name : " << passport.getSecondName() << "." << "\n"
        << "Date of birth: " << passport.getDayBirth() << "/" << passport.getMonthBirth() << "/" << passport.getYearBirth() << "." << "\n"
        << "Number and serias of passport: " << "0" << passport.getNumber() << passport.getSeries0() << passport.getSeries1()<< ".";
    }
    return out;
}

int Passport::lastNumber = 0;
char Passport::lastSeries[2] = { 'A', 'A' };
bool Passport::isFirstPassport = false;
