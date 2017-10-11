#ifndef BERSERKER_H
#define BERSERKER_H

#include "Unit.h"
#include "Attack.h"

class Berserker : public Unit {
protected:
    Attack* berserkerAttack;
public:
    Berserker(int unitType = 3, std::string name = "Berserker", int hitPoints = 100, int damage = 10);
    virtual ~Berserker();
    virtual void attack(Unit* enemy, bool isAttack = true);
};

std::ostream& operator<<(std::ostream& out, const Berserker& unit);

#endif // BERSERKER_H