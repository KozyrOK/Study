#ifndef STATE_H
#define STATE_H

#include <iostream>
#include "StateSetParameterException.h"

class State {
    protected:
        int unitType;
        std::string name;
        int hitPoints;
        int hitPointsLimit;
        int damage;
        int mana;
        int manaLimit;
    public:
        State(int unitType, std::string name, int hitPoints, int damage, int mana = 0);
        virtual ~State();

        int getUnitType() const;
        std::string getName() const;
        int getHitPoints() const;
        int getHitPointsLimit() const;
        int getDamage() const;
        int getMana() const;
        int getManaLimit() const;
        void setUnitType(int unitType);
        void setName(std::string name);
        void setHitPoints(int hitPoints);
        void setHitPointsLimit(int hitPointsLimit);
        void setDamage(int damage);
        void setMana(int mana);
        void setManaLimit(int manaLimit);
        void addHitPoints(int hitPoints);
        void subtractHitPoints(int hitPoints);
        void addMana(int mana);
        void subtractMana(int mana);
};

#endif // STATE_H