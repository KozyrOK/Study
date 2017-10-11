#include "Soldier.h"

Soldier::Soldier(int unitType, std::string name, int hitPoints, int damage):
    Unit::Unit(unitType, name, hitPoints, damage) {}
    
Soldier::~Soldier() {}

void Soldier::attack(Unit* enemy, bool isAttack) {
    this->soldierAttack = new Attack(this, enemy, isAttack);
    delete soldierAttack;
}

std::ostream& operator<<(std::ostream& out, const Soldier& unit) {
    out << unit.getName() << " HP: " << unit.getHitPoints() << "|" << unit.getHitPointsLimit() << " DMG: " << unit.getDamage();
    return out;
}