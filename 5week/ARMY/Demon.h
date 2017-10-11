#ifndef DEMON_H
#define DEMON_H

class Warlock;

#include "Unit.h"
#include "Attack.h"
#include "Warlock.h"

class Demon : public Unit {
protected:
    Attack* demonAttack;
    Warlock* master;
public:
    Demon(Warlock* master, int unitType = 12, std::string name = "Demon", int hitPoints = 100, int damage = 10);
    virtual ~Demon();

    virtual void attack(Unit* enemy, bool isAttack = true);
    virtual void subtractHitPoints(int hitPoints);
};

std::ostream& operator<<(std::ostream& out, const Demon& unit);

#endif // DEMON_H