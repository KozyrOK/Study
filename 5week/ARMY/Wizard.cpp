#include "Wizard.h"

Wizard::Wizard(int unitType, std::string name, int hitPoints, int damage, int mana):
    SpellCaster::SpellCaster(unitType, name, hitPoints, damage, mana) {}

Wizard::~Wizard() {}

void Wizard::attack(Unit* enemy, bool isAttack) {
    this->wizardAttack = new Attack(this, enemy, isAttack);
    delete wizardAttack;
}

void Wizard::cast(Unit* enemy) {
    this->wizardCast = new Spell(this, enemy);
    delete wizardCast;
}

void Wizard::heal(Unit* unit) {
    this->wizardHeal = new Helper(this, unit);
    delete wizardHeal;
}

std::ostream& operator<<(std::ostream& out, const Wizard& unit) {
    out << unit.getName() << " HP: " << unit.getHitPoints() << "|" << unit.getHitPointsLimit() << " DMG: " << unit.getDamage()
    << " MANA: " << unit.getMana() << "|" << unit.getManaLimit();
    return out;
}