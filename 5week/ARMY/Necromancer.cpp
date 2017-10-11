#include "Necromancer.h"

Necromancer::Necromancer(int unitType, std::string name, int hitPoints, int damage, int mana):
    SpellCaster::SpellCaster(unitType, name, hitPoints, damage, mana) {}

Necromancer::~Necromancer() {}

void Necromancer::attack(Unit* enemy, bool isAttack) {
    this->wizardAttack = new Attack(this, enemy, isAttack);
    if ( isAttack == true )
        this->addObservable(*enemy);
    delete wizardAttack;
}

void Necromancer::cast(Unit* enemy) {
    this->wizardCast = new Spell(this, enemy);
    this->addObservable(*enemy);
    delete wizardCast;
}

void Necromancer::heal(Unit* unit) {
    this->wizardHeal = new Helper(this, unit);
    delete wizardHeal;
}

std::ostream& operator<<(std::ostream& out, const Necromancer& unit) {
    out << unit.getName() << " HP: " << unit.getHitPoints() << "|" << unit.getHitPointsLimit() << " DMG: " << unit.getDamage()
    << " MANA: " << unit.getMana() << "|" << unit.getManaLimit();
    return out;
}