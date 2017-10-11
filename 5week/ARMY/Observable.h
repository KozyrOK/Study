#ifndef OBSERVABLE_H
#define OBSERVABLE_H

class Unit;

#include <iostream>
#include <cstdio>
#include <set>
#include "Unit.h"

class Observable {
    protected:
        Unit* observer;
        std::set<Unit*>* lst;
    public:
        Observable(Unit* observer);
        ~Observable();

        void addObservable(Unit& unit);
        void removeObservable(Unit& unit);
        void observerIsDead();
};

#endif // OBSERVABLE_H