#ifndef MOHICAN_H
#define MOHICAN_H

class Mohican {
private:
    static Mohican* lastMagican;
    static int counter;
    std::string name;
public:
    Mohican();
    Mohican(Mohican& mohican);
    static int getCounter();
    std::string getName();
    void setName(std::string name);
    static std::string getLastMohican();
};

#endif