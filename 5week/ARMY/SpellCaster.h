#ifndef SPELL_CASTER_H
#define SPELL_CASTER_H

#include "Unit.h"

class SpellCaster : public Unit {
protected:
public:
    SpellCaster(int unitType = 7, std::string name = "SpellCaster", int hitPoints = 100, int damage = 10, int mana = 100);
    virtual ~SpellCaster();

    virtual void attack(Unit* enemy, bool isAttack = true) = 0;
    virtual void cast(Unit* enemy) = 0;
    virtual void heal(Unit* unit) = 0;
    int getMana() const;
    int getManaLimit() const;
    void setMana(int mana);
    void setManaLimit(int manaLimit);
    void addMana(int mana);
    void subtractMana(int mana);
};

std::ostream& operator<<(std::ostream& out, const SpellCaster& unit);

#endif // SPELL_CASTER_H