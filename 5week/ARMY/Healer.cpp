#include "Healer.h"

Healer::Healer(int unitType, std::string name, int hitPoints, int damage, int mana):
    SpellCaster::SpellCaster(unitType, name, hitPoints, damage, mana) {}

Healer::~Healer() {}

void Healer::attack(Unit* enemy, bool isAttack) {
    this->healerAttack = new Attack(this, enemy, isAttack);
    delete healerAttack;
}

void Healer::cast(Unit* enemy) {
    this->healerCast = new Spell(this, enemy);
    delete healerCast;
}

void Healer::heal(Unit* unit) {
    this->healerHeal = new Helper(this, unit);
    delete healerHeal;
}

std::ostream& operator<<(std::ostream& out, const Healer& unit) {
    out << unit.getName() << " HP: " << unit.getHitPoints() << "|" << unit.getHitPointsLimit() << " DMG: " << unit.getDamage()
    << " MANA: " << unit.getMana() << "|" << unit.getManaLimit();
    return out;
}