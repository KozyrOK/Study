#include "Priest.h"

Priest::Priest(int unitType, std::string name, int hitPoints, int damage, int mana):
    SpellCaster::SpellCaster(unitType, name, hitPoints, damage, mana) {}
    
Priest::~Priest() {}

void Priest::attack(Unit* enemy, bool isAttack) {
    this->priestAttack = new Attack(this, enemy, isAttack);
    delete priestAttack;
}

void Priest::cast(Unit* enemy) {
    this->priestCast = new Spell(this, enemy);
    delete priestCast;
}

void Priest::heal(Unit* unit) {
    this->priestHeal = new Helper(this, unit);
    delete priestHeal;
}

std::ostream& operator<<(std::ostream& out, const Priest& unit) {
    out << unit.getName() << " HP: " << unit.getHitPoints() << "|" << unit.getHitPointsLimit() << " DMG: " << unit.getDamage()
    << " MANA: " << unit.getMana() << "|" << unit.getManaLimit();
    return out;
}
