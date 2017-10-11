#ifndef HEALER_H
#define HEALER_H

#include "SpellCaster.h"
#include "Spell.h"
#include "Attack.h"
#include "Helper.h"

class Healer : public SpellCaster {
protected:
    Attack* healerAttack;
    Spell* healerCast;
    Helper* healerHeal;
public:
    Healer(int unitType = 9, std::string name = "Healer", int hitPoints = 100, int damage = 10, int mana = 100);
    virtual ~Healer();

    virtual void attack(Unit* enemy, bool isAttack = true);
    virtual void cast(Unit* enemy);
    virtual void heal(Unit* unit);
};

std::ostream& operator<<(std::ostream& out, const Healer& unit);

#endif // HEALER_H