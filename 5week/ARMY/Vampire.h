#ifndef VAMPIRE_H
#define VAMPIRE_H

#include "Unit.h"
#include "VampireAttack.h"
#include "SpellCaster.h"

class Vampire : public Unit {
protected:
    VampireAttack* vampireAttack;
public:
    Vampire(int unitType = 4, std::string name = "Vampire", int hitPoints = 100, int damage = 10);
    virtual ~Vampire();

    virtual void attack(Unit* enemy, bool isAttack = true);
    void makeVampire(SpellCaster* unit, std::string newName = "Vampire");
    void makeVampire(Unit* unit, std::string newName = "Vampire");
};

std::ostream& operator<<(std::ostream& out, const Vampire& unit);

#endif // VAMPIRE_H