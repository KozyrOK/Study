#ifndef WIZARD_H
#define WIZARD_H

#include "SpellCaster.h"
#include "Spell.h"
#include "Attack.h"
#include "Helper.h"

class Wizard : public SpellCaster {
protected:
    Attack* wizardAttack;
    Spell* wizardCast;
    Helper* wizardHeal;
public:
    Wizard(int unitType = 8, std::string name = "Wizard", int hitPoints = 100, int damage = 10, int mana = 100);
    virtual ~Wizard();

    virtual void attack(Unit* enemy, bool isAttack = true);
    virtual void cast(Unit* enemy);
    virtual void heal(Unit* unit);
};

std::ostream& operator<<(std::ostream& out, const Wizard& unit);

#endif // WIZARD_H