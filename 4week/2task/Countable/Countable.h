#ifndef COUNTABLE_H
#define COUNTABLE_H

class Countable {
private:
    static int count;
public:
    Countable();
    static int getCount();
};

#endif
