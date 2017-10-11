#ifndef NECROMANCER_H
#define NECROMANCER_H

#include "SpellCaster.h"
#include "Spell.h"
#include "Attack.h"
#include "Helper.h"

class Necromancer : public SpellCaster {
protected:
    Attack* wizardAttack;
    Spell* wizardCast;
    Helper* wizardHeal;
public:
    Necromancer(int unitType = 13, std::string name = "Necromancer", int hitPoints = 100, int damage = 10, int mana = 100);
    virtual ~Necromancer();

    virtual void attack(Unit* enemy, bool isAttack = true);
    virtual void cast(Unit* enemy);
    virtual void heal(Unit* unit);
};

std::ostream& operator<<(std::ostream& out, const Necromancer& unit);

#endif // NECROMANCER_H