#ifndef WARLOCK_H
#define WARLOCK_H

class Demon;

#include "SpellCaster.h"
#include "Spell.h"
#include "Attack.h"
#include "Helper.h"
#include "Demon.h"

class Warlock : public SpellCaster {
protected:
    Attack* warlockAttack;
    Spell* warlockCast;
    Helper* warlockHeal;
    Demon* demon;
public:
    Warlock(int unitType = 11, std::string name = "Warlock", int hitPoints = 100, int damage = 10, int mana = 100);
    virtual ~Warlock();

    virtual void attack(Unit* enemy, bool isAttack = true);
    virtual void cast(Unit* enemy);
    virtual void heal(Unit* unit);
    Demon* callDemon();
    void killDemon();
    virtual void subtractHitPoints(int hitPoints);
};

std::ostream& operator<<(std::ostream& out, const Warlock& unit);

#endif // WARLOCK_H