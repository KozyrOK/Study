#ifndef UNIT_H
#define UNIT_H

class State;
class Attack;
class Observer;
class Observable;

#include <iostream>
#include "State.h"
#include "UnitIsDeadException.h"
#include "Observer.h"
#include "Observable.h"

class Unit {
    protected:
        std::string name;
        State* state;
        State* altState;
        Observer* observers;
        Observable* observables;
    public:
        Unit(int unitType = 0, std::string name = "Unit", int hitPoints = 100, int damage = 10);
        virtual ~Unit();

        void ensureIsAlive() const;
        int getUnitType() const;
        std::string getName() const;
        int getHitPoints() const;
        int getHitPointsLimit() const;
        int getDamage() const;
        void setUnitType(int unitType);
        void setName(std::string name);
        void setHitPoints(int hitPoints);
        void setHitPointsLimit(int hitPointsLimit);
        void setDamage(int damage);
        virtual void addHitPoints(int hitPoints);
        virtual void subtractHitPoints(int hitPoints);
        bool getIsAlive() const;
        virtual void attack(Unit* enemy, bool isAttack = true) = 0;
        void addObserver(Unit& unit);
        void removeObserver(Unit& unit);
        void addObservable(Unit& unit);
        void removeObservable(Unit& unit);
        void switchState();
        void createAltState(int unitType, std::string name, int hitPoints, int damage);
};

std::ostream& operator<<(std::ostream& out, const Unit& unit);

#endif // UNIT_H