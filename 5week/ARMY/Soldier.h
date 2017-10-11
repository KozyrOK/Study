#ifndef SOLDIER_H
#define SOLDIER_H

#include "Unit.h"
#include "Attack.h"

class Soldier : public Unit {
protected:
    Attack* soldierAttack;
public:
    Soldier(int unitType = 1, std::string name = "Soldier", int hitPoints = 100, int damage = 10);
    virtual ~Soldier();

    virtual void attack(Unit* enemy, bool isAttack = true);
};

std::ostream& operator<<(std::ostream& out, const Soldier& unit);

#endif // SOLDIER_H