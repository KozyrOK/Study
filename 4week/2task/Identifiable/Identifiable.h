#ifndef IDENTIFIABLE_H
#define IDENTIFIABLE_H

class Identifiable {
private:
    static int counter;
    int identNumber;

public:
    Identifiable();
    Identifiable(const Identifiable& identifiable);
    static int getCounter();
    int getIdentNumber() const;
};

#endif