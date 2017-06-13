#include <iostream>
#include "Date.h"

void Date::validate(int day, int month, int year) {

    if (day < 1 || day > 31) { 
        throw InvalidDate("Invalid date");
    }
    
    bool month31 = true;
    if (month == 2 || month== 4 || month== 6 || 
        month== 9 || month== 11) {
        month31 = false;
    }
    
    if (month31 == false && day == 31) {
        throw InvalidDate("Invalid date");
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
        throw InvalidDate("Invalid date");
    } else if (leapYear == true && month == 2 && day > 29) {
        throw InvalidDate("Invalid date");
    }
    
    if (month < 1 || month > 12) { 
        throw InvalidDate("Invalid date");
    }
    
    if (year < 1 || year > 9999) { 
        throw InvalidDate("Invalid date");
    }
}

Date::Date(int day, int month, int year) {
    Date::validate(day, month, year);
    this->day = day;
    this->month = month;
    this->year = year;
}

Date::~Date() {}

int Date::getDay() const {
    return this->day;
}

int Date::getMonth() const{
    return this->month;
}

int Date::getYear() const{
    return this->year;
}

std::ostream& operator<<(std::ostream& out, const Date& date) {
    if (date.getMonth() < 10 ) {
        out << date.getDay() << "." << "0" << date.getMonth() << "." << date.getYear();
    } else {
        out << date.getDay() << "." << date.getMonth() << "." << date.getYear();
    }
    return out;
}
