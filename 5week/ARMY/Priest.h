#ifndef PRIEST_H
#define PRIEST_H

#include "SpellCaster.h"
#include "Spell.h"
#include "Attack.h"
#include "Helper.h"

class Priest : public SpellCaster {
protected:
    Attack* priestAttack;
    Spell* priestCast;
    Helper* priestHeal;
public:
    Priest(int unitType = 10, std::string name = "Priest", int hitPoints = 100, int damage = 10, int mana = 100);
    virtual ~Priest();

    virtual void attack(Unit* enemy, bool isAttack = true);
    virtual void cast(Unit* enemy);
    virtual void heal(Unit* unit);
};

std::ostream& operator<<(std::ostream& out, const Priest& unit);

#endif // PRIEST_H