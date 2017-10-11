#ifndef OBSERVER_H
#define OBSERVER_H

class Unit;

#include <iostream>
#include <cstdio>
#include <set>
#include "Unit.h"

class Observer {
    protected:
        Unit* observable;
        std::set<Unit*>* lst;

    public:
        Observer(Unit* observable);
        ~Observer();

        void addObserver(Unit& unit);
        void removeObserver(Unit& unit);
        void observableIsDead();
};

#endif // OBSERVER_H