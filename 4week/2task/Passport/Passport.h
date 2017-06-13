#ifndef PASSPORT_H
#define PASSPORT_H

class PassportNumberIsOverException {};
class InvalidDateOfBirthday {};
class IncorrectSeries {};
class IncorrectPassportNumber {};

class Passport {
    private:
        int number;
        char series[2];
        static int lastNumber;
        static char lastSeries[2];
        std::string name;
        std::string secondName;
        int dayBirth;
        int monthBirth;
        int yearBirth;
        void validate(int day, int month, int year);
        static bool isFirstPassport;
    public:
        Passport(std::string, std::string, int, int, int);
        static void setSeries(char ser1, char char2);
        static void setNumberAndSerias(char ser1, char ser2, int num);
        static void printLastNumberAndSerias(); 
        std::string getName() const;
        std::string getSecondName() const;
        int getNumber() const;
        char getSeries0() const;
        char getSeries1() const;
        int getDayBirth() const;
        int getMonthBirth() const;
        int getYearBirth() const;
};

std::ostream& operator<<(std::ostream& out, const Passport& passport);

#endif
