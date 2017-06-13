#ifndef MAGICAN_H
#define MAGICAN_H

class Magican {
private:
    static Magican* lastMagican;
    static int counter;
    std::string name;
public:
    Magican();
    Magican(Magican& magican);
    static int getCounter();
    std::string getName();
    void setName(std::string name);
    static std::string getLastMagican();
};

#endif