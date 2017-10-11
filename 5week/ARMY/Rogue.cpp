#include "Rogue.h"

Rogue::Rogue(int unitType, std::string name, int hitPoints, int damage):
    Unit::Unit(unitType, name, hitPoints, damage) {}

Rogue::~Rogue() {}

void Rogue::attack(Unit* enemy, bool isAttack) {
    this->rogueAttack = new RogueAttack(this, enemy, isAttack);
    delete rogueAttack;
}

std::ostream& operator<<(std::ostream& out, const Rogue& unit) {
    out << unit.getName() << " HP: " << unit.getHitPoints() << "|" << unit.getHitPointsLimit() << " DMG: " << unit.getDamage();
    return out;
}