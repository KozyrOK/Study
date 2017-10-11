#include "Berserker.h"

Berserker::Berserker(int unitType, std::string name, int hitPoints, int damage):
    Unit::Unit(unitType, name, hitPoints, damage) {}

Berserker::~Berserker() {}

void Berserker::attack(Unit* enemy, bool isAttack) {
    this->berserkerAttack = new Attack(this, enemy, isAttack);
    delete berserkerAttack;
}

std::ostream& operator<<(std::ostream& out, const Berserker& unit) {
    out << unit.getName() << " HP: " << unit.getHitPoints() << "|" << unit.getHitPointsLimit() << " DMG: " << unit.getDamage();
    return out;
}